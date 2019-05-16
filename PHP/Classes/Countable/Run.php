<?php
    require_once('Countable.php');
    
    $a = new Counter;
    $b = new Counter;
    $c = new Counter;
    $d = new Counter;
    
    $a = null;
    echo $b->total . PHP_EOL;
    echo count($b) . PHP_EOL;
?>
