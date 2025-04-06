n = randi([1, 10]);
n

v = 1:3:(3*n-2);
v

i = eye(n);
i

A = zeros(n, 3);
for i = 1:n
    A(i, :) = [i, i+1, i+2];
end
A

function P = esercizio0(n,i,j)
if i>n || j>n
    P = -1;
else
    P = eye(n);
    t = P(i,:);
    P(i,:) = P(j,:);
    P(j,:) = t;
end
end

f1 = esercizio0(n, 1, 4);
f1

A = [1 1 1 1;
    2 2 2 2;
    3 3 3 3;
    4 4 4 4];

f2 = esercizio0(4, 1, 4);
B = f2 * A;
C = A' * f2;
B
C
