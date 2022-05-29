//
// Created by AiEnigma on 5/24/2022.
//

#include "../Headers/Data.h"

//构造
Data::Data() {
    load();
}

//析构
Data::~Data() {
    save();
}

//排序规则
bool rule(const Employee &first, const Employee &second) {
    return first.salary() >= second.salary();    //按工资从高到低排序
}

//排序
void Data::sort() {
    //生成完整员工列表
    for (auto &iter: vec_engineerList)
        vec_staffList.emplace_back(iter);
    for (auto &iter: vec_managerList)
        vec_staffList.emplace_back(iter);
    for (auto &iter: vec_salesPersonList)
        vec_staffList.emplace_back(iter);
    for (auto &iter: vec_salesManagerList)
        vec_staffList.emplace_back(iter);

    std::sort(vec_staffList.begin(), vec_staffList.end(), rule);
}

//输出
void Data::show() {
    const char tab = '\t';    //间隔符
    int i = 0;                //计次
    //输出
    for (auto &iter: vec_staffList)
        //职工号		姓名		性别		年龄		职位		工资		位次
        cout << iter.id() << tab << iter.name() << tab << iter.sex() << tab << iter.age() << tab << iter.post() << tab
             << iter.salary() << tab << ++i << endl;
}

//输出销售经理和各销售员
float Data::showSalesManager() {
    const char tab = '\t';
    float total = 0.0;
    for (auto &iter: vec_salesPersonList) {
        cout << iter.id() << tab << iter.name() << tab << iter.sales() << endl;
        total += iter.sales();
    }
    return total;   //返回销售额总额
}

//排序后输出
void Data::sortAndShow() {
    sort();      //排序
    show();      //输出
}

////获取数据成员
//vector<Employee> &Data::staffList() {
//    return vec_staffList;
//}
//
//vector<Engineer> &Data::engineerList() {
//    return vec_engineerList;
//}
//
//vector<Manager> &Data::managerList() {
//    return vec_managerList;
//}
//
//vector<SalesPerson> &Data::salesPersonList() {
//    return vec_salesPersonList;
//}
//
//vector<SalesManager> &Data::salesManagerList() {
//    return vec_salesManagerList;
//}

//保存数据
void Data::save() const {
    ofstream outFile("data.dat", ios::out);

    const char tab = ' ';
    outFile << vec_staffList << tab
            << vec_engineerList << tab
            << vec_managerList << tab
            << vec_salesPersonList << tab
            << vec_salesManagerList;
    outFile.close();                         //关闭文件

    auto msg = new Message;
    cout << msg->show("Saved") << endl;  //输出：数据已保存
    delete msg;
}

//载入数据
void Data::load() {
    //读取数据
    ifstream inFile("data.dat", ios::in);

    //是否正常打开数据文件
    if (!inFile.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }
    inFile >> vec_staffList
           >> vec_engineerList
           >> vec_managerList
           >> vec_salesPersonList
           >> vec_salesManagerList;
    inFile.close();                          //关闭文件

    //设置并更新销售经理数据
    float total = 0.0;  //所属部门销售额总额
    for (auto &iter: vec_salesPersonList)
        total += iter.sales();  //累加销售员的销售额
    for (auto &iter: vec_salesManagerList)
        iter.setSalesTotal(total);  //设置销售经理的数据

    //确认信息
    auto msg = new Message;
    cout << msg->show("Loaded") << endl; //输出：数据已载入
    delete msg;
}

//删除数据
void Data::erase() {
    auto msg = new Message;
    cout << msg->show("Deleted") << endl; //输出：数据已删除
    delete msg;
}
