%	Création et Initialisation du plateau de jeu	%

plateau([0,0,0,0,-1,0,0,0,0]).
 
%	Case vide: -1		%
%	Case avec carré: 0		%
%	Case avec pion J1: 1	%
%	Case avec pion J2: 2	%

%	Mise en place du voisinage de chaque case du plateau	%
				%  -------------  %
				%  | 0 | 1 | 2 |  %
				%  -------------  %
				%  | 3 | 4 | 5 |  %
				%  -------------  %
				%  | 6 | 7 | 8 |  %
				%  -------------  %

dpl_case(0,P):- P=1; P=3.
dpl_case(1,P):- P=0; P=2; P=4.
dpl_case(2,P):- P=1; P=5.
dpl_case(3,P):- P=0; P=4; P=6.
dpl_case(4,P):- P=1; P=3; P=5; P=7.
dpl_case(5,P):- P=2; P=4; P=8.
dpl_case(6,P):- P=3; P=7.
dpl_case(7,P):- P=4; P=6; P=8.
dpl_case(8,P):- P=5; P=7.

dpl_2case(0,P1,P2):- P1=1, P2=2; P1=3, P2=6; P1=2, P2=1; P1=6 P2=3.
dpl_2case(1,P1,P2):- P1=4, P2=7; P1=7; P2=4.
dpl_2case(2,P1,P2):- P1=0, P2=1; P1=5, P2=8; P1=1, P2=0; P1=8, P2=5.
dpl_2case(3,P1,P2):- P1=4, P2=5; P1=5, P2=4.
dpl_2case(5,P1,P2):- P1=3, P2=4, P1=4, P2=3.
dpl_2case(6,P1,P2):- P1=0, P2=3; P1=7, P2=8; P1=3, P2=0; P1=8, P2=7.
dpl_2case(7,P1,P2):- P1=1, P2=4; P1=4, P2=1.
dpl_2case(8,P1,P2):- P1=2, P2=5; P1=6, P2=7; P1=5, P2=2; P1=7, P2=6.

%	Condition de victoire pour le joueur J	%

victoire([J,J,J,_,_,_,_,_,_], J).	%	1eme ligne		(0,1,2)	
victoire([_,_,_,J,J,J,_,_,_], J).	%	2eme ligne		(3,4,5)	
victoire([_,_,_,_,_,_,J,J,J], J).	%	3eme ligne		(6,7,8)	
victoire([J,_,_,J,_,_,J,_,_], J).	%	1ere colonne 	(0,3,6)	
victoire([_,J,_,_,J,_,_,J,_], J).	%	2eme colonne 	(1,4,7)	
victoire([_,_,J,_,_,J,_,_,J], J).	%	3eme colonne 	(2,5,8)	
victoire([J,_,_,_,J,_,_,_,J], J).	%	1ere diagonale	(0,4,8)	
victoire([_,_,J,_,J,_,J,_,_], J).	%	2eme diagonale	(2,4,6)	

%	Vérification pour déplacer une pion : case arrivée avec carré sans pion	%

case_vide([X|_],0):- X=0.
case_vide([_|R],C):- C>0, C1 is C-1, case_vide(R,C1).
 
%	Vérification pour déplacer une case : case arrivée sans carré	%
 
vide([X|_],0):- X=-1.
vide([_|R],C):- C>0, C1 is C-1, vide(R,C1).
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 					  RÈGLE DU JEU					  %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
%	Calcule le nombre de pion qu’un joueur a posé sur le plateau 	%
 
nb_pions([X|R],J,N):- X=J, N1 = N+1, nb_pions(R,J,N1),!.
nb_pions([_|R],J,N):- nb_pions(R,J,N).
 
%	Vérifie que le coup suivant est différent du précédent		%
%	CP : coup précédent, CS : coup suivant	
 
coup_prec(P,J,CP,CS):- coup(P,J,CS), not(inverse(CP,CS)).
 
%	Vérification de l’inversion entre 2 coups 	%
%	A: position de case/pion de départ (-1 si le pion va être posé)	
%	B: position de case/pion d’arrivée	
%	C: valeur de l’action (0: pose pion, 1: déplacement 1 pion,	
%	2: déplacement 1 case, 3: déplacement 2 cases)	
 
 
inverse([A,B,C], [B,A,C]).	
 
%	Pose d’un pion	%
%	C : case d’arrivée		
 
action(P,J,[-1,C,0]):- case_vide(P,C), nb_pions(P,J,N), N<3.
 
%	Déplacement d’un pion	%
 
action(P,J,[A,B,1]):- case_vide(P,B), nth0(A,P,J).
 
%	Déplacement d’une case	%
 
action(P,_,[A,B,2]):- vide(P,B), dpl_case(A,B).
 
%	Déplacement de deux cases	%
 
action(P,_,[A,B,3]):- vide(P,B), dpl_2case(B,A,_).

