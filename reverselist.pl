ar([H|T],A,R):-ar(T,[H|A],R).
ar([],A,A).
reverse(L,R):-ar(L,[],R).
#reverse([1,2,3,4],X).
#X=[4,3,2,1]
