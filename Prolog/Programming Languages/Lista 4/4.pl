% isEqual(X,Y) :- permutation(X,Y).
belongsToList(X, [X|_]) :- true.
belongsToList(X, [H|T]) :- belongsToList(X, T).
matchLists([], _) :- true.
matchLists([H|T], Y) :- belongsToList(H, Y), matchLists(T, Y).
isEqual(X, Y) :- matchLists(X, Y), matchLists(Y, X).