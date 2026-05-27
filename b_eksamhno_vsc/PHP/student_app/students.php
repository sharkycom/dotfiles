<?php
include "db.php";
include "header.php";

$sql = "SELECT * FROM students ORDER BY id DESC";
$result = mysqli_query($conn, $sql);
echo "<h2>Λίστα Σπουδαστών</h2>";
if (mysqli_num_rows($result) > 0) {
echo "<table border='1' cellpadding='8'>";
echo "<tr>";
echo "<th>ID</th>";
echo "<th>Ονοματεπώνυμο</th>";
echo "<th>Email</th>";
echo "<th>Ηλικία</th>";
echo "<th>Τμήμα</th>";
echo "<th>Ημερομηνία</th>";
echo "</tr>";
while ($row = mysqli_fetch_assoc($result)) {
echo "<tr>";
echo "<td>" . $row["id"] . "</td>";
echo "<td>" . $row["name"] . "</td>";
echo "<td>" . $row["email"] . "</td>";
echo "<td>" . $row["age"] . "</td>";
echo "<td>" . $row["department"] . "</td>";
echo "<td>" . $row["created_at"] . "</td>";
echo "</tr>";
}
echo "</table>";
} else {
echo "<p>Δεν υπάρχουν καταχωρισμένοι σπουδαστές.</p>";
}
include "footer.php";
?>