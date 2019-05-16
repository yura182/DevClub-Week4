<?php
    class Gun {
        private $amount;
        private $capacity;
        private $isReady;
        private $model;
        private $totalShots;
        
        private function validateNumbers($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        private function validateBool($value) {
            if ( is_bool($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        private function validateString($value) {
            if ( is_string($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        public function __construct($model="Beretta", $capacity=8) {
            $this->amount = 0;
            $this->capacity = $this->validateNumbers($capacity);
            $this->isReady = false;
            $this->model = $this->validateString($model);
            $this->totalShots = 0;
        }
        
        public function __get($name) {
            if ( property_exists($name) ) {
                return $this->$name;
            }
            throw new Exception("Atribute error: property $name not found");
        }
        
        public function __set($name, $value) {
            if ( property_exists($this, $name) ) {
                if ( $name == "model" ) {
                    $this->$name = $this->validateString($value);
                } else if ( $name == "isReady" ) {
                    $this->$name = $this->validateBool($value);
                } else {
                    $this->$name = $this->validateNumbers($value);
                }
            } else {
                throw new Exception("Atribute error: property $name not found");
            }
        }
        
        public function prepare() {
            if ( !$this->isReady and $this->amount != 0 ) {
                $this->isReady = !$this->isReady;
            }
        }
        
        public function reload() {
            $this->amount = $this->capacity;
        }
        
        public function shoot() {
            if ( !$this->isReady ) {
                throw new Exception("Not ready");
            }
            
            if ( $this->amount == 0 ) {
                throw new Exception("Out of rounds");
            }
            
            echo "Bang!" . PHP_EOL;
            
            $this->amount -= 1;
            $this->isReady = false;
            $this->totalShots += 1;
        }
        
        public function __toString() {
            $out = "Model: " . $this->model;
            $out .= ", Amount: " . $this->amount;
            $out .= ", Capacity: " . $this->capacity;
            $out .= ", Total Shots: " . $this->totalShots;
            
            if ( $this->isReady ) {
                $out .= ", is ready" . PHP_EOL;
            } else {
                $out .= ", is not ready" . PHP_EOL;
            }
            return $out;
        }
    }
?>
