dupList([],[]).
dupList([X|Tail1x], [X,X|Tail2x]) :- dupList(Tail1x,Tail2x).