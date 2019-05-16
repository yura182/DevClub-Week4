<?php
    $last = intval(fgets(STDIN));
    
    echo implode(' ', range(0, $last)) . PHP_EOL;
?>
