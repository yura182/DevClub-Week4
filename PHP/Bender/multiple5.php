<?php
    define("DIVISOR", 5);
    
    $last = intval(fgets(STDIN));
    
    $last -= $last % DIVISOR;
    
    echo implode(' ', range(0, $last, DIVISOR)) . PHP_EOL;
?>
