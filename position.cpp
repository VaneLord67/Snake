#include "position.h"


std::mt19937 Position::GEN = std::mt19937(std::random_device()());

Position Position::generateRandom(int sizeX, int sizeY) {
    std::uniform_int_distribution<int> disX(0, sizeX - 1); // 左闭右闭
    std::uniform_int_distribution<int> disY(0, sizeY - 1); // 左闭右闭
    int randomX = disX(GEN);
    int randomY = disY(GEN);
    return {randomX, randomY};
}

bool Position::operator==(const Position &another) const {
    return this->getX() == another.getX() && this->getY() == another.getY();
}
