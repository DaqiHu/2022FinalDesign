//
// Created by AiEnigma on 5/24/2022.
//

#include "Exit.h"

//退出系统
void Exit::exitSystem() {
    system("CLS");    //清屏
    cout << "已自动保存。" << endl;
    cout << "感谢您使用本系统。" << endl;    //结束语
    exit(0);    //退出系统
}