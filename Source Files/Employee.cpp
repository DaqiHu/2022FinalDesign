#include"../Headers/Employee.h"

#include <utility>

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
    const char tab = ' ';
    os << emp.str_id << tab << emp.str_name << tab << emp.c_sex << tab << emp.ui_age << tab << emp.ui_post << tab
       << emp.f_salary;
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
    os << eng.f_hour;
    return os;
}

istream &operator>>(istream &is, Engineer &eng) {
    is >> eng.str_id >> eng.str_name >> eng.c_sex >> eng.ui_age >> eng.f_hour;
    eng.f_salary = hourSalary * eng.f_hour;
    return is;
}

//---------------------------经理-------------------------------

//构造函数
Manager::Manager(string str_id, string str_name, char c_sex, unsigned int ui_age, float f_hour, float f_sales) :
        Employee{std::move(str_id), std::move(str_name), c_sex, ui_age, 2, 0.0} {
    f_salary = staticSalary;                //固定月薪
    cout << msg.show("InputPostManagerSuccess") << endl;
}

ostream &operator<<(ostream &os, const Manager &mang) {
    return os;
}

istream &operator>>(istream &is, Manager &mang) {
    return is;
}

//---------------------------销售员-------------------------------

//构造函数
SalesPerson::SalesPerson(string str_id, string str_name, char c_sex, unsigned int ui_age, float f_hour, float f_sales) :
        Employee{std::move(str_id), std::move(str_name), c_sex, ui_age, 3, 0.0}, f_sales(f_sales) {
    f_salary = bonusRate / 100 * f_sales;    //销售额*提成%
    cout << msg.show("InputPostSalesPersonSuccess") << endl;
}

//获取销售额
float SalesPerson::sales() const {
    return f_sales;
}

ostream &operator<<(ostream &os, const SalesPerson &sp) {
    os << sp.f_sales;
    return os;
}

istream &operator>>(istream &is, SalesPerson &sp) {
    is >> sp.f_sales;
    return is;
}

//---------------------------销售经理-------------------------------

//构造函数
SalesManager::SalesManager() {

}

SalesManager::SalesManager(const string &str_id, const string &str_name, char c_sex, unsigned int ui_age, float f_hour,
                           float f_salesTotal) :
        Employee{str_id, str_name, c_sex, ui_age, 4, 0.0},    //在这里有三个类的初始化列表，就不适合用 std::move 函数了
        Manager{str_id, str_name, c_sex, ui_age, f_hour, 0.0},
        SalesPerson{str_id, str_name, c_sex, ui_age, f_hour, 0.0} {
    f_salary = salesAmountRate / 100 * f_salesTotal + baseSalary; //底薪+所辖部门销售额总额*折算比例%
    cout << msg.show("InputPostSalesManagerSuccess") << endl;
}

//获取销售额总额
float SalesManager::salesTotal() const {
    return f_salesTotal;
}

ostream &operator<<(ostream &os, const SalesManager &sm) {
    os << sm.f_salesTotal;
    return os;
}

istream &operator>>(istream &is, SalesManager &sm) {
    is >> sm.f_salesTotal;
    return is;
}