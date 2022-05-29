#include"../Headers/Employee.h"

const char tab = ' ';

//获取职工号
string Employee::id() {
    return str_id;
}

//获取姓名
string Employee::name() {
    return str_name;
}

//获取年龄
unsigned int Employee::age() const {    //为什么设计成 const 型
    return ui_age;
}

//获取薪水
float Employee::salary() const {
    return f_salary;
}

//获取性别
string Employee::sex() const {
    return (c_sex == 'm') ? "男" : "女";
}

//获取岗位
string Employee::post() {
    switch (ui_post) {
        case 0:
            return msg.show("PostUnknown");
        case 1:
            return msg.show("PostEngineer");
        case 2:
            return msg.show("PostManager");
        case 3:
            return msg.show("PostSalesPerson");
        case 4:
            return msg.show("PostSalesManager");
        default:
            return "";
    }
}

ostream &operator<<(ostream &os, const Employee &emp) {
    os << emp.str_id << tab << emp.str_name << tab << emp.c_sex << tab << emp.ui_age << tab << emp.ui_post << tab
       << emp.f_salary << endl;
    return os;
}

istream &operator>>(istream &is, Employee &emp) {
    is >> emp.str_id >> emp.str_name >> emp.c_sex >> emp.ui_age >> emp.ui_post >> emp.f_salary;
    return is;
}

//---------------------------技术员-------------------------------

//构造函数
Engineer::Engineer() {
    ui_post = 1;
    cout << msg.show("InputPostEngineerSuccess") << endl;
}

//获取工作时长
float Engineer::hour() const {
    return f_hour;
}

ostream &operator<<(ostream &os, const Engineer &eng) {
    os << eng.str_id << tab << eng.str_name << tab << eng.c_sex << tab << eng.ui_age << tab << eng.ui_post << tab
       << eng.f_salary << tab << eng.f_hour << endl;
    return os;
}

istream &operator>>(istream &is, Engineer &eng) {
    is >> eng.str_id >> eng.str_name >> eng.c_sex >> eng.ui_age >> eng.ui_post >> eng.f_salary >> eng.f_hour;
    eng.f_salary = hourSalary * eng.f_hour;
    return is;
}

//---------------------------经理-------------------------------

//构造函数
Manager::Manager() {
    ui_post = 2;
    cout << msg.show("InputPostManagerSuccess") << endl;
}

ostream &operator<<(ostream &os, const Manager &mang) {
    os << mang.str_id << tab << mang.str_name << tab << mang.c_sex << tab << mang.ui_age << tab << mang.ui_post << tab
       << mang.f_salary << endl;
    return os;
}

istream &operator>>(istream &is, Manager &mang) {
    is >> mang.str_id >> mang.str_name >> mang.c_sex >> mang.ui_age >> mang.ui_post >> mang.f_salary;
    mang.f_salary = staticSalary;
    return is;
}

//---------------------------销售员-------------------------------

//构造函数
SalesPerson::SalesPerson() {
    ui_post = 3;
    cout << msg.show("InputPostSalesPersonSuccess") << endl;
}

//获取销售额
float SalesPerson::sales() const {
    return f_sales;
}

ostream &operator<<(ostream &os, const SalesPerson &sp) {
    os << sp.str_id << tab << sp.str_name << tab << sp.c_sex << tab << sp.ui_age << tab << sp.ui_post << tab
       << sp.f_salary << tab << sp.f_sales << endl;
    return os;
}

istream &operator>>(istream &is, SalesPerson &sp) {
    is >> sp.str_id >> sp.str_name >> sp.c_sex >> sp.ui_age >> sp.ui_post >> sp.f_salary >> sp.f_sales;
    sp.f_salary = sp.f_sales * bonusRate;
    return is;
}

//---------------------------销售经理-------------------------------

//构造函数
SalesManager::SalesManager() {
    ui_post = 4;
    cout << msg.show("InputPostSalesManagerSuccess") << endl;
}

//获取销售额总额
float SalesManager::salesTotal() const {
    return f_salesTotal;
}

void SalesManager::setSalesTotal(float total) {
    f_salesTotal = total;
}

ostream &operator<<(ostream &os, const SalesManager &sm) {
    os << sm.str_id << tab << sm.str_name << tab << sm.c_sex << tab << sm.ui_age << tab << sm.ui_post << tab
       << sm.f_salary << tab << sm.f_salesTotal << endl;
    return os;
}

istream &operator>>(istream &is, SalesManager &sm) {
    is >> sm.str_id >> sm.str_name >> sm.c_sex >> sm.ui_age >> sm.ui_post >> sm.f_salary >> sm.f_salesTotal;
    sm.f_salary = salesAmountRate / 100 * sm.f_salesTotal + baseSalary;  //底薪+所辖部门销售额总额*折算比例%
    return is;
}