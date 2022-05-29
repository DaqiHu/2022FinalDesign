#ifndef INC_2022FINALDESIGN_SORTDATA_H
#define INC_2022FINALDESIGN_SORTDATA_H

#include <vector>

#include "../Headers/Data.h"
#include "../4_SaveToFile/SaveData.h"

using namespace std;

class SortData {
public:
    //构造析构
    SortData() = default;

    ~SortData() = default;

    static void sort();

    static void displayBanner();
};

#endif //INC_2022FINALDESIGN_SORTDATA_H
