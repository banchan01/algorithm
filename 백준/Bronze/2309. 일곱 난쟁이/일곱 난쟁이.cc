#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    bool flag = false;
    int height[9];
    int left_height=0;
    for(int i = 0; i<9; i++)
    {
        cin >> height[i];
        left_height += height[i];
    }
    left_height -= 100;

    for(int i=0; i<9;i++)
    {
        for(int j=i+1; j<9; j++)
        {
            int a = left_height;
            a -= height[i];
            a -= height[j];
            if (a==0)
            {
                height[i] =0;
                height[j] =0;
                flag = true;
                break;
            }
        }
        if (flag == true) break;
    }

    sort(height,height+9);

    for(int i=0; i<9;i++)
    {
        if (height[i] != 0)
        {
            cout << height[i] << '\n';
        }
    }
    return 0;

}