<?php
    $data = $_POST['data'];
    $hora = $_POST['hora'];
    $id_atual = $_POST['id'];

    // $servername     = '354042';
    // $user           = '354042'; 
    // $pass           = 'PR0JET0engsoft';
    // $db             = 'localhost';
    $servername = "localhost";
    $db = "telemeddb";
    $user = "root";
    $pass = "";
    echo $hora;
    $db = new mysqli($servername, $user, $pass, $db) or die("Falha de conexão.");   

    //consulta(id_consulta, horario, link, paciente_id, medico_id);
    $stmt = $db->prepare("insert into consulta(Data, Horario, Link, ID_Paciente, ID_Medico, Receitas, Exames) values(?, ?, ?, ?, ?, ?, ?)");
    $chave = "/abcd-abcd-abcd"; //a ser gerada com uma API
    $link= "https://meet.google.com" . $chave;
    $paciente_id = $id_atual; //um método pra pegar o id atual
    $medico_id = 8; //um método para pegar um médico disponível
    $receitas = null;
    $exames = null;
    $stmt->bind_param("sssiiss", $data, $hora, $link, $paciente_id, $medico_id, $receitas, $exames);
    $execval = $stmt->execute();
    echo $execval;
    echo "Registration successfully...";
    $stmt->close();
?>