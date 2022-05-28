//
// Created by AiEnigma on 5/24/2022.
//

#ifndef INC_2022FINALDESIGN_MESSAGE_H
#define INC_2022FINALDESIGN_MESSAGE_H

#include <map>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Message {
public:
    //构造析构
    Message();
    string show(const string &key);    //返回信息
private:
    map<string, string> MESSAGE;
};

#endif //INC_2022FINALDESIGN_MESSAGE_H
