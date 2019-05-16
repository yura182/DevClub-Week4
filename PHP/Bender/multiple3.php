<?php
    define("DIVISOR", 3);
    
    $last = intval(fgets(STDIN));
    
    $last -= $last % DIVISOR;
    
    echo implode(' ', range(0, $last, DIVISOR)) . PHP_EOL;
?>
