#include <iostream>
using namespace std;
int main()
{
    int b = 0;
    int *a = &b;

    cout << " + - " << uintptr_t(a) << ' ' << a;
    
    return 0;
}
