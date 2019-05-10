<?php
    $size = intval(fgets(STDIN));
    
    for ( $row = 1; $row <= $size; $row++ ) {
        $first = $size * $size - $size * $row + 1;
        $last = $first + $size - 1;
        
        echo implode(" ", range($first, $last)) . PHP_EOL;
    }
?>
