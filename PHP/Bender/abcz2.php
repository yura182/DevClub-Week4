<?php
    $number = intval(fgets(STDIN));
    $isZulu = TRUE;
    
    if ( $number % 2 == 0 ) {
        echo "alpha" . PHP_EOL;
        $isZulu = FALSE;
    }
    if ( $number % 3 == 0 ) {
        echo "bravo" . PHP_EOL;
        $isZulu = FALSE;
    }
    if ( $number % 5 == 0 ) {
        echo "charlie" . PHP_EOL;
        $isZulu = FALSE;
    }
    if ( $isZulu ) {
        echo "zulu" . PHP_EOL;
    }
?>
