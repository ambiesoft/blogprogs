// testRVO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <iostream>

struct C {
    C() = default;
    C(const std::string& s) {
        std::cout << s << "\n";
    }
    C(const C&) { std::cout << "A copy was made.\n"; }
};

C f() {
    C c;
    return c;
}

void main2() {
    std::cout << "Hello World!\n";
    C obj = f();
}



C F(bool cond = false) {
    C first("first");
    C second("second");
    // the function may return one of two named objects
    // depending on its argument. RVO might not be applied
    return cond ? first : second;
}
C F2(bool cond = false) {
    return cond ? C("first") : C("second");
}

void main3() {
    {
        C result = F();
        C resultTrue = F(true);
        C resultFalse = F(false);
        int i = 0;
        C resultV = F(i == 0);
    }
}
void main4(){
    {
        C result = F2();
        C resultTrue = F2(true);
        C resultFalse = F2(false);
        int i = 0;
        C resultV = F2(i == 0);
    }
}


int main()
{
    //main2();
    //main3();
    main4();
}