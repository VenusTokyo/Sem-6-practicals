sumList([],0).
sumList([H|T],S):-sumList(T,S1),
    S is H + S1.
#sumList([1,2,3,4],X).
#X=10
