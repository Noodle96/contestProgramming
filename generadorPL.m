function [A,b,c] = generadorPL(m,n)
  x = 100 * rand(n,1) + 1;
  A = 100 * rand(m,n) - 100 * rand(m,n);
  b = A*x;
  # falta restringir
  c = round(100*rand(n,1) - 100*rand(n,1));
endfunction
