<!DOCTYPE HTML>
<html>
    <h1>thema 4</h1>
    <form method="post">
        <input type="text" name="onoma" placeholder="enter your name"><br>
        <input type="email" name="email" placeholder="enter your email"><br>
        <input type="number" name="hlikia" placeholder="enter your age"><br>
        <input type="text" name="polh" placeholder="enter your city"><br>
        <input type="text" name="typos" placeholder="enter your user type"><br>
        <button type="submit">submit</button>
    </form>
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $onoma = $_POST['onoma'];
    $email = $_POST['email'];
    $hlikia = $_POST['hlikia'];
    $polh = $_POST['polh'];
    $typos = $_POST['typos'];
    trim ($onoma);
    trim ($email);
    trim ($hlikia);
    trim ($polh);
    trim ($typos);

}
$users = [];
foreach ($users as $user) {
    echo "<p>Onoma: " . $user['onoma'] . "</p>";
    echo "<p>Email: " . $user['email'] . "</p>";
    echo "<p>Hlikia: " . $user['hlikia'] . "</p>";
    echo "<p>Polh: " . $user['polh'] . "</p>";
    echo "<p>Typos: " . $user['typos'] . "</p>";
}
if ($hlikia < 18) {
    echo "<p>O xrhsths einai anilikos</p>";
} else {
    echo "<p>O xrhsths einai enilikos</p>";
}
$user = [
    'onoma' => $onoma,
    'email' => $email,
    'hlikia' => $hlikia,
    'polh' => $polh,
    'typos' => $typos,
];
foreach ($user as $key => $value) {
    echo "<p>" .$key . ": " . $value . "</p>";
}
    if ($user['typos'] == 'student') {
        echo "<p>10% ekptosi</p>";
    } elseif ($user['typos'] == 'regular') {
        echo "<p>kanoniki simetoxi</p>";
    } elseif ($user['typos'] == 'vip') {
        echo "<p>VIP Prosvasi</p>";
    } else {
        echo "<p>Agnostos typos xrhsth</p>";
}
    if ($user['hlikia'] < 18) {
    echo "<p>O xrhsths einai anilikos</p>";
    } else {
        echo "<p>O xrhsths einai enilikos</p>";
}
?>
</html>

