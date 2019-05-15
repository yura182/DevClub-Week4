<?php
    class Passport {
        private $series;
        private $number;
        private $name;
        private $surname;
        private $dateOfBirth;
        
        private static $firstLetter = 65;
        private static $secondLetter = 65;
        private static $nextNumber = 1;
        
        private function validate($value) {
            if ( is_string($value) ) {
                return $value;
            }
            throw new Exception("Invalid Param");
        }
        
        public function __construct($name, $surname, $dateOfBirth='01-01-2000') {
            $this->name = $this->validate($name);
            $this->surname = $this->validate($surname);
            $this->dateOfBirth = new DateTime($dateOfBirth);
            $this->series = $this->newSeries();
            $this->number = $this->newNumber();
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
        }
        
        private function newSeries() {
            return chr(self::$firstLetter) . chr(self::$secondLetter);
        }
        
        private function newNumber() {
            $newNumber = sprintf("%06d", self::$nextNumber);
            self::$nextNumber += 1;
            
            if ( self::$nextNumber > 999999 ) {
                self::$nextNumber = 1;
                self::$secondLetter += 1;
                if ( self::$secondLetter > 90 ) {
                    self::$secondLetter = 65;
                    self::$firstLetter += 1;
                    if ( self::$firstLetter > 90 ) {
                        throw new Exception("Serial out of Range");
                    }
                }
            }
            return $newNumber;
        }
        
        public static function setSeries($series, $number=1) {
            if ( !is_string($series) or strlen($series) != 2 ) {
                throw new Exception("Invalid series");
            }
            if ( ord($series[0]) < self::$firstLetter ) {
                throw new Exception("Invalid series");
            } else if ( ord($series[0]) == self::$firstLetter ) {
                if ( ord($series[1] < self::$secondLetter ) ) {
                    throw new Exception("Invalid series");
                }
            }
            
            self::$firstLetter = ord($series[0]);
            self::$secondLetter = ord($series[1]);
            
            if ( is_numeric($number) ) {
                if ( $number > 999999 ) {
                    throw new Exception("Invalid number");
                }
            }
            
            self::$nextNumber = $number;
        }
        
        public function __toString() {
            $out = "Serial number: " . $this->series . $this->number . PHP_EOL;
            $out .= "Name: " . $this->name . PHP_EOL;
            $out .= "Surname: " . $this->surname . PHP_EOL;
            $out .= "Date of Birth: " . $this->dateOfBirth->format('d-m-Y') . PHP_EOL;
            return $out;
        }
    }
?>
