%%%%%%%%%%%%%%%%%%%%%%%%
% Base de connaissance %
%%%%%%%%%%%%%%%%%%%%%%%%
% CrÃ©ation d'un plateau vide
board([0,0,0,0,-1,0,0,0,0]).

% Conditions de victoires du Joueur J
% LIGNES
victoire([J,J,J,_,_,_,_,_,_], J).
victoire([_,_,_,J,J,J,_,_,_], J).
victoire([_,_,_,_,_,_,J,J,J], J).

% COLONNES
victoire([J,_,_,J,_,_,J,_,_], J).
victoire([_,J,_,_,J,_,_,J,_], J).
victoire([_,_,J,_,_,J,_,_,J], J).

% DIAGONALES
victoire([J,_,_,_,J,_,_,_,J], J).
victoire([_,_,J,_,J,_,J,_,_], J).

% est_voisin
est_voisin(0,C2):- C2 = 1; C2 = 3; C2 = 4.
est_voisin(1,C2):- C2 = 0; C2 = 2; C2 = 3; C2 = 4; C2 = 5.
est_voisin(2,C2):- C2 = 1; C2 = 4; C2 = 5.
est_voisin(3,C2):- C2 = 0; C2 = 1; C2 = 4; C2 = 6 ;C2 = 7.
est_voisin(4,_).
est_voisin(5,C2):- C2 = 1; C2 = 2; C2 = 4; C2 = 7; C2 = 8.
est_voisin(6,C2):- C2 = 3; C2 = 4; C2 = 7.
est_voisin(7,C2):- C2 = 3; C2 = 4; C2 = 5; C2 = 6; C2 = 8.
est_voisin(8,C2):- C2 = 4; C2 = 5; C2 = 7.

