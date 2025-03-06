#include <iostream>
#include <string>
using namespace std;

int main()
{
    int result = 1;
    string a;
    cin >> a;

    for(int i=0; i<a.length()/2; i++)
    {
        if (a[i] != a[a.length()-1-i])
        {
            result = 0;
        }
    }
    cout << result;
    return 0;
}