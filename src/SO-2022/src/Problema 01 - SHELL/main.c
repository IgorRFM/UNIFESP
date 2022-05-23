#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// Funções de busca de tokens
int conta_tk(int argc, char **argv, char *tk);                 // conta a quantidade de vezes que um token aparece
int encontra_tks(int argc, char **argv, char *tk1, char *tk2); // acha a posição de um dos dois tokens
int encontra_tk(int argc, char **argv, char *tk);              // acha a posição de um token

int comando_simples(char **cmd, int bg);        // executa comandos simples com vários parâmetros e/ou em background
int comando_pipes(int argc, char **argv, int qtde_pipes); // executa comando aninhado em pipes
int comando_cond(int argc, char **cmd, int pos);          // executa comando separado por condicionais "e" ou "ou"

int main(int argc, char **argv)
{
    int fd[2], ret, n;
    if (argc <= 1)
    {
        printf("Use o comando no formato: ./main <comando> <parametros>\n");
        printf("ou: ./main <comando> <parametros> <operador> <comando> <parâmetros> <operador> ...\n");
        return 0;
    }

    char **cmd = &argv[1]; // apontar para o primeiro comando

    int i = 0, pos_operador_condicional = -1, token_or = -1, token_and = -1;
    pos_operador_condicional = encontra_tks(argc, argv, "||", "&&");
    if (pos_operador_condicional > 0)
    {
        // executa comando condicional
        comando_cond(argc, cmd, pos_operador_condicional);
        // printf("Existe comando condicional %d (%s)\n", pos_operador_condicional, argv[pos_operador_condicional]);
    }
    else
    {
        int qtde_pipes = conta_tk(argc, argv, "|");
        if (qtde_pipes > 0)
        {
            int a=comando_pipes(argc,cmd,qtde_pipes);
            // printf("Existe %d comando em pipe %d\n", qtde_pipes, a);
        }
        else // só pode ser comando simples ou em background
        {
            int background = FALSE;
            background = encontra_tk(argc, argv, "&");
            // printf("Existe comando simples %d\n", background);
            int a = comando_simples(cmd, background);
        }
    }

    return 0;
}

int conta_tk(int argc, char **argv, char *tk)
{
    int i = 0, qtde = 0;
    char *token = NULL;
    for (i = 0; i < argc; i++) // conta a quantidade de pipe (|)
    {
        token = strtok(argv[i], tk);
        if (token == NULL)
        {
            qtde++;
        }
    }
    return qtde;
}

int encontra_tks(int argc, char **argv, char *tk1, char *tk2)
{
    int token_or = -1, token_and = -1, i = 0;
    for (i = 0; i < argc; i++) // procura operadores condicionais "e" (&&) ou "ou" (||)
    {
        token_or = strcmp(argv[i], tk1);
        token_and = strcmp(argv[i], tk2);
        if (token_or == 0 || token_and == 0)
        {
            return i;
        }
    }
    return -1;
}

int encontra_tk(int argc, char **argv, char *tk)
{
    int i = 0;
    char *token = NULL;
    for (i = 0; i < argc; i++)
    {
        token = strtok(argv[i], "&");
        if (token == NULL)
        {
            argv[i] = NULL;
            return TRUE;
        }
    }
    return FALSE;
}

int encontra_pipe(int argc, char **argv, char *tk)
{
    int i = 0;
    char *token = NULL;
    for (i = 0; i < argc; i++)
    {
        // printf("%d: %s ; ",i,argv[i]);
        token = strtok(argv[i], "|");
        if (token == NULL)
        {
            argv[i] = NULL;
            return i;
        }
    }
    printf("\n");
    return -1;
}

int comando_simples(char **cmd, int bg)
{
    pid_t pid; // instancia o indentificador do processo

    pid = fork();
    if (pid == 0) // processo filho
    {
        execvp(cmd[0], cmd);
        return 0;
    }
    else if (pid > 0) // processo pai
    {
        int status;
        if (!bg) // se FALSE, comando não tem bg, então pai aguarda filho
        {
            waitpid(pid, &status, 0);
        } // senão, pai há bg, então pai não espera filho
        return WEXITSTATUS(status);
    }
    else
    {
        return -1;
    }
}

int comando_pipes(int argc, char **argv, int qtde_pipes)
{
    int fd[2], i = 0, pos_pipe; // fd[2] representa a criação de dois canais de comunicação, 1 para escrita, 0 para leitura de dados
    int aux = STDIN_FILENO;

    for (int j = 0; j <= qtde_pipes; j++)
    {
        // formata o comando atual de acordo com a posicao do pipe retornada
        char **cmd = &argv[i]; // copia o comando referente a posição na matriz de argumento
        pos_pipe = encontra_pipe(argc, cmd, "|");

        // argv[pos_pipe]=NULL;
        // printf("i: %d, pos pipe: %d\n", i, pos_pipe);
        // printf("cmd: %s %s\n", cmd[0], cmd[1]);
        cmd[pos_pipe] = NULL; //adiciona NULL onde teria o pipe, igual é feito na função encontratk
        if (qtde_pipes != -1)
            cmd[pos_pipe - i] = NULL;
        
        
        if (pipe(fd) < 0)
        {
            return -1;
        }

        pid_t pid = fork(); 

        if (pid == 0)   //processo filho
        {                            
            close(fd[0]);            
            dup2(aux, STDIN_FILENO); 

            if (j < qtde_pipes)
                dup2(fd[1], STDOUT_FILENO); // duplica saida padrao do filho para escrita do pipe

            execvp(cmd[0], cmd); // fornece um vetor de ponteiros representando a lista de argumentos para o processo
            return 0;
        }
        else if (pid > 0)
        { // processo pai
            aux = fd[0];
            close(fd[1]); // pai nao vai escrever
            waitpid(pid, NULL, 0);
        }
        else
        {
            perror("fork");
            return -1;
        }

        i = i + pos_pipe +1;
    }

    return 1;
}

int comando_cond(int argc, char **cmd, int pos){
    char **cond_cmd;
    int current_condition=0;

    if (pos != -1)
    {
        // formata o comando atual e o prox comando corretamente
        cond_cmd = &cmd[pos];
        // printf("pos: %d - %s, %s\n", pos, cmd[pos], cond_cmd[0]);
        if(!strcmp(cmd[pos-1],"&&")){
            // printf("\ne\n");
            current_condition=1; //e
        }else{
            // printf("\nou\n");
            current_condition=2; //ou
        }
        cmd[pos-1] = NULL;
    }
    else
    {
        current_condition = 0;
    }

    // com o retorno do exec_command verifico se será executado o prox comando condicional
    // printf("cmd: %s\n", cmd[0]);
    int res = comando_simples(cmd, FALSE);
    // printf("cond: %d | res: %d \n",current_condition, res);
    

    if ((current_condition == 1 && res == 0) ||
        (current_condition == 2 && res != 0))
    {
        //rodou o comando e prossegue pro condicional '&&'
        //ou não rodou o comando e prossegue pro condicional '||'

        int pos2 = -1;
        pos2 = encontra_tks(argc-pos-1, cond_cmd, "&&", "||");
        // printf("pos 2: %d\n", pos2);
        
        return comando_cond(argc, cond_cmd, pos2);
    }

    return res;
}