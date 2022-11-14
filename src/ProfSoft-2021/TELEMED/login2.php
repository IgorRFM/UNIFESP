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

$user = $_POST['username'];
$senha = $_POST['password'];
//echo $senha;
//echo $user;

$query = "SELECT ID_Medico, Login, Senha FROM Medico WHERE Login = '".$user. "'";

$result = mysqli_query($db_conn, $query);

$query2 = "SELECT ID_Paciente, Login, Senha FROM Paciente WHERE Login = '".$user. "'";

$result2 = mysqli_query($db_conn, $query2);

$user2;
$senha2; 

while($row = $result->fetch_assoc()){
	if($user == $row['Login']){
		$user2 = $row['Login'];
		$senha2 = $row['Senha'];
		$id_atual= $row['ID_Medico'];
                // echo "<br>";
                // echo $id_atual;
		if((md5($senha) == $senha2) && ($user == $user2)){
			
			$db_conn->close();
			header('Location: medico.php?id='.$id_atual);
		}else{
			echo "<h3>Senha ou usuario incorreto!</h3>" ;
			echo "<h3><a href='/index.html'>Pagina Inicial</a></h3>";
		}
		$db_conn->close();
		break;
	}
	else{
		break;
	}
}
$result->free();
while($row = $result2->fetch_assoc()){
	if($user == $row['Login']){
		$user2 = $row['Login'];
		$senha2 = $row['Senha'];
		$id_atual= $row['ID_Paciente'];
                //echo "<br>";
                //echo $senha2;
		if((md5($senha) == $senha2) && ($user == $user2)){
			$db_conn->close();
			header('Location: paciente.php?id='.$id_atual);
		}else{
			echo "<h3>Senha ou usuario incorreto!</h3>" ;
			echo "<h3><a href='/index.html'>Pagina Inicial</a></h3>";
		}
		$db_conn->close();
		break;

	}
	else{
		break;
	}
}

$db_conn->close();

	
?>	