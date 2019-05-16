<?php
    $input = explode(" ", fgets(STDIN));
    $a = intval($input[0]);
    $b = intval($input[1]);
    $c = intval($input[2]);
    $max = $a;
    
    if ( $max < $b ) {
        $max = $b;
    }
    if ( $max < $c ) {
        $max = $c;
    }
    
    echo $max . PHP_EOL;
?>
