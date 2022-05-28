//
// Created by AiEnigma on 5/24/2022.
//

#include "MainPage.h"

void displayBanner() {
    cout << "--------------------------------------------" << endl
         << endl
         << "              欢迎使用本系统" << endl
         << endl
         << "--------------------------------------------" << endl;
}

void displayMainPage() {
    cout << endl
         << "1. 输入数据" << endl
         << "2. 数据统计" << endl
         << "3. 数据打印" << endl
         << "4. 数据备份" << endl
         << "5. 退出系统" << endl
         << endl
         << "请输入数字...";
}

void selectFunction() {
    int key = 0;
    cin >> key;
    switch (key) {
        case 0:
            break;
        case 1: {
            auto p = new InputData;
            p->input();
            delete p;
            break;
        }
        case 2:{
            auto p = new SortData;
            p->sort();
            delete p;
            break;
        }
        case 3:
            PrintData::print();
            break;
        case 4:
            SaveData::save();
            break;
        case 5:
            Exit::exitSystem();
            break;
        default:
            break;
    }
}

[[noreturn]] void MainPage::menu() {
    SaveData::load();
    displayBanner();
    while (true) {
        displayMainPage();
        selectFunction();
    }
}
