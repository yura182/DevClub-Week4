<?php
    require_once('../Point/Point.php');
    
    class Car {
        private $fuelAmount;
        private $fuelCapacity;
        private $fuelConsumption;
        private $location;
        private $model;
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        public function __construct($capacity=60, $consumption=0.6, 
            Point $location=null, string $model="Mercedes") {
            $this->fuelAmount = 0;
            $this->fuelCapacity = $this->validate($capacity);
            $this->fuelConsumption = $this->validate($consumption);
            $this->model = $model;
            
            if ( $location == null ) {
                $this->location = new Point;
            } else {
                $this->location = $location;
            }
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Atribute error: property $name not found");
        }
        
        public function __set($name, $value) {
            if ( property_exists($this, $name) ) {
                if ( $name == "location" ) {
                    if ( $value instanceof Point ) {
                        $this->location = $value;
                    } else {
                        throw new Exception("Invalid param for location");
                    }
                } else if ( $name == "model" ) {
                    if ( is_string($value) ) {
                        $this->model = $value;
                    } else {
                        throw new Exception("Invalid param for model");
                    }
                } else {
                    $this->$name = $this->validate($value);
                }
            } else {
                throw new Exception("Atribute error: property $name not found");
            }
        }
        
        public function drive(Point &$destination) {
            $needFuel = $this->location->distance($destination) * $this->fuelConsumption;
            
            if ( $needFuel > $this->fuelAmount ) {
                throw new Exception("Out of fuel");
            }
            
            echo $this->model . " is moving...." . PHP_EOL;
            $this->fuelAmount -= $needFuel;
            $this->location = $destination;
        }
        
        public function refill($fuel) {
            if ( !is_numeric($fuel) ) {
                throw new Exception("Invalid param");
            }
            
            $newAmount = $fuel + $this->fuelAmount;
            
            if ( $newAmount > $this->fuelCapacity ) {
                throw new Exception("To much fuel");
            }
            
            $this->fuelAmount = $newAmount;
        }
        
        public function __toString() {
            $out =  "Model: " . $this->model . PHP_EOL;
            $out .= "Fuel Amount: " . $this->fuelAmount . PHP_EOL;
            $out .= "Fuel Capacity: " . $this->fuelCapacity . PHP_EOL;
            $out .= "Fuel consumption: " . $this->fuelConsumption . PHP_EOL;
            $out .= "Location: " . $this->location . PHP_EOL;
            
            return $out;
        }
    }
?>
