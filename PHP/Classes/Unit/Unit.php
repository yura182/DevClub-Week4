<?php
    class Unit {
        private $damage;
        private $hitPoints;
        private $hitPointsLimit;
        private $name;
        private $damageStart;
        
        private function validateNumbers($value) {
            if ( is_numeric($value) ) {
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
        
        private function ensureIsAlive() {
            if ( $this->hitPoints == 0 ) {
                throw new Exception("Unit is dead");
            }
        }
        
        private function damage() {
            $this->damage = round(($this->hitPoints / $this->hitPointsLimit) * $this->damageStart);
        }
        
        public function __construct($name, $hp, $dmg) {
            $this->damage = $this->validateNumbers($dmg);
            $this->hitPointsLimit = $this->validateNumbers($hp);
            $this->hitPoints = $this->hitPointsLimit;
            $this->name = $this->validateString($name);
            $this->damageStart = $this->damage;
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
        }
        
        public function addHitPoints($hp) {
            $freeHitPoints = $this->hitPointsLimit - $this->hitPoints;
            
            $this->ensureIsAlive();
            
            if ( $this->validateNumbers($hp) > $freeHitPoints ) {
                $hp = $freeHitPoints;
            }
            
            $this->hitPoints += $hp;
        }
        
        public function takeDamage($dmg) {
            $this->ensureIsAlive();
            
            if ( $this->validateNumbers($dmg) > $this->hitPoints ) {
                $this->hitPoints = 0;
            } else {
                $this->hitPoints -= $dmg;
            }
            
            $this->damage();
        }
        
        public function attack(Unit $enemy) {
            $this->ensureIsAlive();
            
            $enemy->takeDamage($this->damage);
            
            echo $this->name . " attacks " . $enemy->name . PHP_EOL;
            
            if ( $enemy->hitPoints > 0 ) {
                $this->counterAttack($enemy);
            }
        }
        
        public function counterAttack(Unit $enemy) {
            $this->takeDamage($enemy->damage / 2);
            echo $enemy->name . " counter attacks " . $this->name . PHP_EOL;
        }
        
        public function __toString() {
            $out = "Name: " . $this->name . PHP_EOL;
            $out .= "Hit Points: " . $this->hitPoints . PHP_EOL;
            $out .= "Hit Points Limit: " . $this->hitPointsLimit . PHP_EOL;
            $out .= "Damage: " . $this->damage . PHP_EOL;
            return $out;
        }
    }
?>
