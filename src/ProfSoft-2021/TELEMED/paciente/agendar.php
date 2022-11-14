<?php
include 'connect.php';
echo "você está logado como paciente.";

$id_atual = $_GET['id'];
?>

<html>
  <head>
    <title>Registration Page</title>
    <link rel="stylesheet" type="text/css" href="css/bootstrap.css" />
  </head>
  <body>
    <div class="container">
      <div class="row col-md-6 col-md-offset-3">
        <div class="panel panel-primary">
          <div class="panel-heading text-center">
            <h1>Registration Form</h1>
          </div>
          <div class="panel-body">
            <form action="enviar.php" method="post">
              <div class="form-group">
                <label for="data">Data</label>
                <input
                  type="date"
                  class="form-control"
                  id="data"
                  name="data"
                />
              </div>

              <div class="form-group">
                <label for="hora">Horário</label>
                <input
                  type="time"
                  class="form-control"
                  id="hora"
                  name="hora"
                />
              </div>

              <div class="form-group">
                <label for="id">ID</label>
                <input
                  type="input"
                  class="form-control"
                  id="id"
                  name="id"
                  value = "<?php echo $id_atual ?>"
                  readonly
                />
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