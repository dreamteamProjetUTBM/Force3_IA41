%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%       Règles              %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Conditions de victoires du Joueur J
% J : Joueur
win([J,J,J,_,_,_,_,_,_], J).
win([_,_,_,J,J,J,_,_,_], J).
win([_,_,_,_,_,_,J,J,J], J).
win([J,_,_,J,_,_,J,_,_], J).
win([_,J,_,_,J,_,_,J,_], J).
win([_,_,J,_,_,J,_,_,J], J).
win([J,_,_,_,J,_,_,_,J], J).
win([_,_,J,_,J,_,J,_,_], J).

is_neighbour(0,C2):- C2 = 1; C2 = 3; C2 = 4.
is_neighbour(1,C2):- C2 = 0; C2 = 2; C2 = 3; C2 = 4; C2 = 5.
is_neighbour(2,C2):- C2 = 1; C2 = 4; C2 = 5.
is_neighbour(3,C2):- C2 = 0; C2 = 1; C2 = 4; C2 = 6 ;C2 = 7.
is_neighbour(4,_).
is_neighbour(5,C2):- C2 = 1; C2 = 2; C2 = 4; C2 = 7; C2 = 8.
is_neighbour(6,C2):- C2 = 3; C2 = 4; C2 = 7.
is_neighbour(7,C2):- C2 = 3; C2 = 4; C2 = 5; C2 = 6; C2 = 8.
is_neighbour(8,C2):- C2 = 4; C2 = 5; C2 = 7.

taquin(0,P):- P=1; P=3.
taquin(1,P):- P=0; P=2; P=4.
taquin(2,P):- P=1; P=5.
taquin(3,P):- P=0; P=4; P=6.
taquin(4,P):- P=1; P=3; P=5; P=7.
taquin(5,P):- P=2; P=4; P=8.
taquin(6,P):- P=3; P=7.
taquin(7,P):- P=4; P=6; P=8.
taquin(8,P):- P=5; P=7.

taquin2(0,P1,P2):- P1=1, P2=2; P1=3, P2=6; P1=2, P2=1; P1=6, P2=3.
taquin2(1,P1,P2):- P1=4, P2=7; P1=7; P2=4.
taquin2(2,P1,P2):- P1=0, P2=1; P1=5, P2=8; P1=1, P2=0; P1=8, P2=5.
taquin2(3,P1,P2):- P1=4, P2=5; P1=5, P2=4.
taquin2(5,P1,P2):- P1=3, P2=4, P1=4, P2=3.
taquin2(6,P1,P2):- P1=0, P2=3; P1=7, P2=8; P1=3, P2=0; P1=8, P2=7.
taquin2(7,P1,P2):- P1=1, P2=4; P1=4, P2=1.
taquin2(8,P1,P2):- P1=2, P2=5; P1=6, P2=7; P1=5, P2=2; P1=7, P2=6.


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%         Général           %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%	Calcule le nombre de pion qu’un joueur a posé sur le plateau
% premier
nb_pions([],_,0).
nb_pions([J|R],J,N):- nb_pions(R,J,N1), N is N1+1, !.
nb_pions([_|R],J,N):- nb_pions(R,J,N).


% Pose d un pion 
action([0|R],J,[-1,0,0])                  :- nb_pions([0|R],J,N), N < 3.
action([A,0|R],J,[-1,1,0])                :- nb_pions([A,0|R],J,N), N < 3.
action([A,B,0|R],J,[-1,2,0])              :- nb_pions([A,B,0|R],J,N), N < 3.
action([A,B,C,0|R],J,[-1,3,0])            :- nb_pions([A,B,C,0|R],J,N), N < 3.
action([A,B,C,D,0|R],J,[-1,4,0])          :- nb_pions([A,B,C,D,0|R],J,N), N < 3.
action([A,B,C,D,E,0|R],J,[-1,5,0])        :- nb_pions([A,B,C,D,E,0|R],J,N), N < 3.
action([A,B,C,D,E,F,0|R],J,[-1,6,0])      :- nb_pions([A,B,C,D,E,F,0|R],J,N), N < 3.
action([A,B,C,D,E,F,G,0|R],J,[-1,7,0])    :- nb_pions([A,B,C,D,E,F,G,0|R],J,N), N < 3.
action([A,B,C,D,E,F,G,H,0],J,[-1,8,0])    :- nb_pions([A,B,C,D,E,F,G,H,0],J,N), N < 3.

