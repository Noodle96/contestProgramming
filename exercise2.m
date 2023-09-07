function result = exercise2()
  a = 1;
  s = 2;
  while(s > 1)
    disp("a: ");
    disp(a);
    a = a/2;
    disp("s: ");
    disp(s);
    s = 1+a;
  endwhile
  disp("FINAL: ");
  disp(2*a);
  disp("s: ");
  disp(s);
  result = 2*a;
endfunction