% est_taquin (c'est une case voisine selon le taquin)
est_taquin(0,1).
est_taquin(0,3).
est_taquin(1,0).
est_taquin(1,2).
est_taquin(1,4).
est_taquin(2,1).
est_taquin(2,5).
est_taquin(3,0).
est_taquin(3,4).
est_taquin(3,6).
est_taquin(4,1).
est_taquin(4,3).
est_taquin(4,5).
est_taquin(4,7).
est_taquin(5,2).
est_taquin(5,4).
est_taquin(5,8).
est_taquin(6,3).
est_taquin(6,7).
est_taquin(7,4).
est_taquin(7,6).
est_taquin(7,8).
est_taquin(8,5).
est_taquin(8,7).

% est_taquin2
est_taquin2(0,2,1).
est_taquin2(0,6,3).
est_taquin2(1,7,4).
est_taquin2(2,0,1).
est_taquin2(2,8,5).
est_taquin2(3,5,4).
est_taquin2(5,3,4).
est_taquin2(6,0,3).
est_taquin2(6,8,7).
est_taquin2(7,1,4).
est_taquin2(8,2,5).
est_taquin2(8,6,7).

%%%%%%%%%%%%%%%%%
% RÃ©gles du jeu %
%%%%%%%%%%%%%%%%%

% On doit avoir posÃ© tout ses pions pour faire des coups plus Ã©voluÃ©s

% Nb de pions : Calcule le nombre de pions du joueur sur la plateau
% (Il ne doit pas dÃ©passer 3)
nb_pions(P,J,Y) :- sublist(=(J), (P), L), length(L,Y).

coupp(P,J,CP,CS) :- coup(P,J,CS), not(inverse(CP,CS)).

inverse([A,B,C], [B,A,C]).


% Pose d'un pion 
coup([0|R],J,[-1,0,0])                  :- nb_pions([0|R],J,N), N < 3.
coup([A,0|R],J,[-1,1,0])                :- nb_pions([A,0|R],J,N), N < 3.
coup([A,B,0|R],J,[-1,2,0])              :- nb_pions([A,B,0|R],J,N), N < 3.
coup([A,B,C,0|R],J,[-1,3,0])            :- nb_pions([A,B,C,0|R],J,N), N < 3.
coup([A,B,C,D,0|R],J,[-1,4,0])          :- nb_pions([A,B,C,D,0|R],J,N), N < 3.
coup([A,B,C,D,E,0|R],J,[-1,5,0])        :- nb_pions([A,B,C,D,E,0|R],J,N), N < 3.
coup([A,B,C,D,E,F,0|R],J,[-1,6,0])      :- nb_pions([A,B,C,D,E,F,0|R],J,N), N < 3.
coup([A,B,C,D,E,F,G,0|R],J,[-1,7,0])    :- nb_pions([A,B,C,D,E,F,G,0|R],J,N), N < 3.
coup([A,B,C,D,E,F,G,H,0],J,[-1,8,0])    :- nb_pions([A,B,C,D,E,F,G,H,0],J,N), N < 3.

% DÃ©placement d'un pion
coup(P,J,[C1,C2,1]) :- est_voisin(C1,C2), nth0(C1,P,J), nth0(C2,P,0).

% DÃ©placement d'une case
coup(P,_,[C1,C2,2]) :- est_taquin(C1,C2), nth0(C2,P,-1).

% DÃ©placement de deux cases
coup(P,_,[C1,C2,3]) :- est_taquin2(C1,C2,_), nth0(C2,P,-1).

coupia(P,J,[A,B,0]) :- coup(P,J,[A,B,0]).
coupia(P,J,C) :- coup(P,J,C), nb_pions(P,J,N), N = 3.

%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Modification du plateau %
%%%%%%%%%%%%%%%%%%%%%%%%%%%

setval([J|P],[_|P],J,0).
setval([X|R],[X|P],J,C) :- C > 0, Y is C-1,setval(R,P,J,Y).

%%%%%%%%%%%%%%%
% Tour de jeu %
%%%%%%%%%%%%%%%
% JEU
% Jouer permet de retourner le plateau une fois le coup jouÃ©
% Pose d'un pion
jouer(P, J, [-1,C,0], R) :- setval(R, P, J, C).

% DÃ©placement d'un pion
jouer(P, J, [C1,C2,1], R) :- setval(X,P,0,C1), setval(R,X,J,C2).

% DÃ©placement de case
jouer(P, _, [C1,C2,2], R) :- nth0(C1,P,Y),setval(X,P,Y,C2),setval(R,X,-1,C1).

% DÃ©placement de deux cases
jouer(P, J, [C1,C2,3], R) :- 
        est_taquin2(C1,C2,C0), 
        jouer(P, J, [C0,C2,2], X),
        jouer(X, J, [C1,C0,2], R).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Intelligence Artificielle %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% eval(Plateau,Joueur,Case1,Case2,Type).

eval(P,J,C,N) :- jouer(P,J,C,R), nb_ouverture(R,J,N).

successeur(P,Joueur,[]) :- victoire(P,Joueur),!.
successeur(P,Joueur,R)  :- findall(C,coupia(P,Joueur,C),R).

% Lance la recherche de la meilleure combinaison
meilleur(P,J,M) :- findall(C,coupia(P,J,C),R), est_meilleur(P,R,J,-1001,_,_,M).

% Recherche la meilleure combinaison
est_meilleur(_,[],_,_,C,_,C).

est_meilleur(P,[X|L],J,ScoreP,_,ScoreS,CombiS) :- 
    eval(P,J,X,N),      N > ScoreP, !, est_meilleur(P,L,J,N,X,ScoreS,CombiS).

est_meilleur(P,[_|L],J,ScoreP,CombiP,ScoreS,CombiS):- 
    est_meilleur(P,L,J,ScoreP,CombiP,ScoreS,CombiS).

% nb_ouverture : Pour un plateau et un joueur donnÃ©, retourne le
% nombre d'ouverture de combinaisons gagnantes

% On gagne
nb_ouverture(P,J,1000) :- victoire(P,J),!.

% On perd
nb_ouverture(P,1,-1000) :- victoire(P,2),!.
nb_ouverture(P,2,-1000) :- victoire(P,1),!.

% On ouvre le jeu
nb_ouverture(P,J,N) :- findall(_,coupia(P,J,_), R), length(R,N).


plus_fort(_,V1,C2,V1,C2,V1) :- !.
plus_fort(C1,V1,_,-1001,C1,V1) :- !.
plus_fort(_,-1001,C2,V2,C2,V2) :- !.
plus_fort(C1,V1,_,V2,C1,V1) :- V1 > V2,!.
plus_fort(_,V1,C2,V2,C2,V2) :- V1 < V2,!.


minimax(P,J,D,M):- successeur(P,J,R), maxValue(P,J,D,R,_,M).

% La valeur MAX
% Il n'y a plus de coup de la phase 1 Ã  Ã©valuer la valeur du coup est -Infini.
% Fin de la profondeur, on Ã©value.
maxValue(P,J,0,R,V,M) :- est_meilleur(P,R,J,-1001,_,V,M),!.

% Ã©valuons toutes les branches.
maxValue(P,J,D,[X],V,X) :-
        % Phase 1, on lance la recherche en profondeur dans la branche de X
        jouer(P,J,X,R),adversaire(J,AdvJ), D1 is D-1, successeur(R,AdvJ,K), maxValue(R,AdvJ,D1,K,V,_).

maxValue(P,J,D,[X|L],V,M) :-
        % Phase 1, on lance la recherche en profondeur dans la branche de X
        jouer(P,J,X,R),adversaire(J,AdvJ), D1 is D-1, successeur(R,AdvJ,K), maxValue(R,AdvJ,D1,K,V1,_),
        % Phase 2, on lance la recherche pour les autres coups
        maxValue(P,J,D,L,V2,M2),
        % Phase 3, on selectionne le meilleur coup des deux.
        plus_fort(X,V1,M2,V2,M,V).

adversaire(1,2).
adversaire(2,1).
