<!DOCTYPE HTML>
<html>
    <h1>thema 2</h1>
<?php
$numbers = [3, 7, 12, 5, 9];
echo "<p>Plithos pinaka:" . count($numbers) . "</p>";
foreach ($numbers as $number) {
    echo "$number<br>";
    if ($number > 10) {
        echo "<p>$number einai megalytero apo to 10</p>";
    }
}
?>
</html>