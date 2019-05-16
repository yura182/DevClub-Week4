<?php
    function arrayZeroFill(&$array) {
        $array = array_fill(0, count($array), 0);
    }
    
    $array = array(1, 2, 3, 4, 5);
    
    echo implode(" ", $array) . PHP_EOL;
    
    arrayZeroFill($array);
    
    echo implode(" ", $array) . PHP_EOL;
?>
