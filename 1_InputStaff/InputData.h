#ifndef INC_2022FINALDESIGN_INPUTDATA_H
#define INC_2022FINALDESIGN_INPUTDATA_H

#include <string>

#include "../Headers/Data.h"

using namespace std;

class InputData {
public:
    void input();   //输入各项数据
    void save();    //保存数据

private:
    Message msg;
};

#endif //INC_2022FINALDESIGN_INPUTDATA_H