%	Modification d’une valeur	%
%	C: position de la case d’arrivée, J: valeur pion (-1, 0 , 1, 2)	
 
modif([J|P],[_|P],J,0).
modif([X|R],[X|P],J,C):- C>0, C1 is C-1, modif(R,P,J,C1).
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%						JEU						  %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
%	Renvoie le plateau modifié (R) après une action 	  %
 
%	Pose d’un pion	%
 
jouer(P,J,[-1,C,0],R):- modif(R,P,J,C).
 
%	Déplacement d’un pion	%
 
jouer(P,J,[A,B,1],R):- modif(R1,P,0,A), modif(R,R1,J,B).
 
%	Déplacement d’une case 	%
 
jouer(P,_,[A,B,2],R):- nth0(A,P,X), modif(R1,P,X,B), modif(R,R1,-1,A).
 
%	Déplacement de deux cases	%
 
jouer(P,J,[A,B,3],R):- dpl_2case(A,B,C), jouer(P,J,[A,C,2],X), jouer(X,J,[B,A,2],R).
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%				   Intelligence Artificielle			  	  %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
%	Positionnement des 3 pions lors des 3 premiers tours	%
 
action_ia(P,J,[A,B,0]):- action(P,J,[A,B,0].
action_ia(P,J,C):- action(P,J,C), nb_pions(P,J,N), N=3.
 
%	Nombre de combinaisons gagnantes après un coup C 	%
%	100 représente la condition de victoire
%	-100 représente la condition de défaite
%	-101 représente la condition de départ du jeu
 
 
%	En ouvrant le jeu  	%
 
nb_cas_win(P,J,N):- findall(_,action_ia(P,J,_),R), length(R,N).
 
 
%	On gagne	%
 
nb_cas_win(P,J,100):- victoire(P,J),!.
 
%	On perd	%
 
nb_cas_win(P,1,-100):- victoire(P,2),!.
 
nb_cas_win(P,2,-100):- victoire(P,1),!.
 
%	Evaluation du plateau après un coup	%
 
eval(P,J,C,N):- jouer(P,J,C,R), nb_cas_win(R,J,N).
 
%	Action au coup d’après	%
%	S’il n’y a pas de coup à jouer, pas de successeur et donc victoire ou %	défaite; sinon renvoie la liste des coups possibles suivant le coup  %	précédent	
 
successeur(P,J,[]):- victoire(P,J),!.
 
successeur(P,J,R):- findall(C,action_ia(P,J,C),R).
 
%	Recherche de la meilleure combinaison	%
%	Sp: Score possible, Cp: Combinaison possible,
%	Ss: Score sélectionnée, Cs: Combinaison sélectionnée
 
meilleure_combi(_,[],_,_,C,_,C).
 
meilleure_combi(P,[X|L],J,Sp,_,Ss,Cs):- eval(P,J,X,N), N > Sp, !, meilleure_combi(P,L,J,N,X,Ss,Cs).
 
meilleure_combi(P,[_|L],J,Sp,Cp,Ss,Cs):- meilleure_combi(P,L,J,Sp,Cp,Ss,Cs).
 
%	Lancement de la recherche de la meilleure combinaison	%
 
meilleure(P,J,M):- findall(C,action_ia(P,J,C),R), meilleure_combi(P,R,J,-101,_,_,M).
 
%	Sélection du meilleur coup selon leur condition de victoire	  %
%	Cv: condition de victoire (-101/-100/100)
 
meilleur_coup(_,Cv1,C2,Cv1,C2,Cv1):- !.
meilleur_coup(C1,Cv1,_,-101,C1,Cv1):- !.
meilleur_coup(_,-101,C2,Cv2,C2,Cv2):- !.
meilleur_coup(C1,Cv1,_,Cv2,C1,Cv1):- Cv1 > Cv2, !.
meilleur_coup(_,Cv1,C2,Cv2,C2,Cv2):- Cv1 < Cv2, !.
 
%	Recherche de la valeur de condition de victoire maximale	%
 
max(P,J,0,R,Cv,M):- meilleure_combi(P,R,J,-101,_,Cv,M), !.
 
%	Évaluation en profondeur de la branche X	
 
max(P,J,D,[X],V,X):- jouer(P,J,X,R), joueur(J,AdvJ), cpt1 is cpt-1, successeur(R,AdvJ,K), max(R,AdvJ,cpt1,K,Cv,_).
 
%	Evaluation en profondeur de la branche X puis recherche pour les autres coups de la liste, ensuite sélection du meilleur coup des deux	
 
max(P,J,cpt,[C|L],Cv,M):- jouer(P,J,X,R), joueur(J,AdvJ), cpt1 is cpt, successeur(R,AdvJ,K), max(R,AdvJ,cpt1,K,Cv1,_),max(P,J,cpt,L,Cv2,M2), meilleur_coup(X,Cv1,M2,Cv2,M,Cv).
 
%	Détermine qui est le joueur 1 ou 2	%
 
joueur(1,2).
joueur(2,1).
