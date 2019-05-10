<?php
    $size = intval(fgets(STDIN));
    
    for ( $row = 1, $first = 1; $row <= $size; $row++ ) {
        $last = $size * $row;
        echo implode(" ", range($first, $last)) . PHP_EOL;
        $first = $last + 1;
    }
?>
