#pragma once
#include <vector>
#include <cstring>
#ifndef BOARD_H 
#define BOARD_H

using namespace std;


class Board
{
private:
	int board[9];
	int _board[9];
	int hash;
	int manhattan;
	int misplaced;
	int moves[4];
	int topleft;
	double fitness;

	void calcHash();
	void calcManhattan();
	void calcMisPlaced();
	void calcMoves();
	void calcTopLeft();
	void calcFitness();

public:
	Board(const char *conf);
	Board(const int arrayboard[9]);
	Board(const int hash);

	int getHash() { calcHash(); return hash; }//used in Solution truncate and mutate and growBestNoCycle and Board calcMoves
	int getManhattan() { calcManhattan(); return manhattan; }//used in Solution getFitness() and Board calcFitness()
	int getMisPlaced() { calcMisPlaced(); return misplaced; }//used in Board calcFitness()
	int getTopLeft() { calcTopLeft(); return topleft; }//used in Solution getFitness()
	double getFitness() { calcFitness(); return fitness; }//used in Solution growBestNoCycle
	int * getBoard() { for (int i = 0; i < 9; i++) _board[i] = board[i]; return _board; }//used in Board calcMoves and getDistance
	int * getMoves() { calcMoves(); return moves; }//used in Solution growBestNoCycle and growNoCycle
	void printPretty();//used in Solution print
	void printConf();//used in world constructor and Population printVerbose and printSummary
};

namespace BoardSpace //used in Solution solved
{
	const int goalBoard[9] = { 8, 0, 1, 2, 3, 4, 5, 6, 7 };
	const int goalBoardHash = 123456780;

	int getCol(int);//used in Board calcManhattan() and getDistance
	int getRow(int);//used in Board calcManhattan() and getDistance
	void swap(int*, int, int); //used in Board calcMoves
}

#endif