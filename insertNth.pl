insert_nth(I,1,L,[I|L]).
insert_nth(I,N,[X|Y],[X|Z]):-A is N-1,insert_nth(I,A,Y,Z).
#insert_nth(1,1,[6],R).
#R=[1,6]
