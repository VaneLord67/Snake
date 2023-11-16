#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <vector>
#include <unordered_set>
#include "position.h"
#include <unordered_map>

class Snake {
private:
    std::vector<Position> bodies;
    std::unordered_set<Position, Position> bodySet;
public:
    Snake() = default;
    explicit Snake(Position position);
    ~Snake() = default;

    static std::pair<int, int> key2dxy(char key);
    const static std::unordered_map<char, std::pair<int, int>> KEY_MAP;

    Position move(Position position);
    Position getHeadPosition();
    std::vector<Position>& getBodies() {return bodies;};
    std::unordered_set<Position, Position>& getBodySet() {return bodySet;};
};

#endif //SNAKE_SNAKE_H
