/******************************************************************************* 
** Author:       Michael Nutt
** Date:         8/15/2019
** Description:  Implementation file for FBoard class.
*******************************************************************************/

#include "FBoard.hpp"
#include <cstdlib>

/*******************************************************************************
    FBoard::initializeEmptyBoard
    Initializes the board to empty ('E').
 *******************************************************************************/
void FBoard::initializeEmptyBoard()
{
    for (int i = 0; i < ROW_COUNT; i++)
    {
        for (int j = 0; j < COL_COUNT; j++)
        {
            positionTracker[i][j] = 'E';
        }
    }
}

/*******************************************************************************
    FBoard::initializeEmptyBoard default construtor initalizes the board to 
    empty ('E'), places an 'o' at (5,7), (6,6), (7,5), and (7,7), and an "x" at 
    (0,0), and initializes the gameState to UNFINISHED.
*******************************************************************************/
FBoard::FBoard()
{
    initializeEmptyBoard();
    positionTracker[5][7] = 'o';
    positionTracker[6][6] = 'o';
    positionTracker[7][5] = 'o';
    positionTracker[7][7] = 'o';
    positionTracker[0][0] = 'x';
    xPosition[0] = 0;
    xPosition[1] = 0;
    gameState = UNFINISHED;
}

/*******************************************************************************
    FBoard::getGameState
    Returns the state of the game
*******************************************************************************/
PossibleGameStates FBoard::getGameState()
{
    return gameState;
}

/*******************************************************************************
    FBoard::checkIfEmpty
    Takes a row and column and checks if the square is empty.
    If the square is empty, it returns true, otherwise it returns false.
*******************************************************************************/
bool FBoard::checkIfEmpty(int rowTo, int colTo)
{
    return (positionTracker[rowTo][colTo] == 'E');
}

