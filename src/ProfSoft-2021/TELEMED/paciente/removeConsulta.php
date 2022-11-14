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

$idconsulta = $_GET['id'];

$stmt= 'DELETE from exame_consulta WHERE ID_Consulta='.$idconsulta;
$result = $db->prepare($stmt);
$result->execute();
echo "removido com sucesso.";

$stmt= 'DELETE from consulta WHERE ID_Consulta='.$idconsulta;
$result = $db->prepare($stmt);
$result->execute();
echo "removido com sucesso.";

?>