% Déplacement d un pion
action(P,J,[C1,C2,1]) :- is_neighbour(C1,C2), nth0(C1,P,J), nth0(C2,P,0).

% Déplacement d une case
action(P,_,[C1,C2,2]) :- taquin(C1,C2), nth0(C2,P,-1).

% Déplacement de deux cases
action(P,_,[C1,C2,3]) :- taquin2(C1,C2,_), nth0(C2,P,-1).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%       Tour de jeu         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Pose d un pion
play(P, J, [-1,C,0], R) :- setval(R, P, J, C).

% Déplacement d un pion
play(P, J, [C1,C2,1], R) :- setval(X,P,0,C1), setval(R,X,J,C2).

% Déplacement de case
play(P, _, [C1,C2,2], R) :- nth0(C1,P,Y),setval(X,P,Y,C2),setval(R,X,-1,C1).

% Déplacement de deux cases
play(P, J, [C1,C2,3], R) :- 
        taquin2(C1,C2,C0), 
        play(P, J, [C0,C2,2], X),
        play(X, J, [C1,C0,2], R).


% Vérifie l action du joueur
%   P : plateau
%   J : joueur
%   A : position de départ
%   B : postion d arrivé
%   C : coup joué (0 = pose d un pion, 1 = deplacement pion, 2 = deplacement d une case, 3 = deplacement de deux cases) 
is_possible(P,J,[A,B,C]):- action(P,J,[A,B,C]).


%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Modification du plateau %
%%%%%%%%%%%%%%%%%%%%%%%%%%%

setval([J|P],[_|P],J,0).
setval([X|R],[X|P],J,C) :- C > 0, Y is C-1,setval(R,P,J,Y).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%           IA              %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Méthode à appelé dans le cpp 
% Trouve le meilleur coup
%   P : plateau (exemple : [1,1,0,0,-1,0,0,0,0])
%   J : joueur (1 ou 2)
%   M : [A,B,C]     
%       A : position de départ
%       B : position d arrivé   
%       C : coup joué (0 = pose d un pion, 1 = deplacement pion, 2 = deplacement d une case, 3 = deplacement de deux cases) 
best_combination(P,J,M) :- findall(C,action_ia(P,J,C),R), is_the_best(P,R,J,-1001,_,_,M).


% Recherche la meilleure combinaison en comparant les scores obtenus
is_the_best(_,[],_,_,C,_,C).

is_the_best(P,[X|L],J,ScoreP,_,ScoreS,CombiS) :- 
    eval(P,J,X,N),      N > ScoreP, !, is_the_best(P,L,J,N,X,ScoreS,CombiS).

is_the_best(P,[_|L],J,ScoreP,CombiP,ScoreS,CombiS):- 
    is_the_best(P,L,J,ScoreP,CombiP,ScoreS,CombiS).

eval(P,J,C,N) :- play(P,J,C,R), nb_ouverture(R,J,N).


action_ia(P,J,[A,B,0]):- action(P,J,[A,B,0]).
action_ia(P,J,C):- nb_pions(P,J,N), N=3,action(P,J,C).


% nb_ouverture : Pour un plateau et un joueur donné, retourne le
% nombre d ouverture de combinaisons gagnantes

% Win
nb_ouverture(P,J,1000) :- win(P,J),!.

% Lose
nb_ouverture(P,1,-1000) :- win(P,2),!.
nb_ouverture(P,2,-1000) :- win(P,1),!.

% Initialisation
nb_ouverture(P,J,N) :- findall(_,action_ia(P,J,_), R), length(R,N).
