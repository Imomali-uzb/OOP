//
// Created by NEW on 08.10.2021.
//

#ifndef LAB1_HEADER_H
#define LAB1_HEADER_H

#pragma once
namespace header {
    typedef struct Item {
        int numColumn;
        int value;
        struct Item* next;
    } Item;
    typedef struct Line {
        int numLine;
        struct Item* a;
        struct Line* next;
    } Line;

    template <class T>
    int getNum(T& a) {
        std::cin >> a;
        if (!std::cin.good())
            return -1;
        return 1;
    }

    int getRowNum();
    int getColNum();
    void menu_(Line*, int, int);
    Line* input(Line*, int, int);
    void output(const char*, Line*);
    Line* erase(Line*);
}

#endif //LAB1_HEADER_H
