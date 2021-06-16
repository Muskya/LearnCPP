#pragma once
#include <iostream>
#include <string>

void displayTab(int* tab, int tsize, std::string name) {
    std::cout << "\n" << name << ":\n"; //security lnjump
    for (int i = 0; i < tsize; i++) {
        std::cout << tab[i] << std::endl;
    }
}

void bubbleSortTab(int* tabA, int ABs) {
    int swaps, tmp;
    do { 
        swaps = 0; 
        for (int i = 0; i < ABs - 1; i++) {
            if (tabA[i] > tabA[i + 1]) {
                tmp = tabA[i]; tabA[i] = tabA[i + 1]; tabA[i + 1] = tmp;
                swaps++;
            }
        }
    } while (swaps != 0);
}