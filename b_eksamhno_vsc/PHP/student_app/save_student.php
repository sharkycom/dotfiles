<?php
include "db.php";
include "header.php";
if ($_SERVER["REQUEST_METHOD"] == "POST") {
$name = trim($_POST["name"]);
$email = trim($_POST["email"]);
$age = trim($_POST["age"]);
$department = trim($_POST["department"]);
$errors = [];
if (empty($name)) {
$errors[] = "Το ονοματεπώνυμο είναι υποχρεωτικό.";
}
if (empty($email)) {
$errors[] = "Το email είναι υποχρεωτικό.";
}
if (empty($age)) {
$errors[] = "Η ηλικία είναι υποχρεωτική.";
}
if (empty($department)) {
$errors[] = "Το τμήμα είναι υποχρεωτικό.";
}
if (!empty($age) && $age <= 0) {

$errors[] = "Η ηλικία πρέπει να είναι μεγαλύτερη από 0.";
}
if (!empty($errors)) {
echo "<h2>Σφάλματα καταχώρισης</h2>";
foreach ($errors as $error) {
echo "<p>" . $error . "</p>";
}
echo '<p><a href="index.php">Επιστροφή στη φόρμα</a></p>';
} else {
$sql = "INSERT INTO students (name, email, age, department)
VALUES (?, ?, ?, ?)";
$stmt = mysqli_prepare($conn, $sql);
mysqli_stmt_bind_param($stmt, "ssis", $name, $email, $age, $department);
if (mysqli_stmt_execute($stmt)) {
echo "<h2>Η καταχώριση ολοκληρώθηκε επιτυχώς.</h2>";
echo '<p><a href="students.php">Προβολή σπουδαστών</a></p>';
} else {
echo "Σφάλμα κατά την αποθήκευση.";
}
mysqli_stmt_close($stmt);
}
} else {
echo "Δεν έγινε υποβολή φόρμας.";
}
include "footer.php";
?>