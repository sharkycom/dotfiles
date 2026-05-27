<?php
$products = [
    "name" => "Laptop",
    "category" => "Electronics",
    "price" => 1000,
    "stock" => 10,
    "brand" => "Lenovo"
];
$products["discount"] = 0.15;
$final_price = $products["price"] * (1 - $products["discount"]);
foreach ($products as $key => $value) {
    echo $key . ": " . $value . "\n";
}
echo "Final Price: " . $final_price;
if ($products["stock"] > 0) {
    echo "To proion exei apothema.";
} else {
    echo "out of stock.";
}
if ($products["price"] > 800) {
    echo "Premium Product\n";
} else {
    echo "Regular Product\n";
}
count($products);
?>