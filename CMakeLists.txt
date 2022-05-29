cmake_minimum_required(VERSION 3.22)
project(2022FinalDesign)

set(CMAKE_CXX_STANDARD 14)
file(GLOB 2022FinalDesign CONFIGURE_DEPENDS "*.h" "*.cpp")
add_executable(2022FinalDesign main.cpp "Source Files/Data.cpp" Headers/Data.h "0_MainPage/MainPage.cpp" 0_MainPage/MainPage.h "Source Files/Message.cpp" Headers/Message.h "3_PrintData/PrintData.cpp" 3_PrintData/PrintData.h "4_SaveToFile/SaveData.cpp" 4_SaveToFile/SaveData.h Headers/Employee.h "Source Files/Employee.cpp" "5_ExitSystem/Exit.cpp" "2_SortData/SortData.cpp" "1_InputStaff/InputData.cpp")

add_executable(main test.cpp "Headers/Message.h" "Source Files/Message.cpp")