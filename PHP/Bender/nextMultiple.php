<?php
    $input = explode(" ", fgets(STDIN));
    $divident = intval($input[0]);
    $divisor = intval($input[1]);
    $multiple = $divident - $divident % $divisor;
    
    if ( $multiple < $divident ) {
        if ( $divisor < 0 ) {
            $divisor *= -1;
        }
        $multiple += $divisor;
    }
    
    echo $multiple . PHP_EOL;
?>
