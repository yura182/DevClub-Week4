<?php
    function arrayExchange(&$array) {
        $len = count($array);
        
        for ( $even = 0, $odd = 1; $odd < $len; $even += 2, $odd += 2 ) {
            $temp = $array[$even];
            
            $array[$even] = $array[$odd];
            $array[$odd] = $temp;
        }
    }
    
    $array = array(1, 2, 3, 4, 5, 6);
    
    echo implode(" ", $array) . PHP_EOL;
    
    arrayExchange($array);
    
    echo implode(" ", $array) . PHP_EOL;
?>
