parent(kim, holly).
parent(margaret, kim).
parent(margaret, kent).
parent(esther, margaret).
parent(herbert, margaret).
parent(herbert, jean).

% ?_ parent(X,Y) = parent(kim,Y). --> Unificável, {X = kim, Y = holly}
% <X, kim>, {} -> Eliminação -> {} U {X = kim},
% <Y, Y> {}, -> Identidade -> {}
% Interpretador de Prolog só aponta solução {X = kim}