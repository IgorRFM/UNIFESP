<?php
include 'connect.php';
echo "você está logado como paciente.";

$id_atual = $_GET['id'];
echo "id:".$id_atual;
?>

<html>

<head>
    <title>Área do paciente</title>
    <link rel="stylesheet" type="text/css" href="css/bootstrap.css" />
</head>

<body>
    <div class="container">
        <div class="row col-md-6 col-md-offset-3">
            <div class="panel panel-primary">
                <div class="panel-heading text-center">
                    <h1>Área do Paciente</h1>
                </div>
                <div class="panel-body">
                    <center>
                        <button onclick="location.href='paciente/agendar.php?id=<?php echo $id_atual;?>'" type="button" class="btn btn-primary">Agendar Consulta</button>
                        <button onclick="location.href='paciente/historico.php?id=<?php echo $id_atual;?>'" type="button" class="btn btn-primary">Histórico de Consultas</button>
                        <button onclick="location.href='paciente/editar.php?id=<?php echo $id_atual;?>'" type="button" class="btn btn-primary"> Editar perfil</button>
                    </center>
                </div>
            </div>
        </div>
    </div>
</body>

</html>