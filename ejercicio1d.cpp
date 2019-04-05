#include <iostream>
using namespace std;

int main()
{
    int a = 5, *p = &a, **p2 = &p; // a = *p = **p2

    **p2 = *p + (**p2 / a); // a = 6
    *p = a+1;               // a = 7
    a = **p2 / 2;           // a = 3
    cout << "a es igual a: " << a << endl;

    return 0;    
}