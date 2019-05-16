<?php
    $input = explode(" ", fgets(STDIN));
    $a = intval($input[0]);
    $b = intval($input[1]);
    $c = intval($input[2]);
    
    if ( $a + $b > $c ) {
        echo "alpha" . PHP_EOL;
    } else if ( $a < $b - $c ) {
        echo "bravo" . PHP_EOL;
    } else if ( $b % $c == 0 ) {
        echo "charlie" . PHP_EOL;
    } else {
        echo "zulu" . PHP_EOL;
    }
?>
