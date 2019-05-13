<?php
    $input = explode(" ", fgets(STDIN));
    $a = intval($input[0]);
    $b = intval($input[1]);
    
    if ( $a <= $b ) {
        echo "alpha" . PHP_EOL;
    } else if ( $a < 0 ) {
        echo "bravo" . PHP_EOL;
    } else if ( $b == 0 ) {
        echo "charlie" . PHP_EOL;
    } else {
        echo "zulu" . PHP_EOL;
    }
?>
