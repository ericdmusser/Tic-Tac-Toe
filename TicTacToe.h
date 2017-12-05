#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <array>

enum BoardStates {
    UNSELECTED = -1,
    PLAYER_X = 0,
    PLAYER_O = 1,
};

class TicTacToe {
public:
    TicTacToe();

    //changes to next turn
    void nextTurn();

    //Returns current turn
    int getTurn();

    //Sets board tile to player who selected it 
    //(PLAYER_X or PLAYER_O)
    void play(int tile);

    //Returns PLAYER_X or PLAYER_O if won, 
    //UNSELECTED otherwise.
    int isWon();

    //Returns True if full
    bool isFull();

    //Returns copy of board state
    const std::array<int, 9> returnBoardCopy();

    //Sets board array to UNSELECTED and selections to 0.
    void resetBoard();

private:
    //PLAYER_X or PLAYER_O
    int turn;

    //9 integers of value UNSELECTED, PLAYER_X, or PLAYER_O
    std::array<int, 9> board;

    //Number of selections(plays) made by players
    int selections;
	
    //Returns true if a, b and c are selected 
    //(PLAYER_X or PLAYER_O) AND equal to each other 
    bool winningThree(int a, int b, int c);
};

#endif // !TICTACTOE_H