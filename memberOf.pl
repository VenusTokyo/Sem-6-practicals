memb(X,[X|_]).
memb(X,[_|Z]):-
   	       memb(X,Z).
#memb(1,[1,2,3]).
#true
