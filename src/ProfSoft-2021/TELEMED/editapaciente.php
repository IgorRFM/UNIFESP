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

$query_search = "SELECT Nome, Data_Nascimento, Login, Convenio, Email FROM Paciente";
$result = $db_conn->query($query_search);

if ($result->num_rows > 0) {
  echo "<center><table><tr><th>Nome</th><th>Data_Nascimento</th><th>Login</th><th>Convenio</th><th>Email</th></tr>";
  // output data of each row
  while($row = $result->fetch_assoc()) {
    echo "<tr><td>".$row["Nome"]."</td><td>".$row["Data_Nascimento"]."</td><td>".$row["Login"]."</td><td>".$row["Convenio"]."</td><td>".$row["Email"]."</td></tr>";
  }
	echo "</table></center>";
  } else {
	echo "Nao ha registros!";
}


mysqli_close($db_conn);

?>	
<center>
<div class="registration-form" id="border">
        <br>
     <h4>Preencher nome e login e depois apenas o que for atualizar.</h4>
    <form  action="/atualizapaciente.php" id="form_cad" method="post">
	<label for="nome">Nome:</label>
	<input type="nome" id="nome" name="nome" required >
	
	<label for="user">Login Atual:</label>
	<input type="nome" id="user" name="user" required>
	
	<label for="datnas">Data de Nascimento:</label>
	<input type="date" id="datnas" name="datnas" ><br>
    
	<label for="convenio">Convenio:</label>
	<input type="name" id="convenio" name="convenio" >

	<label for="email">Email:</label>
	<input type="name" id="email" name="email" ><br><br>
	
	<input type="checkbox" id="excluir" name="excluir" value="excluir">
	<label for="excluir">Excluir Conta </label>
	
	<input type="submit" value="OK"></input>
        </form>
</div>	
</center>
			