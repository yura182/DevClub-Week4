<?php
    function arrayMin($array) {
        return min($array);
    }
    
    $array = array(1, 2, 3, 4, 5);
    
    echo implode(" ", $array) . PHP_EOL;
    echo arrayMin($array) . PHP_EOL;
?>
