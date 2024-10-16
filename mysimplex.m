function [z, x,iteraciones, indB] = mysimplex(A,b,c, indB)
  iteraciones = 0;
  [m,n] = size(A);
  flag = true;
  while flag
    iteraciones=iteraciones+1;
    R = setdiff(1:n, indB);
    B = A(:, indB);
    N = A(:, R);
    cB = c(indB);
    cN = c(R);
    iB = inv(B);
    bb = iB *b; % valor objetivo
    if min(bb)<0
      error("indB no proveeb una SBF")
    endif

    zj_zi = cB'*iB*N-cN';
    [zk_ck,k_max] = max(zj_zi);
    k = R(k_max);
    yk = iB*A(:,k);

    % ver qu todas las componentes de zj_z_i sean <=0
    % Existe solucion optima
    if(zk_ck  <= 0)
      flag = false;
      z = cB' * bb;
      x = zeros(n,1);
      x(indB) = bb;
    elseif(max(yk) <= 0)
      %algun costo reducido >0 zk_ck
      %calcular y_k = invB *ak
      disp('Existe solucion optima ilimitada');
      flag = false; z = []; x = [];
    else
      % Test de la razon
      minimo = inf;
      %r = inf;
      for i = 1:m
        if (yk(i) > 0 && bb(i)/yk(i) < minimo)
          minimo = bb(i)/yk(i);
          r = i;
		  indB(r) = k;
        endif
      endfor
    endif

  endwhile
endfunction
