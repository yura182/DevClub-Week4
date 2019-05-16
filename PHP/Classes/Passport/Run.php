<?php
    require_once('Passport.php');
    
    $pas1 = new Passport("Yura", "Petrashenko", "11-04-1985");
    $pas2 = new Passport("Sasha", "Petrashenko", "29-08-1960");
    
    echo $pas1 . PHP_EOL;
    echo $pas2 . PHP_EOL;
    
    Passport::setSeries("XZ", 999997);
    
    $pas3 = new Passport("Katya", "Doroshenko", "10-12-1980");
    $pas4 = new Passport("Tina", "Van", "30-01-1994");
    
    echo $pas3 . PHP_EOL;
    echo $pas4 . PHP_EOL;
    
    Passport::setSeries("ZA", 999999);
    
    $pas5 = new Passport("Dan", "Tramp", "19-12-1970");
    $pas6 = new Passport("Zhan", "Tirnak");
    
    echo $pas5 . PHP_EOL;g
    echo $pas6 . PHP_EOL;
    ?>
