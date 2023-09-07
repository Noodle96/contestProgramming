function ans = exercise09(a,n,e)
  x = a;
  while(abs(power(x,n) -a ) > e) # controlando la magnitid del error absouto
    x = x - ((power(x,n) -a)) / (n*power(x,n-1));
    disp(x);
  endwhile
  ans = x;
endfunction