<!DOCTYPE HTML>
<html>
    <h1>thema 3</h1>
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $grade1 = $_POST['grade1'];
    $grade2 = $_POST['grade2'];
    $grade3 = $_POST['grade3'];
    $average = ($grade1 + $grade2 + $grade3) / 3;
    if ($average >= 10) {
        echo "Εpitixia, o meso oros einai: " . $average;
    } else {
        echo "Apotixia, o meso oros einai: " . $average;
    }
}
?>
<form method="post">
    vathmos 1: <input type="number" name="grade1" required><br>
    vathmos 2: <input type="number" name="grade2" required><br>
    vathmos 3: <input type="number" name="grade3" required><br>
    <input type="submit" value="ypoogise meso oro">
</form>
</html>