<?php
$pageTitle = "Tech Workshop";
if (isset($_GET['pageTitle'])) {
    $pageTitle = $_GET['pageTitle'];
}

function showParticipant($participant) {
    foreach ($participant as $label => $value) {
        echo $label . ": " . $value . "<br>";
    }
}

function showActivities($activities) {
    for ($i = 0; $i < count($activities); $i++) {
        echo $i + 1 . ". " . $activities[$i] . "<br>";
    }
}

function ticketMessage($ticketType) {
    if ($ticketType == "basic") {
        return "Πρόσβαση μόνο στις ομιλίες.";
    } elseif ($ticketType == "premium") {
        return "Πρόσβαση σε ομιλίες και φαγητό.";
    } elseif ($ticketType == "vip") {
        return "Πρόσβαση σε όλα και θέση μπροστά.";
    }
}

$errors = [];
$activities = ["PHP Intro", "HTML Basics", "CSS Design", "JS Workshop", "SQL Practice"];

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = htmlspecialchars(trim($_POST['name']));
    $email = htmlspecialchars(trim($_POST['email']));
    $age = htmlspecialchars(trim($_POST['age']));
    $city = htmlspecialchars(trim($_POST['city']));
    $ticketType = htmlspecialchars(trim($_POST['ticketType']));

    if (empty($name) || strlen($name) < 3) {
        $errors[] = "Λάθος όνομα.";
    }
    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $errors[] = "Λάθος email.";
    }
    if ($age <= 0) {
        $errors[] = "Λάθος ηλικία.";
    }
    if (empty($city)) {
        $errors[] = "Η πόλη λείπει.";
    }

    if (count($errors) == 0) {
        $participant = [
            "Όνομα" => $name,
            "Email" => $email,
            "Ηλικία" => $age,
            "Πόλη" => $city,
            "Εισιτήριο" => $ticketType
        ];
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title><?php echo $pageTitle; ?></title>
</head>
<body>

    <h1><?php echo $pageTitle; ?></h1>

    <form method="post">
        Όνομα: <input type="text" name="name"><br>
        Email: <input type="text" name="email"><br>
        Ηλικία: <input type="number" name="age"><br>
        Πόλη: <input type="text" name="city"><br>
        Εισιτήριο: 
        <select name="ticketType">
            <option value="basic">Basic</option>
            <option value="premium">Premium</option>
            <option value="vip">VIP</option>
        </select><br>
        <input type="submit" value="Εγγραφή">
    </form>

    <?php
    if (count($errors) > 0) {
        foreach ($errors as $err) {
            echo "<p style='color:red;'>$err</p>";
        }
    }

    if ($_SERVER["REQUEST_METHOD"] == "POST" && count($errors) == 0) {
        echo "<h3>Στοιχεία Εγγραφής:</h3>";
        showParticipant($participant);

        if ($age >= 18) {
            echo "Κατάσταση: Ενήλικος<br>";
        } else {
            echo "Κατάσταση: Ανήλικος<br>";
        }

        if ($city == "Αθήνα" || $city == "Θεσσαλονίκη") {
            echo "Ειδικό μήνυμα: Κερδίσατε έκπτωση μεταφορικών!<br>";
        }

        echo "Προνόμια: " . ticketMessage($ticketType) . "<br>";

        echo "<h3>Δραστηριότητες (" . count($activities) . "):</h3>";
        showActivities($activities);
    }
    ?>

</body>
</html>