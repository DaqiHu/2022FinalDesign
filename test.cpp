////
//// Created by AiEnigma on 5/28/2022.
////
//#include <iostream>
//#include <utility>
//#include <fstream>
//
//using namespace std;
//
//struct Student {
//    Student() = default;
//
//    Student(std::string n, int a, int s)
//            : name(std::move(n)), age(a), score(s) {
//    }
//
//    std::string name;
//    int age = 0;
//    int score = 0;
//
//    void log() const {
//        std::cout << "name:" << name.c_str() << std::endl;
//        std::cout << "age:" << age << std::endl;
//        std::cout << "score:" << score << std::endl;
//    }
//};
//
//int main() {
//    {
//        std::ofstream fin("a.dat", std::ios::binary);
//        Student aa("小明", 26, 100);
//        std::string str = "空格";
//        fin.write((const char *) &aa, sizeof(Student));
//        //将student中的内容 写入到文件
//        fin.write((const char *) &str, sizeof(std::string));
//        fin.close();
//    }
//
//    {
//        auto *stu = new Student;
//        std::string str;
//        std::fstream fin("a.dat", std::ios::binary | ios::in);
//        fin.read((char *) stu, sizeof(Student));
//        //fin.seekg(sizeof(Stuent), ios::beg);
//        fin.read((char *) &str, sizeof(std::string));
//        fin.close();
//
//        std::cout << str.c_str() << std::endl;
//        stu->log();
//        delete stu;
//    }
//    getchar();
//    return 0;
//}

#include <iostream>
#include <string>

using namespace std;

int main() {
    char a = '\003', b = 4, c = 5, d = 6;
    cout << a << endl
         << b << endl
         << c << endl
         << d << endl;
    return 0;
}