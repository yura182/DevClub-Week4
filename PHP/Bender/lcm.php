<?php
    function gcd($a, $b) {
        if ( $b == 0 ) {
            return $a;
        }
        return gcd($b, $a%$b);
    }
    
    function lcm($a, $b) {
        return $a / gcd($a, $b) * $b;
    }
    
    $in = fopen("task.in", "r");
    $out = fopen("task.out", "w");
    $input = explode(" ", fgets($in));
    $a = intval($input[0]);
    $b = intval($input[1]);
    
    fwrite($out, lcm($a, $b));
    
    fclose($in);
    fclose($out);
?>
