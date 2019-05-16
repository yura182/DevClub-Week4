<?php
    class Paper {
        private $maxSymbols;
        private $symbols;
        private $content;
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        public function __construct($maxSymbols=1000) {
            $this->maxSymbols = $this->validate($maxSymbols);
            $this->symbols = 0;
            $this->content = "";
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Atribute error: property $name not found");
        }
        
        public function addContent($message) {
            if ( !is_string($message) ) {
                throw new Exception("Invalid param");
            }
            
            $freeSpace = $this->maxSymbols - $this->symbols;
            
            if ( strlen($this->content) == $this->maxSymbols ) {
                throw new Exception("Out of space");
            }
            
            if ( $freeSpace < strlen($message) ) {
                $this->content .= substr($message, 0, $freeSpace);
                $this->symbols += $freeSpace;
            } else {
                $this->content .= $message;
                $this->symbols += strlen($message);
            }
        }
        
        public function show() {
            echo $this->content . PHP_EOL;
        }
    }
?>
