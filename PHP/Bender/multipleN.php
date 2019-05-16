<?php
    $input = explode(" ", fgets(STDIN));
    $last = intval($input[0]);
    $divisor = intval($input[1]);
    
    if ( $divisor < 0 ) {
        $divisor *= -1;
    }
    
    $last -= $last % $divisor;
    
    echo implode(" ", range(0, $last, $divisor)) . PHP_EOL;
?>
