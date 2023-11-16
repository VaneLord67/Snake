#include "map.h"
#include <iostream>
#include <stdexcept>

Map::Map(int sizeX, int sizeY) {
    if (sizeX <= 0 || sizeY <= 0) {
        throw std::invalid_argument("size must be greater than 0");
    }
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    Position snakeInitPosition = Position::generateRandom(sizeX, sizeY);
    snake = Snake(snakeInitPosition);
    Position itemInitPosition = Position::generateRandom(sizeX, sizeY);
    while (itemInitPosition == snakeInitPosition) {
        itemInitPosition = Position::generateRandom(sizeX, sizeY);
    }
    item = Item(itemInitPosition);
}

int Map::moveSnake(char key) {
    std::pair<int, int> dxy = Snake::key2dxy(key);
    int dx = dxy.first;
    int dy = dxy.second;
    Position head = snake.getHeadPosition();
    int newX = head.getX() + dx;
    int newY = head.getY() + dy;
    if (newX < 0 || newY < 0 || newX >= sizeX || newY >= sizeY) {
        // 越界死亡
        return MOVE_DEAD;
    }
    Position p = Position(newX, newY);
    if (snake.getBodySet().find(p) != snake.getBodySet().end()) {
        // 撞到自己身体上
        return MOVE_DEAD;
    }
    Position tail = snake.move(p);
    if (p == item.getPosition()) {
        // 吃食物增加长度
        snake.getBodies().push_back(tail);
        snake.getBodySet().insert(tail);
        if (snake.getBodySet().size() == sizeX * sizeY) {
            return MOVE_WIN;
        }
        regenerateItem();
    }
    return MOVE_SUCCESS;
}

void Map::regenerateItem() {
    Position p = Position::generateRandom(sizeX, sizeY);
    while (snake.getBodySet().find(p) != snake.getBodySet().end()) {
        p = Position::generateRandom(sizeX, sizeY);
    }
    item = Item(p);
}

void Map::print() {
    auto& bodySet = snake.getBodySet();
//    std::cout << "sizeX = " << sizeX << " sizeY = " << sizeY << std::endl;
    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            Position p = Position(i, j);
            if (bodySet.find(p) != bodySet.end()) {
                if (p == snake.getHeadPosition()) {
                    std::cout << "S";
                } else {
                    std::cout << "s";
                }
            } else if (item.getPosition() == p) {
                std::cout << "X";
            } else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
}
