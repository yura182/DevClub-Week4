<?php
    function arrayCopy(&$destination, &$source) {
        $destination = $source;
    }
    
    $array1 = array(1, 2, 3, 4, 5);
    $array2 = array();
    
    echo implode(" ", $array1) . PHP_EOL;
    echo implode(" ", $array2) . PHP_EOL;
    
    arrayCopy($array2, $array1);
    
    echo implode(" ", $array2) . PHP_EOL;
?>
