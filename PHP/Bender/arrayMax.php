<?php
    function arrayMax($array) {
        return max($array);
    }
    
    $array = array(1, 2, 3, 4, 5);
    
    echo implode(" ", $array) . PHP_EOL;
    echo arrayMax($array) . PHP_EOL;
?>
