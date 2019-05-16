<?php
    class Point {
        private $x, $y;
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        public function __construct($x=0, $y=0) {
            $this->x = $this->validate($x);
            $this->y = $this->validate($y);
        }
        
        public function __get($name) {
            return $this->$name;
        }
        
        public function __set($name, $value) {
            $this->$name = $this->validate($value);
        }
        
        public function distance(Point $other) {
            return hypot($this->x - $other->x, $this->y - $other->y);
        }
        
        public function __toString() {
            return sprintf("(%g, %g)", $this->x, $this->y);
        }
    }
    
    function compare($x, $y) {
        if ( $x == $y ) {
            echo $x . " is equal to " . $y . PHP_EOL;
        } else {
            echo $x . " is not equal to " . $y . PHP_EOL;
        }
    }
    
    function isTheSameInstance($x, $y) {
        if ( $x === $y ) {
            echo $x . " and " . $y . " is references to the same instance" . PHP_EOL;
        } else {
            echo $x . " and " . $y . " is different instaces" . PHP_EOL;
        }
    }
    
    $a = new Point(2, 5);
    $b = new Point(3, 7);
    $c = new Point(3, 7);
    $d = $a;
    $e = clone $a;
    
    echo "a: " . $a . PHP_EOL;
    echo "b: " . $b . PHP_EOL;
    echo "c: " . $c . PHP_EOL;
    
    compare($a, $b);
    compare($b, $c);
    compare($a, $d);
    compare($a, $e);
    
    isTheSameInstance($a, $b);
    isTheSameInstance($a, $d);
    isTheSameInstance($a, $e);
    
    echo $a->distance($b) . PHP_EOL;
    echo $b->distance($c) . PHP_EOL;
?>
