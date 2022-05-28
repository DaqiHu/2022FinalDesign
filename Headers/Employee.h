#ifndef INC_2022FINALDESIGN_EMPLOYEE_H
#define INC_2022FINALDESIGN_EMPLOYEE_H

const float hourSalary = 100.0;         //技术员：每小时工资
const float staticSalary = 8000.0;      //经理：固定月薪
const float bonusRate = 4.0;            //销售员：提成比例
const float salesAmountRate = 0.5;      //销售经理：所辖部门销售额总额的折算比例
const float baseSalary = 5000.0;        //销售经理：底薪

#include <iostream>
#include <string>
#include <fstream>

#include "../Headers/Message.h"

using namespace std;

class Employee {
public:
    //调用数据成员
    string id();                //获取职工号
    string name();                //获取姓名
    unsigned int age() const;    //获取年龄
    float salary() const;        //获取薪水
    string sex() const;            //获取性别
    string post();                //获取岗位

    friend ostream &operator<<(ostream &os, const Employee &emp);

    friend istream &operator>>(istream &is, Employee &emp);

protected:
    string str_id = "Number";   //职工号
    string str_name = "Staff";  //姓名
    char c_sex = 'm';           //性别，m代表男性，f代表女性
    unsigned int ui_age = 0;    //年龄
    unsigned int ui_post = 0;   //岗位，0 未知，1 技术员，2 经理，3 销售员，4 销售经理
    float f_salary = 0.0;       //月薪
    Message msg;
};

class Engineer : public Employee {
public:
    //构造析构
    Engineer();

    ~Engineer() = default;

    //调用数据成员
    float hour() const;            //获取工作时长

    friend ostream &operator<<(ostream &os, const Engineer &eng);

    friend istream &operator>>(istream &is, Engineer &eng);

private:
    float f_hour = 0.0;            //工作时长
};

class Manager : virtual public Employee {
public:
    //构造析构
    Manager();
    Manager(string str_id, string str_name, char c_sex, unsigned int ui_age, float f_hour, float f_sales);

    friend ostream &operator<<(ostream &os, const Manager &mang);

    friend istream &operator>>(istream &is, Manager &mang);

};

class SalesPerson : virtual public Employee {
public:
    //构造析构
    SalesPerson();
    SalesPerson(string str_id, string str_name, char c_sex, unsigned int ui_age, float f_hour, float f_sales);

    ~SalesPerson() = default;

    //调用数据成员
    float sales() const;        //获取销售额

    friend ostream &operator<<(ostream &os, const SalesPerson &sp);

    friend istream &operator>>(istream &is, SalesPerson &sp);

private:
    float f_sales = 0.0;        //销售额
};

class SalesManager : public Manager, public SalesPerson {
public:
    //构造析构
    SalesManager();
    SalesManager(const string &str_id, const string &str_name, char c_sex, unsigned int ui_age, float f_hour,
                 float f_salesTotal);

    ~SalesManager() = default;

    //调用数据成员
    float salesTotal() const;                //获取销售额总额

    friend ostream &operator<<(ostream &os, const SalesManager &sm);

    friend istream &operator>>(istream &is, SalesManager &sm);

private:
    float f_salesTotal = 0.0;        //所辖部门销售额总额
};

#endif //INC_2022FINALDESIGN_EMPLOYEE_H
