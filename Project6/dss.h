#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <Windows.h>

class dss {
    static const int N = 6;
    int iter = 0;
    int arrayOfW[5][N];

    std::vector<std::string> langs = {
        "C lang",
        "CPP lang",
        "JAVA lang",
        "JS lang",
        "PYTHON lang"
    };

    std::vector<std::string> question = {
        "1. �������� i��� ?",
        "2. ��� �������� ?",
        "3. �������� ��� �i����� ?",
        "4. �������� �������� i�������� ?",
        "5. �������� ����������� ?",
        "6. ��������� ������������� ���� ?",
    };

    std::vector<std::vector<bool>> answ = {
        {false, false, false, false, true, true},
        {true, false, false, true, true, true},
        {true, true, true, true, false, false},
        {false, true, true, false, false, true},
        {false, true, false, true, false, false}
    }; 

    std::vector<int> index;

public :
    dss();
    ~dss() {};
    int getSize(int index);
    bool calc();
    std::pair<int, int> getTrueFalse(int indexInVector);
    void userInterfase();
    std::vector<bool> userAnsw;
    void input();
    void clearAnsw();


private:
    void study();    
};