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

?>