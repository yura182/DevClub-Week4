<?php
    $last = intval(fgets(STDIN));
    
    if ( $last % 2 == 0 ) {
        $last -= 1;
    }
    
    echo implode(' ', range(1, $last, 2)) . PHP_EOL;
?>
