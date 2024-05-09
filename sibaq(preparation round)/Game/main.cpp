#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    int len;
    cin>>len;
    if(len>100||len<0){exit(0);}
    int numsarray[len];
    int results[len];
    stringstream nums;
    string numstr;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin,numstr);
    nums << numstr;

    int x = 0,i=0,j=0;
    while (nums >> x)
    {
        numsarray[i] = x;
        i++;
    }

    int s = sizeof(numsarray)/sizeof(numsarray[0]);
    while(s>0){
        auto maximum = max_element(numsarray,numsarray+s);
        int maxindex  = distance(numsarray,maximum);
        results[j]=numsarray[maxindex];
        for(int i=maxindex;i<s;i++)
        {
            numsarray[i]= numsarray[i+1];
        }
        s--;
        j++;
        auto minimum = min_element(numsarray,numsarray+s);
        int minindex = distance(numsarray,minimum);
        results[j]=numsarray[minindex];
        for(int i=minindex;i<s;i++)
        {
            numsarray[i]= numsarray[i+1];
        }
        s--;
        j++;
    }

    for(int j=0;j<=len-1;j++){cout<<results[j]<<" ";}

    return 0;
}
