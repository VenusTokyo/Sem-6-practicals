max(X,Y,M):-X>Y,
    M is X.
max(X,Y,M):-Y>=X,
    M is Y.
#max(0,9,X).
#X=9
