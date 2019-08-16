#include <iostream>
#include "FBoard.hpp"

using std::cout;
using std::endl;

int main()
{
    FBoard fb;
    fb.moveX(1, 1);
    fb.moveX(2, 0);
    fb.moveO(6, 6, 5, 5);
    cout << fb.getGameState() << endl;

    return 0;
}