//
// Created by AiEnigma on 5/24/2022.
//

#include "SaveData.h"

void SaveData::load() {

    ifstream inFile;                    //从文件读取
    inFile.open("data.dat", ios::in);    //数据文件名

    //失败检测
    if (!inFile.is_open()) {
        cout << "Error opening file";
        exit(1);
    }

    string id;
    string name;
    char sex;
    unsigned int age;
    unsigned int post;
    float salary;

    //循环输入
    while (inFile >> id >> name >> sex >> age >> post >> salary) {
        staffList.emplace_back(id, name, sex, age, post, salary);
    }   //为什么要用 emplace_back 代替 push_back？

    inFile.close();
    cout << "已读取数据" << endl;
}

void SaveData::save() {

    ofstream outFile;                    //输出到文件
    outFile.open("data.dat", ios::out);    //输出数据文件名
    const char tab = ' ';

    //循环输出

/*
    for (auto &iter: staffList)
        outFile << iter.id() << tab << iter.name() << tab << iter.sex() << tab << iter.age() << tab << iter.post()
                << tab << iter.salary() << endl;
    for (auto &iter: engineerList)
        outFile << iter.id() << tab << iter.name() << tab << iter.sex() << tab << iter.age() << tab << iter.post()
                << tab << iter.salary() << endl;
    for (auto &iter: managerList)
        outFile << iter.id() << tab << iter.name() << tab << iter.sex() << tab << iter.age() << tab << iter.post()
                << tab << iter.salary() << endl;
    for (auto &iter: salesPersonList)
        outFile << iter.id() << tab << iter.name() << tab << iter.sex() << tab << iter.age() << tab << iter.post()
                << tab << iter.salary() << endl;
    for (auto &iter: salesManagerList)
        outFile << iter.id() << tab << iter.name() << tab << iter.sex() << tab << iter.age() << tab << iter.post()
                << tab << iter.salary() << endl;
*/

    outFile.close();
    cout << "数据已保存." << endl;
}

void SaveData::erase() {
    ofstream deleteFile;
    deleteFile.open("data.dat", ios::trunc);    //删除数据
    deleteFile.close();

    cout << "数据已删除" << endl;
}