<?php
// $servername     = '354042';
// $user           = '354042'; 
// $pass           = 'PR0JET0engsoft';
// $db             = 'localhost';
$servername = "localhost";
$db = "telemeddb";
$user = "root";
$pass = "";

$id_atual=$_GET['id'];

$db = new mysqli($servername, $user, $pass, $db) or die("Falha de conexão.");

$result = mysqli_query($db, "SELECT * FROM consulta where ID_Medico =".$id_atual);

?>

<html>

<head>
    <title>Área do Médico</title>
    <link rel="stylesheet" type="text/css" href="css/bootstrap.css" />
</head>
<table class="table">
    <thead>
        <tr>
            <th scope="col">id</th>
            <th scope="col">data </th>
            <th scope="col">hora </th>
            <th scope="col">link</th>
            <th scope="col">id do paciente</th>
            <th scope="col">id do médico</th>
            <th scope="col">Ações</th>
        </tr>
    </thead>
    <tbody>
        <?php
        while ($row = $result->fetch_row()) {
            $_SESSION["consulta_id"] = $row[0];
            echo "<tr>";
            echo "<th scope='row'>" . $row[0] . "</th>";
            echo "<td>" . $row[1] . "</td>";
            echo "<td>" . $row[2] . "</td>";
            echo "<td>" . $row[3] . "</td>";
            echo "<td>" . $id_atual . "</td>";
            echo "<td>" . $row[4] . "</td>";
            echo "<td>";
            echo "<a type='submit' name='id' value='".$row[0]."' class='btn btn-primary' href='exame.php?id=".$row[0]."' >Pedir Exames</button>";
            echo "<a type='submit' name='id' value='".$row[0]."' class='btn btn-primary' href='receita.php?id=".$row[0]."'>Passar Receitas</button>";
            echo "<a type='submit' name='id' value='".$row[0]."' class='btn btn-danger' href='removeConsulta.php?id=".$row[0]."'>Cancelar</button></td>";
            echo "</tr>";
        }
        ?>
        
    </tbody>
</table>

</html>