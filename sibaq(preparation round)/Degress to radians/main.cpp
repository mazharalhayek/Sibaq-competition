#include <iostream>
#include <math.h>
#include <iomanip>

#define PI 3.141592653589793238462643383279502884

using namespace std;

int main()
{
    int degrees;
    cin>>degrees;
    while(degrees >= 0 && degrees < 360 && degrees%1 ==0)
    {
        cout<<setprecision(13);
        double radians = degrees * (PI / 180);
        cout<<radians;
        return 0;
    }
    return 0;
}
