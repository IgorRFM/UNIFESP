<?php
    $nome = $_POST['nome'];
    $clinica = $_POST['clinica'];
    $data =  $_POST['data'];
    $jejum =  $_POST['jejum'];
    $idconsulta =  $_POST['idconsulta'];
    $idexame =  $_POST['idexame'];

    // $servername     = '354042';
    // $user           = '354042'; 
    // $pass           = 'PR0JET0engsoft';
    // $db             = 'localhost';
    $servername = "localhost";
    $db = "telemeddb";
    $user = "root";
    $pass = "";

    $db = new mysqli($servername, $user, $pass, $db) or die("Falha de conexão.");   

    //consulta(id_consulta, horario, link, paciente_id, medico_id);
    $stmt = $db->prepare("insert into exame(ID_Exame, Nome_Exame, Clinica, Data, Jejum) values(?, ?, ?, ?, ?)");
    $stmt->bind_param("isssi", $idexame, $nome, $clinica, $data, $jejum);
    $execval = $stmt->execute();
    echo $execval;
    echo "Registration successfully...";
    $stmt->close();

    $stmt = $db->prepare("insert into exame_consulta(ID_Exame, ID_Consulta) values(?, ?)");
    $stmt->bind_param("ii", $idexame, $idconsulta);
    $execval = $stmt->execute();
    echo $execval;
    echo "Registration successfully...";
    $stmt->close();
?>