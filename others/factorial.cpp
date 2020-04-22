#include <iostream>

using namespace std;

int fact(int x) {
    if (x == 1) {
        return x;
    }
    
    return x * fact(x - 1);
}

int main()
{
    int x = 5;
    int result = fact(x);
    cout << "Factorial of " << x << " is " << result;

    return 0;
}