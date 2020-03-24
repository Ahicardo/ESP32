<?php

function mysqli_conectar()
{	
	
	if(!$conexion = mysqli_connect("servidor", "usuario", "clave", "base de datos"))
	{
		exit ('Error de Conexion a MySQLi:(' . mysqli_connect_errno() . ') ' . mysqli_connect_error());
		return ("FALSE");
	}
	else
	{
		return $conexion;
	}
	

}

function mysqli_desconectar($conexion)
{
	if(!mysqli_close($conexion))
	{
		return ("FALSE");
	}
	else
	{
		return ("TRUE");
	}
}
?>
