n = 4;

%%%
% v = ones(1,n);
% A = v;
% for i = 2:n
%     A = [A;i*v];
% end

%%%
% A = ones(n);
% for i = 2:n
%     A(i,:) = i;
% end
% D = diag([1:n]);
% A = D*ones(n);

v = (1:n)';
z = ones(1,n);
A = v*z;

% A = ones(n);
% v = [1:n]';
% A = A.*v

P = esercizio0(n,1,4);
B = P*A;

C = A';

disp(C);