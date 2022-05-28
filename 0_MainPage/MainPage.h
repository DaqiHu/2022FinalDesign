//
// Created by AiEnigma on 5/24/2022.
//

#ifndef INC_2022FINALDESIGN_MAINPAGE_H
#define INC_2022FINALDESIGN_MAINPAGE_H


#include "../1_InputStaff/InputData.h"
#include "../2_SortData/SortData.h"
#include "../3_PrintData/PrintData.h"
#include "../4_SaveToFile/SaveData.h"
#include "../5_ExitSystem/Exit.h"
#include <iostream>

using namespace std;

class MainPage {
public:
    [[noreturn]] static void menu();
};

#endif //INC_2022FINALDESIGN_MAINPAGE_H
