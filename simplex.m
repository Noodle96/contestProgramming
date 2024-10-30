function [z,x,iter,indB,type]=simplex(A,b,c,indB)
[m,n]=size(A); parar='no'; iter=0;
while parar=='no'
   iter=iter+1;
   R=setdiff(1:n,indB);
   B=A(:,indB); N=A(:,R); cB=c(indB); cN=c(R); iB=inv(B); bb=iB*b;
   if min(bb)<0
       error('indB no provee una SBF');
   end
   zj_cj=cB'*iB*N-cN';
   [zk_ck,ki]=max(zj_cj); k=R(ki); yk=iB*A(:,k);
   if zk_ck<=0
       parar='si'; z=cB'*bb; x=zeros(n,1); x(indB)=bb;
	   type = 'optima_finita';
   elseif max(yk)<=0
		%x = x;
		x = zeros(n,1); x(indB) = bb;
		type= 'optima_ilimitada';
       parar='si'; z=[];

   else
       minimo=inf;
       for i=1:m
           if yk(i)>0
               if bb(i)/yk(i)<minimo
                   minimo=bb(i)/yk(i); r=i;
               end
           end
       end
       indB(r)=k;
   end
end

