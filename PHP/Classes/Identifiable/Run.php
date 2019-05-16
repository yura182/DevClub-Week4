<?php
    require_once('Identifiable.php');
    
    $a = new Identifiable;
    $b = new Identifiable;
    $c = new Identifiable;
    $d = new Identifiable;
    
    echo $d->id . PHP_EOL;
    echo $d->total . PHP_EOL;
    echo count($d) . PHP_EOL;
    
    $a = null;
    $b = null;
    
    $e = new Identifiable;
    
    echo $e->id . PHP_EOL;
    echo count($e) . PHP_EOL;
    
    $f = clone($e);
    $g = new Identifiable;
    
    echo $f->id . PHP_EOL;
    echo $g->id . PHP_EOL;
?>
