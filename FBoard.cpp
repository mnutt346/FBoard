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
bool FBoard::checkXDiagonal(int rowFrom, int colFrom, int rowTo, int colTo)
{
    // if the move is more than 1 space
    if (abs(rowTo - rowFrom) > 1 || abs(colTo - colFrom) > 1)
    {
        return false;
    }
    // if the move is straight up
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
    // if the move left
    else if ((rowTo == rowFrom) && (colTo == colFrom))
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*******************************************************************************
    FBoard::isValidMove
    Takes the row and column of the square x is moving from and the row and
    column to which x will move and determines whether that move is legal.
    If the move is illegal, isValidMove returns false. Otherwise it returns true
    "x" can move 1 square
    diagonally in any direction. A piece is not allowed to move off the board or
    to an occupied square.
*******************************************************************************/
bool FBoard::isValidMove(int rowFrom, int colFrom, int rowTo, int colTo)
{
    bool isValid = true;

    if (!checkIfEmpty(rowTo, colTo))
    {
        return false;
    }
    else if (!checkXDiagonal(rowFrom, colFrom, rowTo, colTo))
    {
        return false;
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
// bool FBoard::moveX(int rowFrom, int colFrom, int rowTo, int colTo)
// {
// }