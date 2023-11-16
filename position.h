#ifndef SNAKE_POSITION_H
#define SNAKE_POSITION_H

#include <random>

class Position {
private:
    int x;
    int y;

    // random
    static std::mt19937 GEN;

public:
    Position(int x, int y): x(x), y(y){};
    Position() = default;
    ~Position() = default;

    int getX() const{return x;};
    int getY() const{return y;};

    static Position generateRandom(int sizeX, int sizeY);

    bool operator==(const Position & another) const;

    // 自定义哈希函数
    size_t operator()(const Position& p) const {
        // 你可以根据需要定义一种哈希算法
        return std::hash<int>()(p.x) ^ std::hash<int>()(p.y);
    };
};

#endif //SNAKE_POSITION_H
