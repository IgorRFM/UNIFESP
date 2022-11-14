<?php
// $servername     = '354042';
// $user           = '354042'; 
// $pass           = 'PR0JET0engsoft';
// $db             = 'localhost';
$servername = "localhost";
$db = "telemeddb";
$user = "root";
$pass = "";

$db = new mysqli($servername, $user, $pass, $db) or die("Falha de conexão.");

echo "Conectado.";

$result = $db -> query("SELECT * FROM area_medicina");
echo $result -> num_rows.' ';

//inserindo um area de medicina 0
if($result->num_rows == 0){
    $send = $db->prepare("insert into area_medicina(ID_Area, Nome_Area) values(?, ?)");
    $id = 1;
    $nome_area = 'gastroenterologista';
    $send->bind_param("is", $id, $nome_area);
    $execval = $send->execute();
    echo $execval;
    echo "Registration successfully...";
    $send->close();
}


$result = $db -> query("SELECT * FROM paciente");
echo $result -> num_rows.' ';

//inserindo um paciente 0
if($result->num_rows == 0){
    $send = $db->prepare("insert into paciente(Nome, Data_Nascimento, Login, Senha, Convenio, Email) values(?, ?, ?, ?, ?, ?)");
    $nome = 'João';
    $datanasc = '2001-07-22';
    $login = 'joaojao';
    $senha = '123456';
    $convenio = 'sim';
    $email = "joão@gmail.com";
    $send->bind_param("ssdsss", $nome, $datanasc, $login, $senha, $convenio, $email);
    $execval = $send->execute();
    echo $execval;
    echo "Registro bem sucedido...";
    $send->close();
}


$result = $db -> query("SELECT * FROM medico");
echo $result -> num_rows.' ';

//inserindo um medico 0
if($result->num_rows == 0){
    $send = $db->prepare("insert into medico(Nome, Login, Senha, Preco_Particular, Dias_Atendimento, Horario_Atendimento, Email, Area_Medicina_ID_Area ) values(?, ?, ?, ?, ?, ?, ?, ?)");
    $nome = 'Dr Frederico';
    $login = 'fred123';
    $senha = '12345678';
    $preco = 15.7;
    $diasAtend = null;
    $horaAtend = null;
    $areaMedId = 1;
    $email = "fred@gmail.com";
    $send->bind_param("sssisssi", $nome, $login, $senha, $preco, $diasAtend, $horaAtend, $email, $areaMedId);
    $execval = $send->execute();
    echo $execval;
    echo "Registration successfully...";
    $send->close();
}
?>