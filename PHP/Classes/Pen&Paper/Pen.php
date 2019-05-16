<?php
    require_once('Paper.php');
    
    class Pen {
        private $inkAmount;
        private $inkCapacity;
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        public function __construct($inkCapacity=1000) {
            $this->inkCapacity = $this->validate($inkCapacity);
            $this->inkAmount = $this->inkCapacity;
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Atribute error: property $name not found");
        }
        
        public function write(Paper $paper, $message) {
            if ( !is_string($message) ) {
                throw new Exception("Invalid param");
            }
            
            if ( $this->inkAmount == 0 ) {
                throw new Exception("Out of ink");
            }
            
            if ( $paper->maxSymbols == $paper->symbols ) {
                throw new Exception("Out of space");
            }
            
            if ( $paper->maxSymbols - $paper->symbols < $this->inkAmount ) {
                $messageSize = $paper->maxSymbols - $paper->symbols;
            } else {
                $messageSize = $this->inkAmount;
            }
            
            if ( $messageSize < strlen($message) ) {
                $paper->addContent(substr($message, 0, $messageSize));
                $this->inkAmount -= $messageSize;
            } else {
                $paper->addContent($message);
                $this->inkAmount -= strlen($message);
            }
        }
        
        public function refill() {
            $this->inkAmount = $this->inkCapacity;
        }
    }
?>
