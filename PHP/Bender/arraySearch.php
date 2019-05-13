<?php
    function arraySearch($array, $needle) {
        return array_search($needle, $array);
    }
    
    $array = array(1, 2, 3, 4, 5);
    
    echo implode(" ", $array) . PHP_EOL;
    echo arraySearch($array, 4) . PHP_EOL;
?>