/*******************************************************************************
    FBoard::checkDiagonal
    Takes a row and column and checks if the move is 1 square diagonally.
    If the move is 1 square diagonally, it returns true, otherwise it returns
    false.
*******************************************************************************/
bool FBoard::checkXDiagonal(int rowTo, int colTo)
{
    // if the move is more than 1 space
    if (abs(rowTo - xPosition[0]) > 1 || abs(colTo - xPosition[1]) > 1)
    {
        return false;
    }
    // if the move is straight up
    else if ((rowTo == xPosition[0] - 1) && (colTo == xPosition[1]))
    {
        return false;
    }
    // if the move is right
    else if ((rowTo == xPosition[0]) && (colTo == xPosition[1] + 1))
    {
        return false;
    }
    // if the move is straight down
    else if ((rowTo == xPosition[0] + 1) && (colTo == xPosition[1]))
    {
        return false;
    }
    // if the move is left
    else if ((rowTo == xPosition[0]) && (colTo == xPosition[1] - 1))
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool FBoard::checkODiagonal(int rowFrom, int colFrom, int rowTo, int colTo)
{
    // if both row and column increase
    if (rowTo > rowFrom && colTo > colFrom)
    {
        return false;
    }
    // if the move is more than 1 space
    else if (abs(rowTo - rowFrom) > 1 || abs(colTo - colFrom) > 1)
    {
        return false;
    }
    // if the move is straigth up
    else if ((rowTo == rowFrom - 1) && (colTo == colFrom))
    {
        return false;
    }
    // if the move is right
    else if ((rowTo == rowFrom) && (colTo == colFrom + 1))
    {
        return false;
    }
    // if the move is straight down
    else if ((rowTo == rowFrom + 1) && (colTo == colFrom))
    {
        return false;
    }
    // if the move is left
    else if ((rowTo == rowFrom) && (colTo == colFrom - 1))
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*******************************************************************************
    FBoard::checkInRange
    Takes a row and column and checks if the move is within the bounds of the 
    board. If the move is inbounds, it returns true. Otherwise, it returns false
*******************************************************************************/
bool FBoard::checkInRange(int rowTo, int colTo)
{
    // check if too far right or down
    if (rowTo > 7 || colTo > 7)
    {
        return false;
    }
    // check if too far left or up
    else if (rowTo < 0 || colTo < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*******************************************************************************
    FBoard::checkGameState
    Checks if the game state is not unfinished. If the game is unfinished, it
    returns true. Otherwise, it returns false.
*******************************************************************************/
bool FBoard::checkGameState()
{
    if (gameState != UNFINISHED)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*******************************************************************************
    FBoard::isValidXMove
    Takes the row and column of the square x is moving from and the row and
    column to which x will move and determines whether that move is legal.
    If the move is illegal, isValidMove returns false. Otherwise it returns true
    "x" can move 1 square diagonally in any direction. 
    A piece is not allowed to move off the board or to an occupied square.
    If x reaches square (7,7), the game state should change to X_WON.
*******************************************************************************/
bool FBoard::isValidXMove(int rowTo, int colTo)
{
    if (!checkGameState())
    {
        return false;
    }
    else if (!checkIfEmpty(rowTo, colTo))
    {
        return false;
    }
    else if (!checkInRange(rowTo, colTo))
    {
        return false;
    }
    else if (!checkXDiagonal(rowTo, colTo))
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*******************************************************************************
    FBoard::isValidOMove
    Takes the row and column of the square o is moving from and the row and
    column to which o will move and determines whether that move is legal.
    If the move is illegal, isValidMove returns false. Otherwise it returns true
    "o" can move 1 square diagonally, but the row and column cannot both increase. 
    A piece is not allowed to move off the board or to an occupied square.
    If there are no more legal moves for x, the gameState should be set to 
    O_WON.
*******************************************************************************/
bool FBoard::isValidOMove(int rowFrom, int colFrom, int rowTo, int colTo)
{
    if (!checkGameState())
    {
        return false;
    }
    else if (!checkIfEmpty(rowTo, colTo))
    {
        return false;
    }
    else if (!checkInRange(rowTo, colTo))
    {
        return false;
    }
    else if (!checkODiagonal(rowFrom, colFrom, rowTo, colTo))
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*******************************************************************************
FBoard::checkRemainingXMoves
Checks if there are any x moves remaining. Returns true if there are moves left.
Otherwise, it returns false.
*******************************************************************************/
bool FBoard::checkRemainingXMoves()
{
    int possibleMoves = 4;
    // check if x can go up and left
    if (!isValidXMove(xPosition[0] - 1, xPosition[1] - 1))
    {
        possibleMoves--;
    }
    // check if x can go up and right
    if (!isValidXMove(xPosition[0] - 1, xPosition[1] + 1))
    {
        possibleMoves--;
    }
    // check if x can go down and right
    if (!isValidXMove(xPosition[0] + 1, xPosition[1] + 1))
    {
        possibleMoves--;
    }
    // check if x can go down and left
    if (!isValidXMove(xPosition[0] + 1, xPosition[1] - 1))
    {
        possibleMoves--;
    }
    return (possibleMoves > 0);
}

/*******************************************************************************
    FBoard::checkForWinner
    Checks if there is a winner. If a winner is found, it returns the winner 
    value ('x' or 'o').
*******************************************************************************/
void FBoard::checkForWinner()
{
    // check if o is the winner
    if (!checkRemainingXMoves() && xPosition[0] != 7 && xPosition[1] != 7)
    {
        gameState = O_WON;
    }
    else if (xPosition[0] == 7 && xPosition[1] == 7)
    {
        gameState = X_WON;
    }
}

/*******************************************************************************
    FBoard::moveX
    Takes the row and column of the square x is moving from and the row and
    column to which x will move. If the desired move is not allowed, or if the 
    game has already been won, it returns false.
    Otherwise, it makes the move and returns true. "x" can move 1 square
    diagonally in any direction. A piece is not allowed to move off the board or
    to an occupied square. If x's move is to square (7,7), the gameState is 
    changed to X_WON
*******************************************************************************/
bool FBoard::moveX(int rowTo, int colTo)
{
    if (!isValidXMove(rowTo, colTo))
    {
        return false;
    }
    else
    {
        positionTracker[xPosition[0]][xPosition[1]] = 'E';
        positionTracker[rowTo][colTo] = 'o';
        xPosition[0] = rowTo;
        xPosition[1] = colTo;
        checkForWinner();
        return true;
    }
}

/*******************************************************************************
    FBoard::moveO
    Takes the row and column of the square o is moving from and the row and
    column to which o will move. If the desired move is not allowed, or if the 
    game has already been won, it returns false.
    Otherwise, it makes the move and returns true. "o" can move 1 square
    diagonally, but the row and column cannot both increase. A piece is not 
    allowed to move off the board or to an occupied square.
*******************************************************************************/
bool FBoard::moveO(int rowFrom, int colFrom, int rowTo, int colTo)
{
    if (!isValidOMove(rowFrom, colFrom, rowTo, colTo))
    {
        return false;
    }
    else
    {
        positionTracker[rowTo][colTo] = 'o';
        positionTracker[rowFrom][colFrom] = 'E';
        checkForWinner();
        return true;
    }
}