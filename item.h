#ifndef SNAKE_ITEM_H
#define SNAKE_ITEM_H

#include <utility>
#include "position.h"

class Item {
private:
    Position position;

public:
    explicit Item(Position position): position(position){};
    Item() = default;
    ~Item() = default;

    const Position& getPosition() const{return position;};
};

#endif //SNAKE_ITEM_H
