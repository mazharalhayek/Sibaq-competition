#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    int len;
    cin>>len;
    int numbers[len];
    stringstream ss;
    string str;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin, str);
    //replace( str.begin(), str.end(), ',', ' ');
    ss << str;

    int x = 0,i=0;
    while (ss >> x)
    {
        numbers[i] = x;
        i++;
    }

    int s = sizeof(numbers)/sizeof(numbers[0]);
    sort(numbers,s+numbers);
    for(int j=0;j<=len-1;j++){cout<<numbers[j]<<" ";}
    return 0;
}
