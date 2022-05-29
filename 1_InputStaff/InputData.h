#ifndef INC_2022FINALDESIGN_INPUTDATA_H
#define INC_2022FINALDESIGN_INPUTDATA_H

#include <string>

#include "../Headers/Data.h"

using namespace std;

class InputData {
public:
    void input();   //输入各项数据

private:
    static void showStaff(unsigned int post);
    void getStaff(unsigned int post);
    void getPost();
    Data data;
};

#endif //INC_2022FINALDESIGN_INPUTDATA_H
