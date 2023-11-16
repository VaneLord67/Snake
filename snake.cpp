#include "snake.h"

Snake::Snake(Position position) {
    bodies.push_back(position);
    bodySet.insert(position);
}

std::pair<int, int> Snake::key2dxy(char key) {
    auto it = Snake::KEY_MAP.find(key);
    if (it != Snake::KEY_MAP.end()) {
        return it->second;
    }
    throw std::invalid_argument("invalid key");
}

const std::unordered_map<char, std::pair<int, int>> Snake::KEY_MAP = {
    {'w', std::pair<int, int>(-1, 0)},
    {'a', std::pair<int, int>(0, -1)},
    {'s', std::pair<int, int>(1, 0)},
    {'d', std::pair<int, int>(0, 1)},
};

Position Snake::getHeadPosition() {
    return bodies.front();
}

Position Snake::move(Position position) {
    bodySet.insert(position);
    bodies.insert(bodies.begin(), position);
    Position ret = bodies.back();
    bodies.pop_back();
    bodySet.erase(ret);
    return ret;
}
