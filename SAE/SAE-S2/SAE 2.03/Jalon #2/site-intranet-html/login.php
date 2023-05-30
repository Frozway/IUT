<?php
session_start();
if($_SERVER["REQUEST_METHOD"] == "POST") {
	$username = $_POST['username'];
	$password = $_POST['password'];
	if($username == 'intranet' && $password == 'T&k!t!zY') {
		$_SESSION['loggedin'] = true;
		header("Location: protected.php");
		exit;
	} else {
		$_SESSION['error'] = true;
		echo '<script>alert("Mot de passe ou nom d\'utilisateur incorrect.")</script>';
		header("Location:index.php?error=401");
		exit;
	}
}
?>