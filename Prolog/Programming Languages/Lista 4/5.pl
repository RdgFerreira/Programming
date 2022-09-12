setMinus(X, Y, I) :- isMember(I, X) , not(isMember(I, Y)).

setPlus(I, Y, Z) :- (isMember(I, Y) ; isMember(I, Z)).

isDifference([XHead|XTail], Y, [ZHead|ZTail]) :- setMinus([XHead|XTail], Y, ZHead) , setPlus(XHead, Y, [ZHead|ZTail]) , isDifference(XTail, Y, ZTail).