<?php
$student = [
    "name" => "Vasilis",
    "surname" => "Mouzourakis",
    "age" => 18,
    "department" => "Texnikos Efarmogwn Pliroforikis",
    "city" => "Nikaia"
];
foreach ($student as $key => $value) {
    echo "$key: $value\n";
}
$student["grade"] = 8.5;
$student["age"] = 19;
count($student);
echo "<br>";
if ($student["age"] > 18) {
    echo "Enilikos";
}
else {
    echo "Anilikos";
}
?>