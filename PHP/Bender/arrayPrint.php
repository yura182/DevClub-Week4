<?php
    function arrayPrint($out, $array) {
        fwrite($out, implode(" ", $array) . PHP_EOL);
        fclose($out);
    }
    
    $in = fopen("task.in", "r");
    $out = fopen("task.out", "w");
    $array = explode(" ", fgets($in));
    fclose($in);
    
    arrayPrint($out, $array);
?>
