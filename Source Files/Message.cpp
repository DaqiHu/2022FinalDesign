//
// Created by AiEnigma on 5/24/2022.
//

#include "../Headers/Message.h"

//构造函数
Message::Message() {
    ifstream inFile;
    inFile.open("message.txt", ios::in);    //以只读形式打开 message.txt

    //打开失败报错
    if (!inFile.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }

    //读取txt 内容到 Message 类
    string key, value;
    while (inFile >> key >> value) {
        MESSAGE[key] = value;
    }

    inFile.close();    //关闭文件
}

//返回文本
string Message::show(const string &key) {
    return MESSAGE[key];    //返回 key 所对的 value
}