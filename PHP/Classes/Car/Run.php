<?php
    require_once('Car.php');
    
    $mercedes = new Car;
    $start = new Point(10,19);
    $bmw = new Car(70, 0.8, $start, "BMW");
    $end = new Point(10, 20);
    
    echo $mercedes . PHP_EOL;
    echo $bmw . PHP_EOL;
    
    $bmw->refill(70);
    $mercedes->refill(50);
    
    $bmw->drive($end);
    $mercedes->drive($start);
    
    echo $mercedes . PHP_EOL;
    echo $bmw . PHP_EOL;
    
    $bmw->location = $start;
    $bmw->model = "BMW 5";
    $bmw->fuelConsumption = 0.9;
    $bmw->fuelAmount = 60;
    $bmw->fuelCapacity = 100;
    
    echo $bmw . PHP_EOL;
?>
