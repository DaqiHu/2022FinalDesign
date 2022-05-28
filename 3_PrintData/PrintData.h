//
// Created by AiEnigma on 5/24/2022.
//

#ifndef INC_2022FINALDESIGN_PRINTDATA_H
#define INC_2022FINALDESIGN_PRINTDATA_H

#include <iostream>
#include <vector>

#include "../Headers/Employee.h"

using namespace std;

class PrintData {
public:
    //构造析构
    static void print();
private:
    static void displayBanner(int m);
    static void printStaff();
    static void printSalesManager();
    static Message msg;
};

#endif //INC_2022FINALDESIGN_PRINTDATA_H
