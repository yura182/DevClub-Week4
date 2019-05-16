<?php
    $input = explode(" ", fgets(STDIN));
    $a = intval($input[0]);
    $b = intval($input[1]);
    $c = intval($input[2]);
    $d = intval($input[3]);
    $max = $a;
    
    if ( $max < $b ) {
        $max = $b;
    }
    if ( $max < $c ) {
        $max = $c;
    }
    if ( $max < $d ) {
        $max = $d;
    }
    
    echo $max . PHP_EOL;
?>
