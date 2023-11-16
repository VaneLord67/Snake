#ifndef SNAKE_MAP_H
#define SNAKE_MAP_H

#include "snake.h"
#include "item.h"

class Map{
private:
    Snake snake;
    Item item{};
    int sizeX;
    int sizeY;

public:
    enum MoveState {
        MOVE_SUCCESS = 0,
        MOVE_DEAD,
        MOVE_WIN,
    };

    Map(int sizeX, int sizeY);

    int moveSnake(char key);
    void regenerateItem();

    void print();
};

#endif //SNAKE_MAP_H
