<?php
    require_once('Unit.php');
    
    $gop = new Unit("Gopnik", 100, 11);
    $box = new Unit("Boxer", 150, 20);
    
    echo $gop . PHP_EOL;
    echo $box . PHP_EOL;
    
    $gop->attack($box);
    
    echo PHP_EOL . $gop . PHP_EOL;
    echo $box . PHP_EOL;
    
    $box->attack($gop);
    $box->attack($gop);
    $box->attack($gop);
    
    $gop->addHitPoints(80);
    
    $box->attack($gop);
    $box->attack($gop);
    $box->attack($gop);
    $box->attack($gop);
    
    echo PHP_EOL . $gop . PHP_EOL;
    echo $box . PHP_EOL;
?>
