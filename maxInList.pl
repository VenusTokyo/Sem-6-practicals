maxlist([H],H).
maxlist([H|T],M):- maxlist(T,M1), H<M1 -> M is M1;M is H.
#maxlist([1,2,3,12,5],X).
#X=12
