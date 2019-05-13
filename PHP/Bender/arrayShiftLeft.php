<?php
    function arrayShiftLeft(&$array) {
        $temp = array_shift($array);
        
        array_push($array, $temp);
    }
    
    $array = array(1, 2, 3, 4, 5, 6);
    
    echo implode(" ", $array) . PHP_EOL;
    
    arrayShiftLeft($array);
    
    echo implode(" ", $array) . PHP_EOL;
?>
