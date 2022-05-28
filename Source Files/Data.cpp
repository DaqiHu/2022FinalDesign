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

//增 insert 重载
void Data::insert(const Employee &staff) {
    vec_staffList.push_back(staff);
}

void Data::insert(const Engineer &staff) {
    vec_staffList.push_back(staff);
    vec_engineerList.push_back(staff);
}

void Data::insert(const Manager &staff) {
    vec_staffList.push_back(staff);
    vec_managerList.push_back(staff);
}

void Data::insert(const SalesPerson &staff) {
    vec_staffList.push_back(staff);
    vec_salesPersonList.push_back(staff);
}

void Data::insert(const SalesManager &staff) {
    vec_staffList.push_back(staff);
    vec_salesManagerList.push_back(staff);
}

//删 待开发
void Data::erase(const Employee &staff) {

}

//改 待开发
void Data::update(const Employee &staff) {

}

//查 find 重载
auto Data::find(const Employee &staff) {
    //return find_if(vec_staffList.begin(), vec_staffList.end(), staff.salary());
}

auto Data::find(const Engineer &staff) {}

auto Data::find(const Manager &staff) {}

auto Data::find(const SalesPerson &staff) {

}

auto Data::find(const SalesManager &staff) {}

//排序规则
bool rule(const Employee &first, const Employee &second) {
    return first.salary() >= second.salary();    //按工资从高到低排序
}

//排序
void Data::sort(vector<Employee> &vec) {
    std::sort(vec.begin(), vec.end(), rule);
}

//排序后输出
void Data::sortAndShow(vector<Employee> vec) {
    sort(vec);      //排序
    show(vec);      //输出
}

//输出
void Data::show(vector<Employee> &vec) {
    const char tab = '\t';    //间隔符
    int i = 0;                //计次
    //输出
    for (auto &iter: vec)
        //职工号		姓名		性别		年龄		职位		工资		位次
        cout << iter.id() << tab << iter.name() << tab << iter.sex() << tab << iter.age() << tab << iter.post() << tab
             << iter.salary() << tab << ++i << endl;
}

//获取数据成员
vector<Employee> &Data::staffList() {
    return vec_staffList;
}

vector<Engineer> &Data::engineerList() {
    return vec_engineerList;
}

vector<Manager> &Data::managerList() {
    return vec_managerList;
}

vector<SalesPerson> &Data::salesPersonList() {
    return vec_salesPersonList;
}

vector<SalesManager> &Data::salesManagerList() {
    return vec_salesManagerList;
}

ostream &operator<<(ostream &os, const vector<Employee> &vec) {
    const char tab = ' ';
    for (auto &iter: vec)
        os << iter << tab;
    return os;
}

ostream &operator<<(ostream &os, const vector<Engineer> &vec) {
    const char tab = ' ';
    for (auto &iter: vec)
        os << iter << tab;
    return os;
}

ostream &operator<<(ostream &os, const vector<Manager> &vec) {
    const char tab = ' ';
    for (auto &iter: vec)
        os << iter << tab;
    return os;
}

ostream &operator<<(ostream &os, const vector<SalesPerson> &vec) {
    const char tab = ' ';
    for (auto &iter: vec)
        os << iter << tab;
    return os;
}

ostream &operator<<(ostream &os, const vector<SalesManager> &vec) {
    const char tab = ' ';
    for (auto &iter: vec)
        os << iter << tab;
    return os;
}

//ostream &operator<<(ostream &os, const Data &data) {
//    const char tab = ' ';
//    os << data.vec_staffList << tab
//       << data.vec_engineerList << tab
//       << data.vec_managerList << tab
//       << data.vec_salesPersonList << tab
//       << data.vec_salesManagerList;
//    return os;
//}

istream &operator>>(istream &is, vector<Employee> &vec) {
    Employee emp;
    while (is >> emp) {
        vec.emplace_back(emp);
    }
    return is;
}

istream &operator>>(istream &is, vector<Engineer> &vec) {
    Engineer eng;
    while (is >> eng) {
        vec.emplace_back(eng);
    }
    return is;
}

istream &operator>>(istream &is, vector<Manager> &vec) {
    Manager mang;
    while (is >> mang) {
        vec.emplace_back(mang);
    }
    return is;
}

istream &operator>>(istream &is, vector<SalesPerson> &vec) {
    SalesPerson sp;
    while (is >> sp) {
        vec.emplace_back(sp);
    }
    return is;
}

istream &operator>>(istream &is, vector<SalesManager> &vec) {
    SalesManager sm;
    while (is >> sm) {
        vec.emplace_back(sm);
    }
    return is;
}

//保存数据
void Data::save() {
    ofstream outFile("data.dat", ios::out);

    const char tab = ' ';
    outFile << vec_staffList << tab
            << vec_engineerList << tab
            << vec_managerList << tab
            << vec_salesPersonList << tab
            << vec_salesManagerList;
    outFile.close();                         //关闭文件
    cout << msg.show("Saved") << endl;  //输出：数据已保存
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
    cout << msg.show("Loaded") << endl; //输出：数据已载入
}

//删除数据
void Data::erase() {
    cout << msg.show("Deleted") << endl; //输出：数据已删除
}
