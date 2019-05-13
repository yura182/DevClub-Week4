<?php
    function factorial($n) {
        if ( $n <= 1 ) {
            if ( $n < 0 ) {
                return -1;
            }
            return 1;
        }
        return $n * factorial($n - 1);
    }
    
    $number = intval(fgets(STDIN));
    
    echo factorial($number) . PHP_EOL;
?>
