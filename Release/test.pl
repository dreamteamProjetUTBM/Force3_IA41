factoriel(X):- X = 4, Y is 0, factoriel(X, Y).
factoriel(_, Y):- Y >= 4, !.
factoriel(X, Y):- Z is Y+1, factoriel(X, Z).