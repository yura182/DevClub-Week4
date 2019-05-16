<?php
    class Counter implements Countable {
        private static $total = 0;
        
        public function __construct() {
            self::$total += 1;
        }
        
        public function __destruct() {
            self::$total -= 1;
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return self::$total;
            }
            throw new Exception("Atribute error: atribute $name not found");
        }
        
        public function count() {
            return self::$total;
        }
    }
?>
