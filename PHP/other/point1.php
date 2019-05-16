<?php
    class Point {
        private $x;
        private $y;
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        public function Point($x=0, $y=0) {
            $this->x = $this->validate($x);
            $this->y = $this->validate($y);
        }
        
        public function getX() {
            return $this->x;
        }
        
        public function getY() {
            return $this->y;
        }
        
        public function setX($x) {
            $this->x = $this->validate($x);
        }
        
        public function setY($y) {
            $this->y = $this->validate($y);
        }
        
        public function distance(Point $other) {
            return hypot($this->x - $other->x, $this->y - $other->y);
        }
        
        public function __toString() {
            return sprintf("(%s, %s)", $this->x, $this->y);
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
            echo $x . " and " . $y . " is different instances" . PHP_EOL;
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
    
    compare ($a, $b);
    compare ($b, $c);
    
    isTheSameInstance($a, $b);
    isTheSameInstance($a, $d);
    
    echo $a->distance($b) . PHP_EOL;
    echo $b->distance($c) . PHP_EOL;
?>
