<?php
    function fibonacci($n) {
        if ( $n == 0 ) {
            return 0;
        } else if ( $n == 1 or $n == -1 ) {
            return 1;
        } else if ( $n < 0 ) {
            return fibonacci($n+2) - fibonacci($n+1);
        }
        return fibonacci($n-1) + fibonacci($n-2);
    }
    
    $number = intval(fgets(STDIN));
    
    echo fibonacci($number) . PHP_EOL;
?>
