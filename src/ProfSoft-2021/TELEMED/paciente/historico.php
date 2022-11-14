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

$id_atual = $_GET['id'];

$result = mysqli_query($db, "SELECT * FROM consulta where ID_Paciente =".$id_atual);

?>

<html>

<head>
    <title>Área do paciente</title>
    <link rel="stylesheet" type="text/css" href="css/bootstrap.css" />
</head>
<table class="table">
    <thead>
        <tr>
            <th scope="col">id</th>
            <th scope="col">data</th>
            <th scope="col">hora</th>
            <th scope="col">link</th>
            <th scope="col">id do paciente</th>
            <th scope="col">id do médico</th>
        </tr>
    </thead>
    <tbody>
        <?php
        while ($row = $result->fetch_row()) {
            echo "<tr>";
            echo "<th scope='row'>" . $row[0] . "</th>";
            echo "<td>" . $row[1] . "</td>";
            echo "<td>" . $row[2] . "</td>";
            echo "<td>" . $row[3] . "</td>";
            echo "<td>" . $row[4] . "</td>";
            echo "<td>" . $row[5] . "</td>";
            echo "<td><a type='submit' name='id' value='".$row[0]."' class='btn btn-danger' href='removeConsulta.php?id=".$row[0]."'>Cancelar</button></td>";
            echo "</tr>";
        }
        ?>
        
    </tbody>
</table>

</html>