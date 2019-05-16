<?php
    class Mohican implements Countable {
        private $name;
        private $prev;
        private $next;
        private static $last = null;
        private static $total = 0;
        
        private function validate($value) {
            if ( is_string($value) ) {
                return $value;
            }
            throw new Exception("Invalid Param");
        }
        
        public function __construct($name) {
            $this->name = $this->validate($name);
            $this->prev = &self::$last;
            $this->next = null;
            if ( isset(self::$last) ) {
                self::$last->next = &$this;
            }
            self::$last = &$this;
            self::$total += 1;
        }
        
        public function __destruct() {
            if ( isset($this->next) ) {
                $this->next->prev = &$this->prev;
            } else {
                self::$last = &$this->prev;
            }
            
            if ( isset($this->prev) ) {
                $this->prev->next = &$this->next;
            }
            
            self::$total -= 1;
            echo $this->name . " destroyed" . PHP_EOL; 
            echo "Last: " . self::$last . PHP_EOL;
        }
        
        public static function getLast() {
            return self::$last;
        }
        
        public static function getTotal() {
            return self::$total;
        }
        
        public function count() {
            return self::$total;
        }
        
        public function __toString() {
            return $this->name . PHP_EOL;
        }
    }
?>
