<?php include "header.php"; ?>
<h2>Νέα Καταχώριση Σπουδαστή</h2>
<form action="save_student.php" method="post">
<label>Ονοματεπώνυμο:</label><br>
<input type="text" name="name"><br><br>
<label>Email:</label><br>
<input type="text" name="email"><br><br>
<label>Ηλικία:</label><br>
<input type="number" name="age"><br><br>
<label>Τμήμα:</label><br>
<input type="text" name="department"><br><br>
<input type="submit" value="Αποθήκευση">
</form>
<?php include "footer.php"; ?>