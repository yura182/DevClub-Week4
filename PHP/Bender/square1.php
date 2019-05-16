<?php
    $size = intval(fgets(STDIN));
    
    for ( $row = 1; $row <= $size; $row++ ) {
        echo implode(" ", range(1, $size)) . PHP_EOL;
    }
?>
