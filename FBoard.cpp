/******************************************************************************* 
** Author:       Michael Nutt
** Date:         8/15/2019
** Description:  Implementation file for FBoard class.
*******************************************************************************/

#include "FBoard.hpp"

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

/* default construtor initalizes the board to empty ('E'), places an 'o' at 
   (5,7), (6,6), (7,5), and (7,7), and an "x" at (0,0), and initializes the
   gameState to UNFINISHED.
*/
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
