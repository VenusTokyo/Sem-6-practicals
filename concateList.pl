conc([],L,L).
conc([X|L1],L2,[X|L3]):-conc(L1,L2,L3).
#conc([2,3],[4,5],X).
#X=[2,3,4,5]
