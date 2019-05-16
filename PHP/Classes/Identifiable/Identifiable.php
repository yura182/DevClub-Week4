<?php
    class Identifiable implements Countable {
        private $id;
        private static $newId = 1;
        private static $total = 0;
        
        public function __construct() {
            $this->id = self::$newId;
            self::$newId += 1;
            self::$total += 1;
        }
        
        public function __destruct() {
            self::$total -= 1;
        }
        
        public function __clone() {
            $this->id = self::$newId;
            self::$total += 1;
            self::$newId += 1;
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                if ( $name == "id" ) {
                    return $this->$name;
                } else {
                    return self::$$name;
                }
            }
            throw new Exception("Atribute error: atribute $name not found");
        }
        
        public function count() {
            return self::$total;
        }
    }
?>
