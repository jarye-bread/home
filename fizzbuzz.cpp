// Jarye Murphy 1/31/2017
// fizzbuzz practice problem for c++
#include <iostream>

using std::cout;
using std::endl;
int main()
{
    for(int i=1; i < 101; ++i)
    {
        if(i%15 == 0) // checking for divisbility of 5 and 3 can be done checking for modulus of 15 == 0
            cout << "fizzbuzz" <<endl;
        else
        {
            if(i%3 == 0)
                cout << "fizz" << endl;
            else if(i%5 == 0)
                cout << "buzz" << endl;
            else
                cout << i << endl;
        }
    }
    return 0;
}
