<?php
    function arrayReverse(&$array) {
        $array = array_reverse($array);
    }
    
    $array = array(1, 2, 3, 4, 5, 6);
    
    echo implode(" ", $array) . PHP_EOL;
    
    arrayReverse($array);
    
    echo implode(" ", $array) . PHP_EOL;
?>
