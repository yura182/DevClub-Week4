<?php
    require_once('Point.php');
    
    $x = new Point(2, 8);
    $y = new Point(2, 8);
    $z = new Point;
    
    compare($x, $y);
    compare($y, $z);
    echo $x->distance($x) . PHP_EOL;
?>
