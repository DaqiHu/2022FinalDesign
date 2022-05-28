//
// Created by AiEnigma on 5/24/2022.
//
#include "SortData.h"

void SortData::sort() {
    sl.load();
    displayBanner();
    Data::sortAndShow(data.staffList());
}

//显示
void SortData::displayBanner() {
    cout << "以下是排序: " << endl
         << endl
         << "职工号\t姓名\t性别\t年龄\t职位\t工资\t排名" << endl
         << "---------------------------------------------------------------" << endl;
}