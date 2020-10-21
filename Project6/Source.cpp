#include "dss.h"
#include <locale>

int main()
{
    setlocale(LC_ALL, "ru");
    bool flag = false;
    dss o;
    
    while (flag != true) {    
          o.clearAnsw();
          o.userInterfase();
          flag = o.calc();                
    }   

    system("pause");
    return 0;
}