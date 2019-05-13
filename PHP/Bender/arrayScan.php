<?php
    function arrayScan($in, &$array, $limit) {
        $array = explode(" ", fgets($in), $limit+1);
        
        if ( count($array) > $limit ) {
            array_pop($array);
        }
        return count($array);
    }
    
    $in = fopen("task.in", "r");
    $out = fopen("task.out", "w");
    $limit = 3;
    $array = array();
    
    fwrite($out, arrayScan($in, $array, $limit) . PHP_EOL);
    fwrite($out, implode(" ", $array) . PHP_EOL);
    fclose($in);
    fclose($out);
?>
