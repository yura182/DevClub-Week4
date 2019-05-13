<?php
    function arrayShiftRight(&$array) {
        $temp = array_pop($array);
        
        array_unshift($array, $temp);
    }
    
    $array = array(1, 2, 3, 4, 5, 6);
    
    echo implode(" ", $array) . PHP_EOL;
    
    arrayShiftRight($array);
    
    echo implode(" ", $array) . PHP_EOL;
?>
