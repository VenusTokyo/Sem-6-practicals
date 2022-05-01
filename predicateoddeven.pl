evenlength([]).
evenlength([_|R]):-
    oddlength(R).
oddlength([_|R]):-
    evenlength(R).
#evenlength([1,1]).
#true
