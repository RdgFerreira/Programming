l([], 0).
l([_|Tail], Len) :- l(Tail, TailLen), Len = TailLen + 1.

myLength2([], 0).
myLength2([_|Tail], Len) :- myLength2(Tail, TailLen), Len is TailLen + 1.

myLength3([], 0).
myLength3([_|Tail], Len) :- myLength3(Tail, TailLen), Len =:= TailLen + 1.

% Com operador is, somente o lado direito da expressão é avaliado semanticamente, então podemos fazer chamadas do tipo
% myLength2([1], N). e N será = 2. Mas myLength3 reporta um erro de variáveis livres, pois tenta avaliar os dois
% lados da expressão.
% O operador "=" tenta fazer unificação sintática e não semântica

% --> Somar elementos de uma lista.
sum([],0).
sum([Head|Tail],X) :- sum(Tail,TailSum), X is Head + TailSum.

fact(0, 1).
fact(1, 1).
fact(N, F) :- integer(N), N > 1, N1 is N - 1, fact(N1, F1), F is F1 * N.
% checa se o valor passado é um inteiro de fato

% Maior divisor comum
gcd(X, Y, Z) :- X =:= Y, Z is X.
gcd(X, Y, Denom) :- X > Y, NewY is X - Y, gcd(Y, NewY, Denom).
gcd(X, Y, Denom) :- X < Y, gcd(Y, X, Denom).









