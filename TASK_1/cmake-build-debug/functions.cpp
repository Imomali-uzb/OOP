#include <iostream>
#include "header.h"

using namespace std;

namespace header {
    int getRowNum() {
        const char* error_message = "";
        int m;
        do {
            cout << error_message << std::endl;
            std::cout << "Enter number of rows: ";
            error_message = "You are wrong! Please, repeat!";
            if (getNum(m) < 0)
                return -1;
        } while (m < 1);
        return m;
    }
    int getColNum() {
        const char* error_message = "";
        int m;
        do {
            std::cout << error_message << std::endl;
            std::cout << "Enter number of columns: ";
            error_message = "You are wrong! Please, repeat!";
            if (getNum(m) < 0)
                return -1;
        } while (m < 1);
        return m;
    }

    Line* input(Line* firstLine, int column, int row) {
        int x, y, value;
        Line* newLine = nullptr;
        Line* tmpLine = nullptr;
        Item* newItem = nullptr;
        Item* tmpItem = nullptr;
        const char* error_message = "";

        std::cout << "Enter number of line --> ";
        do {
            std::cout << error_message << std::endl;
            error_message = "You are wrong! Please, repeat!";
            if (getNum(y) < 0)
                return nullptr;
        } while (y < 0 || y > column);

        error_message = "";
        std::cout << "Enter number of column --> ";
        do {
            std::cout << error_message << std::endl;
            error_message = "You are wrong! Please, repeat!";
            if (getNum(x) < 0)
                return nullptr;
        } while (x < 0 || x > row);

        error_message = "";
        std::cout << "Enter value of cell --> ";
        do {
            std::cout << error_message << std::endl;
            error_message = "You are wrong! Please, repeat!";
            if (getNum(value) < 0)
                return nullptr;
        } while (value < 1);
        newItem = new Item;
        newItem->next = nullptr;
        newItem->numColumn = x;
        newItem->value = value;
        if (firstLine == nullptr) {
            newLine = new Line;
            newLine->next = nullptr;
            newLine->numLine = y;
            newLine->a = newItem;
            firstLine = newLine;
            return firstLine;
        }
        else {
            tmpLine = firstLine;

            if (y < tmpLine->numLine) {
                newLine = new Line;
                newLine->numLine = y;
                newLine->a = newItem;
                newLine->next = firstLine;
                firstLine = newLine;
            }

            else if (y == tmpLine->numLine) {
                if (x < tmpLine->a->numColumn) {
                    newItem->next = tmpLine->a;
                    tmpLine->a = newItem;
                }
                else if (x == tmpLine->a->numColumn)
                    std::cout << "Coordinates are doubled! Cannot allocate memory in one place!" << std::endl;
                else {
                    tmpItem = tmpLine->a;
                    while (tmpItem->next != nullptr) {
                        if (tmpItem->next->numColumn > x) {
                            newItem->next = tmpItem->next;
                            tmpItem->next = newItem;
                            return firstLine;
                        }
                        else if (tmpItem->next->numColumn == x) {
                            std::cout << "Coordinates are doubled! Cannot allocate memory in one place!" << std::endl;
                            return firstLine;
                        }
                        tmpItem = tmpItem->next;
                    }
                    tmpItem->next = newItem;
                }
            }

            else {
                while (tmpLine->next != nullptr) {
                    if (tmpLine->next->numLine > y) {
                        newLine = new Line;
                        newLine->numLine = y;
                        newLine->a = newItem;
                        newLine->next = tmpLine->next;
                        tmpLine->next = newLine;
                        break;
                    }
                    else if (tmpLine->next->numLine == y) {
                        if (x < tmpLine->next->a->numColumn) {
                            newItem->next = tmpLine->next->a;
                            tmpLine->next->a = newItem;
                            break;
                        }
                        else if (x == tmpLine->next->a->numColumn){
                            std::cout << "Coordinates are doubled! Cannot allocate memory in one place!" << std::endl;
                            break;
                        }
                        else {
                            tmpItem = tmpLine->next->a;
                            while (tmpItem->next != nullptr) {
                                if (tmpItem->next->numColumn > x) {
                                    newItem->next = tmpItem->next;
                                    tmpItem->next = newItem;
                                    return firstLine;
                                }
                                else if (tmpItem->next->numColumn == x) {
                                    std::cout << "Coordinates are doubled! Cannot allocate memory in one place!" << std::endl;
                                    return firstLine;
                                }
                                tmpItem = tmpItem->next;
                            }
                            tmpItem->next = newItem;
                            break;
                        }
                    }
                    tmpLine = tmpLine->next;
                }
                newLine = new Line;
                newLine->numLine = y;
                newLine->a = newItem;
                newLine->next = nullptr;
                tmpLine->next = newLine;
            }
        }
        return firstLine;
    }

    void menu_(Line* firstLine, int m, int n) {
        int a, b;
        const char* error_message = "";
        do {
            std::cout << "Commands:" << std::endl;
            std::cout << "1. Add element" << std::endl;
            std::cout << "2. Show elements" << std::endl;
            std::cout << "0. Quit" << std::endl;
            do {
                std::cout << error_message << std::endl;
                error_message = "You are wrong! Please, repeat!";
                if (getNum(a) < 0)
                    return;
            } while (a < 0 || a > 2);
            switch (a) {
                case 1: firstLine = input(firstLine, m, n);
                    break;
                case 2: output("Matrix", firstLine);
                    break;
                case 0: return;
            }
            std::cout << "Do you want to continue!?\t0--No 1--Yes\n";
            error_message = "";
            do {
                std::cout << error_message << std::endl;
                error_message = "You are wrong! Please, repeat!";
                if (getNum(b) < 0)
                    return;
            } while (b < 0 || b > 1);
            error_message = "";
        } while (b == 1);
    }

    void output(const char* msg, Line* firstLine) {
        Line* tmp;
        Item* tempItem;
        tmp = firstLine;
        if (tmp == nullptr) {
            std::cout << "Matrix is empty!" << std::endl;
            return;
        }
        std::cout << msg << ":" << std::endl;
        while (tmp != nullptr) {
            std::cout << "#" << tmp->numLine << ": ";
            tempItem = tmp->a;
            while (tempItem != nullptr) {
                std::cout << "--> (x: " << tempItem->numColumn << "value: " << tempItem->value << ")";
                tempItem = tempItem->next;
            }
            std::cout << std::endl;
            tmp = tmp->next;
        }
    }

    Line* erase(Line* firstLine) {
        if (firstLine == nullptr)
            return nullptr;
        while (firstLine != nullptr) {
            firstLine = firstLine->next;
            delete firstLine;
        }
        delete firstLine;
        return nullptr;
    }
}

