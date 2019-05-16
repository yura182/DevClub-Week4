<?php
    require_once('Vector.php');
    
    $a = new Vector(10, 12);
    $b = new Vector(-5, 10);
    $c = new Vector;
    
    echo "a: " . $a . PHP_EOL;
    echo "b: " . $b . PHP_EOL;
    echo "c: " . $c . PHP_EOL;
    echo "Length a: " . $a->len() . PHP_EOL;
    
    compare($a, $b);
    isTheSameInstance($a, $b);
    
    echo " Sum of vector " . $a . " and vector " . $b . " is " . vectorSum($a, $b) . PHP_EOL;
    echo " Diff of vector " . $a . " and vector " . $b . " is " . vectorDiff($a, $b) . PHP_EOL;
?>
