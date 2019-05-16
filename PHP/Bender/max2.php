<?php
    $input = explode(" ", fgets(STDIN));
    $a = intval($input[0]);
    $b = intval($input[1]);
    
    if ( $a > $b ) {
        echo $a . PHP_EOL;
    } else {
        echo $b . PHP_EOL;
    }
?>
