//
// Created by AiEnigma on 5/24/2022.
//
#include "SortData.h"

void SortData::sort() {
    displayBanner();    //显示横幅
    auto d = new Data;  //new 数据对象
    d->sort();   //排序并显示
    delete d;           //delete 数据对象
}

//显示
void SortData::displayBanner() {
    cout << "以下是排序: " << endl
         << endl
         << "职工号\t姓名\t性别\t年龄\t职位\t工资\t排名" << endl
         << "---------------------------------------------------------------" << endl;
}