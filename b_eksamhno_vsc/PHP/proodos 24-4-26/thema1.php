<!DOCTYPE HTML>
<html>
    <h1>thema 1</h1>
<form method="post">
    <input type="text" name="name" placeholder="enter your name">
    <button type="submit">submit</button>
</form>
<?php
if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $name = trim($_POST["name"] ?? '');
    if ($name === '') {
        echo "<p>To onoma einai ypoxreotiko</p>";
    } else {
        echo "<p>geia sou $name!</p>";
    }
}
?>
</html>