//
// Created by AiEnigma on 5/24/2022.
//

#include "InputData.h"

//循环计数器（以后可以用全局静态变量实现） static int count = 0;
int InputData::loopCount() {
    int count;
    cout << "请输入本次录入成员个数：" << endl;
    cin >> count;
    return count;
}

//获取岗位信息
void InputData::getPost() {
    system("CLS");
    cout << "请输入员工岗位：（支持模糊输入）" << endl;
    string post;
    while (cin >> post) {
        if (post == "技术员") {
            getStaff(1);
            break;
        } else if (post == "经理") {
            getStaff(2);
            break;
        } else if (post == "销售员") {
            getStaff(3);
            break;
        } else if (post == "销售经理") {
            getStaff(4);
            break;
        } else {
            if (post == "经理") {
                cout
                        << "输入1 以经理岗位继续..." << endl
                        << "输入2 以销售经理岗位继续..." << endl
                        << endl
                        << "输入0 重新输入岗位信息..."
                        << endl;

                int temp;
                cin >> temp;
                switch (temp) {
                    case 1:
                        getStaff(2);
                        break;
                    case 2:
                        getStaff(4);
                        break;
                    case 0:
                        cout << "请输入员工岗位：（支持模糊输入）" << endl;
                        break;
                    default:
                        cout << "请输入员工岗位：（支持模糊输入）" << endl;
                        break;
                }
            } else if (post == "销售") {
                cout
                        << "输入1 以销售员岗位继续..." << endl
                        << "输入2 以销售经理岗位继续..." << endl
                        << endl
                        << "输入0 重新输入岗位信息..."
                        << endl;

                int temp;
                cin >> temp;
                switch (temp) {
                    case 1:
                        getStaff(3);
                        break;
                    case 2:
                        getStaff(4);
                        break;
                    case 0:
                        break;
                    default:
                        break;
                }
            } else if (post == "技术") {
                cout
                        << "输入1 以技术员岗位继续..." << endl
                        << endl
                        << "输入0 重新输入岗位信息..."
                        << endl;

                int temp;
                cin >> temp;
                switch (temp) {
                    case 1:
                        getStaff(1);
                        break;
                    case 0:
                        break;
                    default:
                        break;
                }
            } else {
                cout << "您的输入有误，请重新输入..." << endl;
            }
        }
    }
}

//显示岗位-输入提示
void InputData::showPost() {

}

//显示员工信息-输入提示
void InputData::showStaff(unsigned int post) {
    cout << "您正在输入 ";

    switch (post) {
        case 0:
            cout << msg.show("Post0");
            break;    //未知
        case 1:
            cout << msg.show("Post1");
            break;    //技术员
        case 2:
            cout << msg.show("Post2");
            break;    //经理
        case 3:
            cout << msg.show("Post3");
            break;    //销售员
        case 4:
            cout << msg.show("Post4");
            break;    //销售经理
        default:
            break;
    }
    cout << " 员工信息：" << endl
         << "请按照以下提示依次输入..." << endl
         << "------------------------------" << endl
         << "职工号\t姓名\t性别\t年龄\t工作时长" << endl
         << endl;
}

//获取员工信息
void InputData::getStaff(unsigned int post) {
    //显示
    showStaff(post);

    string id;                //职工号
    string name;            //姓名
    char sex;                //性别
    unsigned int age;        //年龄
    float time;                //工作时长
    float sales;            //销售额
    float salesTotal = 0.0;    //所辖部门销售额总额

    //销售经理
    if (post == 4) {
        //累加总销售额
        for (auto &iter: staff.salesPersonList()) {
            salesTotal += iter.sales();
        }
    }

    cin >> id >> name >> sex >> age >> time >> sales;
    switch (post) {
        case 0:
            staff.insert(Employee{id, name, sex, age, 0, 0.0});
            break;
        case 1:
            staff.insert(Engineer{id, name, sex, age, time, 0.0});
            break;
        case 2:
            staff.insert(Manager{id, name, sex, age, 0.0, 0.0});
            break;
        case 3:
            staff.insert(SalesPerson{id, name, sex, age, 0.0, sales});
            break;
        case 4:
            staff.insert(SalesManager{id, name, sex, age, 0.0, salesTotal});
            break;
        default:
            break;
    }
}

void InputData::input() {
    int k = loopCount();
    while (k--) {
        getPost();
    }
    SaveData::save();
}

void InputData::save() {

}
