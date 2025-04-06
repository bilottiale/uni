function [P] = esercizio0(n,i,j)
if i>n || j>n
    P = -1;
else
    P = eye(n);
    t = P(i,:);
    P(i,:) = P(j,:);
    P(j,:) = t;
end