<?php
    require_once('Mohican.php');
    
    $hakan = new Mohican("Hakan");
    $wapi = new Mohican("Wapi");
    $kwahu = new Mohican("Kwahu");
    $nuna = new Mohican("Nuna");
    
    echo Mohican::getLast() . PHP_EOL;
    echo Mohican::getTotal() . PHP_EOL;
?>
