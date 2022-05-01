merge_list([],[],[]).
merge_list([],L2,L2).
merge_list(L1,[],L1).
merge_list([H1|T1],[H2|T2],[H1|T3]):-
    H1=<H2,
merge_list(T1, [H2|T2], T3).
merge_list([H1|T1],[H2|T2],[H2|T3]):-
    merge_list([H1|T1], T2, T3).
#merge_list([1,4,3,2],[6,5,0],L).
#L=[1,4,3,2,6,5,0]
