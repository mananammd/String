#include "MyString.h"
#include <utility>
#include <assert.h>


int main() {
    {
        MyString exA("123");
        std::cout << "exA = ";
        exA.printf();
        std::cout << "copyA = ";
        MyString copyA(exA); // copy-constructor
        copyA.printf();
        MyString moveCopyA(std::move(copyA)); // move-constructor
        std::cout << "moveCopyA = ";
        moveCopyA.printf();
        std::cout << "copyA = ";
        copyA.printf();

        MyString exOper = "abcdf";
        std::cout << "exOperator= = ";
        exOper.printf();
        exOper = "123f";
        std::cout << "exOperator=(other) = ";
        exOper.printf();
    }


    {
        std::cout << "exB = ";
        MyString exB("abcdef");
        exB.printf();
        std::cout << "addStr = ";
        MyString addStr("123");
        addStr.printf();
        exB.insert(3, addStr);
        std::cout << "(insert for pos = 3) exB + insertStr = ";
        exB.printf();
        exB.append(addStr);
        std::cout << "append = ";
        exB.printf();

        exB.clear();
        std::cout << "exB = ";
        exB.printf();
    }

    

    {
        MyString exC("asdFGhjhjd");
        std::cout << "exC = ";
        exC.printf();
        exC.erase(3,2);
        std::cout << "Erase exC = ";
        exC.printf();
        MyString b("123");
    }

    {
        MyString exD("816274\0");
       // std::cout << "at[3] = ";
        //char at3 = exD.at(3);
      //  std::cout << at3;
        std::cout << "sizeexD = ";
        int sizestr = exD.size();
        std::cout << sizestr;


    }
    

}