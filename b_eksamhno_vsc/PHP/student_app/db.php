<?php
$servername = "localhost";
$username = "root";
$password = ""; // Ή ο κωδικός που έβαλες στο sudo mariadb-set-root-password
$dbname = "saek_php_app";

$conn = mysqli_connect($servername, $username, $password, $dbname);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
?>