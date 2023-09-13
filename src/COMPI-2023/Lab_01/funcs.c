// #include<stdio.h>

buffer_texto *buf;

void allocate_buffer(int tamanho){
	buf = (buffer_texto*) malloc(sizeof(buffer_texto));

	buf->buf = (char *)malloc(tamanho * sizeof(char));
	buf->tam = tamanho;
}

void replace_print(FILE *arqv_ptr){
	int i = 0, j=0;
	char c;
	while (( c = fgetc(arqv_ptr)) != EOF)
    {
    	if(i==buf->tam-1){
    		j=0;
    		while(j < buf->tam-1){
    			printf("%c", buf->buf[j]);
    			buf->buf[j] = "";
    			j++;
    		}
    		i=0;
    	}

    	buf->buf[i] = c;
    	if(buf->buf[i] >= 65 && buf->buf[i] <= 90){
    		buf->buf[i] = buf->buf[i]+32;
    	}else if(buf->buf[i] >= 97 && buf->buf[i] <= 122){
    		buf->buf[i] = buf->buf[i]-32;
    	}

        i++;
    }

    if(i!=0){
    	j=0;
		while(j < buf->tam-1){
			printf("%c", buf->buf[j]);
			j++;
		}
    }
    
    printf("\n");
}

void deallocate_buffer(){
	free(buf->buf);
	free(buf);
}

