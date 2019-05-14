<?php
    require_once('Gun.php');
    
    $gun1 = new Gun;
    $gun2 = new Gun("Makarov", 12);
    
    echo $gun1 . PHP_EOL;
    echo $gun2 . PHP_EOL;
    
    $gun1->reload();
    $gun1->prepare();
    
    $gun1->shoot();
    $gun1->prepare();
    $gun1->shoot();
    
    echo $gun1 . PHP_EOL;
    
    $gun2->reload();
    $gun2->prepare();
    
    $gun2->shoot();
    $gun2->prepare();
    $gun2->shoot();
    $gun2->prepare();
    $gun2->shoot();
    $gun2->prepare();
    $gun2->shoot();
    $gun2->prepare();
    
    echo $gun2 . PHP_EOL;
    
    $gun2->amount = 10;
    $gun2->capacity = 10;
    $gun2->isReady = true;
    $gun2->model = "Glock";
    $gun2->totalShots = 20;
    
    echo $gun2 . PHP_EOL;
?>
