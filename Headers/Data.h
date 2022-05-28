//
// Created by AiEnigma on 5/24/2022.
//

#ifndef INC_2022FINALDESIGN_DATA_H
#define INC_2022FINALDESIGN_DATA_H

#include "../Headers/Employee.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;

class Data {
public:
    //构造析构
    Data();

    ~Data();

    //增
    void insert(const Employee &staff);

    void insert(const Engineer &staff);

    void insert(const Manager &staff);

    void insert(const SalesPerson &staff);

    void insert(const SalesManager &staff);

    //删
    void erase(const Employee &staff);

    //改
    void update(const Employee &staff);

    //查
    auto find(const Employee &staff);

    auto find(const Engineer &staff);

    auto find(const Manager &staff);

    auto find(const SalesPerson &staff);

    auto find(const SalesManager &staff);

    //排序
    static void sort(vector<Employee> &vec);                            //排序算法
    friend bool rule(const Employee &first, const Employee &second);    //排序规则 （必须声明为友元函数，即全局化）
    static void sortAndShow(vector<Employee> vec);                      //排序后输出

    //显示
    static void show(vector<Employee> &vec);

    //获取数据成员
    vector<Employee> &staffList();

    vector<Engineer> &engineerList();

    vector<Manager> &managerList();

    vector<SalesPerson> &salesPersonList();

    vector<SalesManager> &salesManagerList();

    friend ostream &operator<<(ostream &os, const vector<Employee> &vec);

    friend ostream &operator<<(ostream &os, const vector<Engineer> &vec);

    friend ostream &operator<<(ostream &os, const vector<Manager> &vec);

    friend ostream &operator<<(ostream &os, const vector<SalesPerson> &vec);

    friend ostream &operator<<(ostream &os, const vector<SalesManager> &vec);

//    friend ostream &operator<<(ostream &os, const Data &data);

    friend istream &operator>>(istream &is, vector<Employee> &vec);

    friend istream &operator>>(istream &is, vector<Engineer> &vec);

    friend istream &operator>>(istream &is, vector<Manager> &vec);

    friend istream &operator>>(istream &is, vector<SalesPerson> &vec);

    friend istream &operator>>(istream &is, vector<SalesManager> &vec);

    void save();

    void load();

    void erase();

private:
    vector<Employee> vec_staffList;
    vector<Engineer> vec_engineerList;
    vector<Manager> vec_managerList;
    vector<SalesPerson> vec_salesPersonList;
    vector<SalesManager> vec_salesManagerList;
    static Message msg;
};

#endif //INC_2022FINALDESIGN_DATA_H
