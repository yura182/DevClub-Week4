<?php
    class Complex {
        private $re, $im;
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        public function __construct($re=0, $im=0) {
            $this->re = $this->validate($re);
            $this->im = $this->validate($im);
        }
        
        public function __get($name) {
            return $this->$name;
        }
        
        public function __set($name, $value) {
            $this->$name = $this->validate($value);
        }
        
        public function __toString() {
            if ( $this->im == 0 ) {
                return sprintf("%g", $this->re);
            }
            
            return sprintf("%g%+gi", $this->re, $this->im);
        }
    }
    
    function sum(Complex &$a, Complex &$b) {
        $sum = new Complex;
        
        $sum->re = $a->re + $b->re;
        $sum->im = $a->im + $b->im;
        
        return $sum;
    }
    
    function diff(Complex &$a, Complex &$b) {
        $diff = new Complex;
        
        $diff->re = $a->re - $b->re;
        $diff->im = $a->im - $b->im;
        
        return $diff;
    }
    
    function product(Complex &$a, Complex &$b) {
        $product = new Complex;
        
        $product->re = $a->re * $b->re - $a->im * $b->im;
        $product->im = $a->re * $b->im + $a->im * $b->re;
        
        return $product;
    }
?>
