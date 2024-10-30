function  [ans] = m_grande(A,b,c,typeProblem)
	if(typeProblem == 'max')
		for i = 1:length(c)
			c(i) = -c(i)
		endfor
	endif
	inf = 1e7;
	% verificar que b > 0
	b_size = length(b);
	%disp("before")
	%A
	%b
	[m,n] = size(A);
	for row=1:length(b)
		if( b(row) < 0)
			b(row) = -b(row);
			for col=1:n
				A(row,col) = -A(row,col);
			endfor
		endif
	endfor

	A = [A eye(m)];
	c = [c; inf*ones(m,1)];
	%disp("after")

	indB = (n+1:n+m);
	%A
	%b
	%c
	%indB
	[z,x,iteraciones] = simplex(A,b,c,indB)

	% Clasificando el problema grande
	%if(type == 'optima_finita')
	% Caso Optima finita
	if(length(z) != 0)
		allZeros = true;
		%for i=n+1:n+m
		%	if(x(i) != 0) allZeros = false;
		%	endif
		%endfor
		allZeros = min(x(n+1:n+m)) == 0;
		if(allZeros) ans = ('PLM Tiene solucion optima finita');
		else ans = ('PLM es infactible');
		endif
	else % valor optimo ilimitado
		%allZeros = true;
		%for i = 1:n
		%	if(x(i) != 0) allZeros = false;
		%	endif
		%endfor
		allZeros = min(x(n+1:n+m)) == 0;
		if(allZeros)
			if(typeProblem == 'max') ans = ("PLM tiene solucion optima ilmitada superiorente");
			else ans = ("PLM tiene solucion optima ilmitada inferiormente");
			endif
		else ans = ("PLM es infactible");
		endif
	endif
	if typeProblem == 'max' z = -z;
	endif

	%[rpta, index] = sumar(87,14);
	%rpta
	%index

endfunction
