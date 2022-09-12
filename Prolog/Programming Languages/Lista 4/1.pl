parent(kim,holly).
parent(margaret,kim).
parent(margaret,kent).
parent(esther,margaret).
parent(herbert,margaret).
parent(herbert,jean).

greatGrandParent(GGP,GGC) :- parent(GGP,GP), parent(GP,P), parent(P,GGC).

sibling(X,Y) :- parent(P,X), parent(P, Y), not(X=Y).

% a)
firstCousin(X,Y) :- not(X=Y), parent(A, X), parent(B, Y), sibling(A, B).

% b)
descendant(X,Y) :- parent(Y,X).
descendant(X,Y) :- parent(Y,A), descendant(X,A).
