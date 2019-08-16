#include <iostream>
#include "FBoard.hpp"

using std::cout;
using std::endl;

int main()
{
    FBoard fb;
    fb.moveO(6, 6, 5, 5);
    fb.moveO(5, 5, 6, 4);
    fb.moveO(7, 7, 6, 6);
    fb.moveO(6, 6, 5, 5);
    fb.moveO(5, 5, 4, 4);
    fb.moveO(4, 4, 5, 3);
    fb.moveX(1, 1);
    fb.moveX(2, 2);
    fb.moveX(3, 3);
    fb.moveX(4, 4);
    fb.moveX(5, 5);
    fb.moveX(6, 6);
    fb.moveX(7, 7);
    cout << fb.getGameState() << endl;

    return 0;
}