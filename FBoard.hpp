/******************************************************************************* 
** Author:       Michael Nutt
** Date:         8/15/2019
** Description:  The FBoard class has as data members: 
**               ++ an 8x8 array of chars (the "board")
**               ++ an enum called gameState to hold the state of the game
**               ++ the location of the x piece (xCoordinate)
**               Constructors:
**               ++ Default: initializes the array to empty
**               FBoard Methods:
**               ++ getGameState: returns value of gameState
**               ++ moveX: takes as parameters the row and collumn of the square
**                  to which x will move. Returns a bool.
**               ++ moveO: takes as parameters the row and collumn of the square
**                  to which o will move. Returns a bool.
**               The PossibleGameStates enum holds all possible states of the
**               game:
**               ++ X_WON
**               ++ O_WON
**               ++ UNFINISHED
*******************************************************************************/

#ifndef FBOARD_HPP
#define FBOARD_HPP

enum PossibleGameStates
{
    X_WON,
    O_WON,
    UNFINISHED
};

class FBoard
{
private:
    const int ROW_COUNT = 8;
    const int COL_COUNT = 8;
    char positionTracker[8][8];
    PossibleGameStates gameState;
    int xPosition[2];
    void initializeEmptyBoard();
    bool isValidXMove(int, int, int, int);
    bool checkIfEmpty(int, int);
    bool checkXDiagonal(int, int, int, int);
    bool checkInRange(int, int);
    bool checkGameState();

public:
    FBoard();
    PossibleGameStates getGameState();
    bool moveX(int, int, int, int);
    bool moveO(int, int, int, int);
};

#endif