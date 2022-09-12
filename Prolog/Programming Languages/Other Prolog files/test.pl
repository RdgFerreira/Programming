subset([], []).
subset([H|T], [H|R]) :- subset(T, R).
subset([_|T], SS) :- subset(T, SS).

powerset(S, P) :- findall(SS, subset(S, SS), P).


isEven([]).
isOdd([]) :- false.
isEven([_|T]) :- isOdd(T).
isOdd([_|T]) :- isEven(T).