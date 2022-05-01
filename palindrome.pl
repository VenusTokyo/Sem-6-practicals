ar([H|T],A,R):-ar(T,[H|A],R).
ar([],A,A).
rev(L,R):-ar(L,[],R).
palindrome(L):-rev(L,L).
#palindrome([1,2,1]).
#true
