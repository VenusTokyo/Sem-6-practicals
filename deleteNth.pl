del(1,[_|T],T).
del(_,[],[]).
del(N,[H|T],[H|T1]):-
    N1 is N-1,
    del(N1,T,T1).
#del(1,[1,2,3,4],X).
#X=[2,3,4]
