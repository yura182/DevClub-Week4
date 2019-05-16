<?php
    require_once('Complex.php');
    
    $a = new Complex(10, 12);
    $b = new Complex(2, -3);
    $c = new Complex;
    
    echo "a: " . $a . PHP_EOL;
    echo "b: " . $b . PHP_EOL;
    echo "c: " . $c . PHP_EOL;
    
    if ( $a == $b ) {
        echo $a . " is equal to " . $b . PHP_EOL;
    } else {
        echo $a . " is not equal to " . $b . PHP_EOL;
    }
    
    echo "a + b = " . sum($a, $b) . PHP_EOL;
    echo "a - b = " . diff($a, $b) . PHP_EOL;
    echo "a * b = " . product($a, $b) . PHP_EOL;
?>
