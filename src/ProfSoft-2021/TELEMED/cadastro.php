<?php
// $servername = "localhost";
// $database = "telemeddb";
// $username = "root";
// $password = "";
$servername = "localhost";
$database = "telemeddb";
$username = "root";
$password = "";

// Create connection
$db_conn = mysqli_connect($servername, $username, $password, $database);
if ($db_conn->connect_error){
        echo "Desconectado: ERROR: ". $db_conn->connect_error;
}

// info do usuario
$nome = $_POST['nome'];
$user = $_POST['username'];
$senha = md5($_POST['password']);

echo $nome;
echo $user;

$datnas = $_POST['datnas'];
$convenio = $_POST['convenio'];
$email = $_POST['email'];

$esp = $_POST['esp'];
$preco = $_POST['preco'];
$diasaten = $_POST['diasaten'];
$hraten = $_POST['hraten'];

if($convenio == ""){
        echo "a";
	$query_insert = "INSERT INTO Medico(ID_Medico, Nome, Login, Senha, Preco_Particular, Dias_Atendimento, Horario_Atendimento, Email, Area_Medicina_ID_Area) 
					 VALUES ( '', '".$nome."', '".$user."', '".$senha."', '".$preco."', '".$diasaten."', '".$hraten."', '".$email."', '1')
	";
        $rs_insert = mysqli_query($db_conn, $query_insert);
        header('Location: index.html');


}
else{
// Insert information
        echo "jesus";
	$query_insert = "INSERT INTO Paciente(ID_Paciente, Nome, Data_Nascimento, Login, Senha, Convenio, Email) 
					 VALUES ('','".$nome."', '".$datnas."' , '".$user."', '".$senha."', '".$convenio."', '".$email."')
	";
       $rs_insert = mysqli_query($db_conn, $query_insert);
       header('Location: index.html');

}


mysqli_close($db_conn);

echo "teste";

$url="index.html";
ob_start();
header('Location: '.$url);
ob_end_flush();
die();
?>	