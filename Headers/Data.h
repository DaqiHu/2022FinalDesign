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

//类中全部成员都是 public 的
class Data {
public:
    //构造析构
    Data();

    ~Data();

    //排序
    void sort();                            //排序算法
    friend bool rule(const Employee &first, const Employee &second);    //排序规则 （必须声明为友元函数，即全局化）

    //显示
    void show();
    float showSalesManager();
    void sortAndShow();                      //排序后输出

//    //获取数据成员
//    vector<Employee> &staffList();
//
//    vector<Engineer> &engineerList();
//
//    vector<Manager> &managerList();
//
//    vector<SalesPerson> &salesPersonList();
//
//    vector<SalesManager> &salesManagerList();

    //重载输出运算符<<：vector容器
    friend inline ostream &operator<<(ostream &os, const vector<Employee> &vec);

    friend inline ostream &operator<<(ostream &os, const vector<Engineer> &vec);

    friend inline ostream &operator<<(ostream &os, const vector<Manager> &vec);

    friend inline ostream &operator<<(ostream &os, const vector<SalesPerson> &vec);

    friend inline ostream &operator<<(ostream &os, const vector<SalesManager> &vec);

    //重载输入运算符>>：vector容器
    friend inline istream &operator>>(istream &is, vector<Employee> &vec);

    friend inline istream &operator>>(istream &is, vector<Engineer> &vec);

    friend inline istream &operator>>(istream &is, vector<Manager> &vec);

    friend inline istream &operator>>(istream &is, vector<SalesPerson> &vec);

    friend inline istream &operator>>(istream &is, vector<SalesManager> &vec);

    //保存数据到文件
    void save() const;

    //从文件读取数据
    void load();

    //删除文件数据
    void erase();

    //数据容器
    vector<Employee> vec_staffList;
    vector<Engineer> vec_engineerList;
    vector<Manager> vec_managerList;
    vector<SalesPerson> vec_salesPersonList;
    vector<SalesManager> vec_salesManagerList;
};

inline ostream &operator<<(ostream &os, const vector<Employee> &vec) {
    const char tab = ' ';
    for (auto &iter: vec)
        os << iter << tab;
    return os;
}

inline ostream &operator<<(ostream &os, const vector<Engineer> &vec) {
    const char tab = ' ';
    for (auto &iter: vec)
        os << iter << tab;
    return os;
}

inline ostream &operator<<(ostream &os, const vector<Manager> &vec) {
    const char tab = ' ';
    for (auto &iter: vec)
        os << iter << tab;
    return os;
}

inline ostream &operator<<(ostream &os, const vector<SalesPerson> &vec) {
    const char tab = ' ';
    for (auto &iter: vec)
        os << iter << tab;
    return os;
}

inline ostream &operator<<(ostream &os, const vector<SalesManager> &vec) {
    const char tab = ' ';
    for (auto &iter: vec)
        os << iter << tab;
    return os;
}

inline istream &operator>>(istream &is, vector<Employee> &vec) {
    Employee emp;
    while (is >> emp) {
        vec.emplace_back(emp);
    }
    return is;
}

inline istream &operator>>(istream &is, vector<Engineer> &vec) {
    Engineer eng;
    while (is >> eng) {
        vec.emplace_back(eng);
    }
    return is;
}

inline istream &operator>>(istream &is, vector<Manager> &vec) {
    Manager mang;
    while (is >> mang) {
        vec.emplace_back(mang);
    }
    return is;
}

inline istream &operator>>(istream &is, vector<SalesPerson> &vec) {
    SalesPerson sp;
    while (is >> sp) {
        vec.emplace_back(sp);
    }
    return is;
}

inline istream &operator>>(istream &is, vector<SalesManager> &vec) {
    SalesManager sm;
    while (is >> sm) {
        vec.emplace_back(sm);
    }
    return is;
}

#endif //INC_2022FINALDESIGN_DATA_H
