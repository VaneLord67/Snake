#include <iostream>
#include "map.h"
#include "main.h"
#include <termios.h>
#include <unistd.h>

int main() {
    printMenu();
    setBufferedIO(false); // 禁用缓冲输入
    while (getchar() != '\n'); // 等待输入enter
    clear();
    Map m(5, 5);
    int move_state;
    do {
        m.print();
        char key = getUserInput();
        move_state = m.moveSnake(key);
        clear();
    } while (move_state == Map::MOVE_SUCCESS);
    clear();
    switch (move_state) {
        case Map::MOVE_WIN:
            std::cout << "游戏胜利" << std::endl;
            break;
        case Map::MOVE_DEAD:
            std::cout << "游戏失败" << std::endl;
            break;
        default:
            throw std::invalid_argument("invalid move_state");
    }
    setBufferedIO(true); // 恢复输入，不然终端会出现敲击命令没回显的情况
    return 0;
}

void printMenu() {
    using namespace std;
    cout << "==============================" << endl;
    cout << "      欢迎来到贪吃蛇游戏      " << endl;
    cout << "==============================" << endl;
    cout << "按 Enter 键开始游戏..." << endl;
}

// 函数定义：启用或禁用输入缓冲
void setBufferedIO(bool enableBuffering) {
    struct termios t{};
    tcgetattr(STDIN_FILENO, &t);

    if (enableBuffering) {
        t.c_lflag |= ICANON | ECHO;
    } else {
        t.c_lflag &= ~(ICANON | ECHO);
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void clear() {
    // std::cout << "\033[2J\033[1;1H"; // 使用ANSI转义码清空屏幕
    system("clear");
}

char getUserInput() {
    struct termios oldt{}, newt{};
    char ch;

    // 获取当前终端设置
    tcgetattr(STDIN_FILENO, &oldt);

    // 设置终端为不回显、无缓冲输入模式
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // 从标准输入读取一个字符
    std::cin >> ch;

    // 恢复终端设置
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}