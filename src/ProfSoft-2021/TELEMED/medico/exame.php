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

// echo "id da consulta: " . $idconsulta;

$result = $db -> query("SELECT * FROM exame");
$idexame =  $result -> num_rows+1;

// echo $idconsulta . '  ' . $idexame;
?>

<html>

<head>
    <title>Requerir Exame</title>
    <link rel="stylesheet" type="text/css" href="css/bootstrap.css" />
</head>

<body>
    <div class="container">
        <div class="row col-md-6 col-md-offset-3">
            <div class="panel panel-primary">
                <div class="panel-heading text-center">
                    <h1>Requerir Exame</h1>
                </div>
                <div class="panel-body">
                    <form action="enviaExame.php" method="post">
                        <div class="form-group">
                            <label for="firstName">Exame</label>
                            <input type="text" class="form-control" id="nome" name="nome" />
                        </div>
                        <div class="form-group">
                            <label for="lastName">Clinica</label>
                            <input type="text" class="form-control" id="clinica" name="clinica" />
                        </div>
                        <div class="form-group">
                            <label for="data">Data</label>
                            <input type="date" class="form-control" id="data" name="data" />
                        </div>
                        <div class="form-group">
                            <label for="email">Jejum</label>
                            <input type="text" class="form-control" id="jejum" name="jejum" />
                        </div>
                        <div class="form-group">
                            <label for="email">Id da consulta</label>
                            <input type="text" class="form-control" id="idconsulta" value="<?php echo $idconsulta;?>" name="idconsulta" readonly/>
                        </div>
                        <div class="form-group">
                            <label for="email">Id do exame</label>
                            <input type="text" class="form-control" id="idexame" value="<?php echo $idexame;?>" name="idexame" readonly/>
                        </div>
                            <input type="submit" class="btn btn-primary" />

                    </form>
                </div>
            </div>
        </div>
    </div>
    <div class="toast" role="alert" aria-live="assertive" aria-atomic="true">
    </div>
</body>

</html>