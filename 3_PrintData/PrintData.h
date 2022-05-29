//
// Created by AiEnigma on 5/24/2022.
//

#ifndef INC_2022FINALDESIGN_PRINTDATA_H
#define INC_2022FINALDESIGN_PRINTDATA_H

#include <iostream>
#include <vector>

#include "../Headers/Employee.h"
#include "../Headers/Data.h"

using namespace std;

class PrintData {
public:
    static void print();

private:
    static void displayBanner(int m);

    static void printStaff();

    static void printSalesManager();
};

#endif //INC_2022FINALDESIGN_PRINTDATA_H
