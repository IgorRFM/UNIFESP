<?php
// $servername = "localhost";
// $database = "354042";
// $username = "354042";
// $password = "PR0JET0engsoft";
$servername = "localhost";
$database = "telemeddb";
$username = "root";
$password = "";
// Create connection
$db_conn = mysqli_connect($servername, $username, $password, $database);
// Check connection
if ($db_conn->connect_error) {
  echo "n conectou";
  die("Connection failed: " . $db_conn->connect_error);
}
//  info do usuario
$user = $_POST['user'];
$nome = $_POST['nome'];
$preco = $_POST['preco'];
$diasaten = $_POST['diasaten'];
$hraten = $_POST['hraten'];
$email = $_POST['email'];
$excluir = $_POST['excluir'];
$password = md5($_POST['password']);
echo $password ;

if($preco != ""){
$query_update = "UPDATE Medico SET Preco_Particular = '".$preco."'  WHERE Login = '".$user. "'";
$rs_update = mysqli_query($db_conn, $query_update);
if(mysqli_query($db_conn, $query_update)) {
	header('Location: medico.html');
  //echo $query_update;
} else {
  echo "Error: " . $query_update. "<br>" . $db_conn ->error;
}
}
if($diasaten != ""){
$query_update = "UPDATE Medico SET Dias_Atendimento = '".$diasaten."'  WHERE Login = '".$user. "'";
$rs_update = mysqli_query($db_conn, $query_update);
if(mysqli_query($db_conn, $query_update)) {
   header('Location: medico.html');
  //echo $query_update;
} else {
  echo "Error: " . $query_update. "<br>" . $db_conn ->error;
}
}
if($hraten != ""){
$query_update = "UPDATE Medico SET Horario_Atendimento = '".$hraten."'  WHERE Login = '".$user. "'";
$rs_update = mysqli_query($db_conn, $query_update);
if(mysqli_query($db_conn, $query_update)) {
	header('Location: medico.html');
  //echo $query_update;
} else {
  echo "Error: " . $query_update. "<br>" . $db_conn ->error;
}
}
if($email != ""){
$query_update = "UPDATE Medico SET Email = '".$email."'  WHERE Login = '".$user. "'";
$rs_update = mysqli_query($db_conn, $query_update);
if(mysqli_query($db_conn, $query_update)) {
	header('Location: medico.html');
  //echo $query_update;
} else {
  echo "Error: " . $query_update. "<br>" . $db_conn ->error;
}
}
if($password != ""){
$query_update = "UPDATE Medico SET Senha = '".$password."'  WHERE Login = '".$user. "'";
$rs_update = mysqli_query($db_conn, $query_update);
if(mysqli_query($db_conn, $query_update)) {
	header('Location: medico.html');
  //echo $query_update;
} else {
  echo "Error: " . $query_update. "<br>" . $db_conn ->error;
}
}
if($excluir == "excluir"){
$query_remove = "DELETE FROM Medico WHERE Login = '".$user. "'";
//$rs_remove = mysqli_query($db_conn, $query_remove);
if (mysqli_query($db_conn, $query_remove)) {
  echo " Removido";
  //echo $query_remove;
} else {
  echo "Error: " . $query_remove. "<br>" . $db_conn ->error;
}
}

mysqli_close($db_conn);

?>