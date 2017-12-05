#include "TicTacToe.h"

TicTacToe::TicTacToe() 
{
    //initialize board states
    resetBoard();

    //PLAYER_X always goes first
    turn = PLAYER_X;
}

void TicTacToe::nextTurn()
{
    turn = (turn == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

int TicTacToe::getTurn()
{
    return turn;
}

void TicTacToe::play(int tile)
{
    board[tile] = turn;
    selections++;
}

bool TicTacToe::isFull()
{
    return selections >= 9;
}

int TicTacToe::isWon() {
    if (selections > 4) 
    {
         //check row 1 [0,1,2]
	if (winningThree(0, 1, 2))
	    return board[0];

	//check row 2 [3,4,5]
	if (winningThree(3, 4, 5))
	     return board[3];

	//check row 3 [6,7,8]
	if (winningThree(6, 7, 8))
	    return board[6];

	//check column 1 [0,3,6]
	if (winningThree(0, 3, 6))
	    return board[0];

	//check column 2 [1,4,7]
	if (winningThree(1, 4, 7))
	    return board[1];

	//check column 3 [2,5,8]
	if (winningThree(2, 5, 8))
	    return board[2];

        //check diagonal [0,4,8]
	if (winningThree(0, 4, 8))
	    return board[0];

	//check diagonal [2,4,6]
        if (winningThree(2, 4, 6))
            return board[2];
    }
    return UNSELECTED;
}

void TicTacToe::resetBoard()
{
    int i = 0;
    for (i; i < 9; i++)
    {
         board[i] = UNSELECTED;
    }
    selections = 0;
}

const std::array<int,9> TicTacToe::returnBoardCopy()
{
    return board;
}

bool TicTacToe::winningThree(int a, int b, int c)
{
    return ((board[a] >= 0 && board[b] >= 0 && board[c] >= 0) &&
    (board[a] == board[b] && board[b] == board[c]));
}