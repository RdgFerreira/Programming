parent(kim, holly).
parent(margaret, kim).
parent(margaret, kent).
parent(esther, margaret).
parent(herbert, margaret).
parent(herbert, jean).

% greatGrandparent(GGP, GGC) :- parent(GGP, GP), parent(GP, P), parent(P, GGC). 
grandparent(GP, GC) :- parent(GP, P), parent(P, GC).
greatGrandparent(GGP, GGC) :- grandparent(GGP, P), parent(P, GGC).

ancestor(X, Y) :- parent(X, Y).
ancestor(X, Y) :- parent(Z, Y), ancestor(X, Z).

sibling(X,Y) :- parent(P,X), parent(P, Y).
sibling(X,Y) :- parent(P,X), parent(P, Y), not(X=Y).

append([], L, L).
append([Head|TailA], B, [Head|TailC]) :- append(TailA, B, TailC).

member(X, [X|_]).
member(X, [_|Y]) :- member(X, Y).