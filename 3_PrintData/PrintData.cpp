//
// Created by AiEnigma on 5/24/2022.
//

#include "PrintData.h"

//显示标题：0为员工信息，1为销售经理信息
void PrintData::displayBanner(int m) {
    system("CLS");
    cout << msg.show(m == 0 ? "PrintStaff" : "PrintSalesManager") << endl
         << endl
         << msg.show(m == 0 ? "PrintStaffBanner" : "PrintSalesManagerBanner")
         << "----------------------------------------------" << endl;
}

void PrintData::print() {
    displayBanner(0);
    printStaff();
    cout << endl << endl;
    displayBanner(1);
    printSalesManager();
}

void PrintData::printStaff() {
    extern vector<Employee> staffList;    //声明全局变量
    const char tab = '\t';

    //循环输出
    for (auto &iter: staffList)
        cout << iter.id() << tab << iter.name() << tab << iter.sex() << tab << iter.age() << tab << iter.post() << tab
             << iter.salary() << endl;
}

void PrintData::printSalesManager() {

}