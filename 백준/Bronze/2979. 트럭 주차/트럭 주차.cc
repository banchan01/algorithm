#include <iostream>
using namespace std;

int arr[105];

int main()
{
    int result =0;
    int a,b,c;
    cin >> a >> b >> c;
    for(int i=0; i<3;i++)
    {
        int in, out;
        cin >> in >> out;

        for(int j=in; j<out; j++)
        {
            arr[j] += 1;
        }
    }

    for(int i=0; i<105;i++)
    {
        if (arr[i] == 1)
        {
            result += a;
        }
        else if (arr[i]==2)
        {
            result += 2*b;
        }
        else if (arr[i]==3)
        {
            result += 3*c;
        }
    }
    cout << result;

    return 0;
}