% Esercizio 1
fprintf("Es1:\n");
n = 5;
v = randn(n,1);
y_1 = sum(abs(v));
fprintf('Norma 1:\n%.20f\n', y_1);

y_inf = max(abs(v));
fprintf('Norma inf:\n%.20f\n', y_inf);

y_2 = sqrt(sum(v.^2));
fprintf('Norma Euclidea:\n%.20f\n', y_2);

% Esercizio 2
fprintf("\nEs2:\n");
n = 5;
% matrice quadrata n x n
A = randn(n);
y_1 = norm(A,1);
fprintf('Norma 1:\n%.20f\n', y_1);

y_inf = norm(A,inf);
fprintf('Norma inf:\n%.20f\n', y_inf);

y_Fro = norm(A,'fro');
fprintf('Norma Frobenius:\n%.20f\n', y_Fro);

% Esercizio 3
fprintf("\nEs3:\n");
clear

a = 1;
alpha = sin(a);
n = 16;
h = 10.^(-1:-1:-n)'';

a_star = (sin(a+h) - sin(a-h)) ./ h;
err = abs(a_star - alpha) / abs(alpha);

fprintf('  h\t\talpha_star\t\terrore relativo\n');
for i = 1:n
    fprintf('%.1e\t%.8f\t%.2e\n', h(i), a_star(i), err(i));
end