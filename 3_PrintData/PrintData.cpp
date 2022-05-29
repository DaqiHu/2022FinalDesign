//
// Created by AiEnigma on 5/24/2022.
//

#include "PrintData.h"

//显示标题：0为员工信息，1为销售经理信息
void PrintData::displayBanner(int m) {
    system("CLS");
    auto msg = new Message;
    cout << msg->show(m == 0 ? "PrintStaff" : "PrintSalesManager") << endl
         << endl
         << msg->show(m == 0 ? "PrintStaffBanner" : "PrintSalesManagerBanner")
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
    auto d = new Data;
    d->show();
    delete d;
}

void PrintData::printSalesManager() {
    auto d = new Data;
    float total = 0.0;
    total = d->showSalesManager();
    delete d;

    auto msg = new Message;
    cout << msg->show("PrintSalesManagerHimself") << ' ' << total <<endl;
    delete msg;
}