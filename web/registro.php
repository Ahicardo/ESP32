

<?php
include("lib_MySQLi.php");

if(isset($_POST['uWeb']) && isset($_POST['pWeb']) && isset($_POST['id']) && isset($_POST['spo2']) && isset($_POST['pulsacion'])) 
{

	$usuario = $_POST['uWeb']; 
	$password = $_POST['pWeb'];
    $id = $_POST['id'];  
    $spo2 = $_POST['spo2'];
    $pulsacion = $_POST['pulsacion'];

	echo "-> ".$usuario." - ".$password." - ".$id." - ".$spo2." - ".$pulsacion."\n";



	if ($usuario == "usuario" || $contrasena == "12345")
	{
		echo "-> Login_Sistem_OK \n";

		if($conexion = mysqli_conectar())
		{
			echo "-> Login_mySQL_OK \n";

			// INSERTAR LOS DATOS EN LA TABLA CORRESPONDIENTE.

		}
		else
		{
			echo "-> Login_mySQL_FAIL \n";
		}

	}

}


if(mysqli_desconectar($conexion))
	echo "-> Logout_DB OK \n";

   
?>


