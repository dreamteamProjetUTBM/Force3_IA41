#pragma once

/*
	Classe Game

	Permet de g�rer les scores, d'effectuer des v�rification sur 
	le respect des r�gles du jeu en appellant des pr�dicats prolog.
*/
class Game
{
private:
	int _score_J1;
	int _score_J2;

public:
	Game();
	~Game();

	int Game::GetScoreJ1();
	void Game::SetScoreJ1(int value);

	int Game::GetScoreJ2();
	void Game::SetScoreJ2(int value);
};

