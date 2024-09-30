function [z,x] = met_sol_bas_fac(A,b,c)
  [m,n] = size(A);
  R=nchoosek(1:n,m);
  zopt = inf;
  for k = 1:nchoosek(n,m)
    B = A(:, R(k,:));
    if rank(B) == m
      xB = inv(B)*b;
      if min(xB) >=0
        x = zeros(n,1);
        x(R(k,:)) = xB;
        if c'*x < zopt
          zopt = c'*x;
          xopt= x;
        endif
      endif
    endif
  endfor
  z = zopt;
  x = xopt;

endfunction
