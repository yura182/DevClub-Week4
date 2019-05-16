<?php
    require_once('Pen.php');
    
    $pen = new Pen(10);
    $paper = new Paper(100);
    
    echo $pen->inkAmount . PHP_EOL;
    
    $pen->write($paper, "Hello, world!");
    
    $paper->show();
    
    echo $paper->symbols . PHP_EOL;
    echo $pen->inkAmount . PHP_EOL;
?>
