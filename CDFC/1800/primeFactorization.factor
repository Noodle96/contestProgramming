USING: io kernel math math.parser sequences locals unicode.case arrays ;
readln string>number
{ } 2 [| n divs d | n d mod 0 = [ n d /i divs d 1array append d t ] [ n divs d 1 + d n < ] if ] loop
drop
[ number>string ] map
"*" join
print
drop
