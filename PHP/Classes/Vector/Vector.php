<?php
    class Vector {
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
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Atribute error: atribute $name not found");
        }
        
        public function __set($name, $value) {
            if ( property_exists($this, $name) ) {
                $this->$name = $this->validate($value);
            } else {
                throw new Exception("Atribute error: atribute $name not found");
            }
        }
        
        public function len() {
            return hypot($this->x, $this->y);
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
            echo $x . " and " . $y . " is different instances" . PHP_EOL;
        }
    }
    
    function vectorSum(Vector &$a, Vector &$b) {
        $sum = new Vector;
        
        $sum->x = ($a->x) + ($b->x);
        $sum->y = $a->y + $b->y;
        
        return $sum;
    }
    
    function vectorDiff(Vector &$a, Vector &$b) {
        $diff = new Vector;
        
        $diff->x = $a->x - $b->x;
        $diff->y = $a->y - $b->y;
        
        return $diff;
    }
?>
