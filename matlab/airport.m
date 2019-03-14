N = 200;    %population
T = zeros(N,N); %transformation matrix
I = 1;      % initially informed
S = zeros;
for i = 1:N  %rows
    for j = 1:N  %cols
        if j < i || j > 2*i
            T(i,j) = 0;
        %elseif j = i
         %   T(i,j) = (((i-1)+0.5*(N-i))/(N-1))^i;
        elseif 2*i > N && j == N
            for m = N-i:i
                T(i,j) = T(i,j) + nchoosek(i,m)*((0.5*(N-i)/(N-1))^m)*((((i-1)/(N-1))+(0.5*(N-i)/(N-1)))^(i-m));
            end           
        else
            k = j-i;
            T(i,j) = nchoosek(i,k)*((0.5*(N-i)/(N-1))^k)*((((i-1)/(N-1))+(0.5*(N-i)/(N-1)))^(i-k));
        end
    end
end
for i = 1:N
    S(i) = sum(T(i,:));
end
function p = npermutek(n,r)
    p = fact(n)/fact(n-r);
end
function f = fact(n)
    f = prod(1:n);
end