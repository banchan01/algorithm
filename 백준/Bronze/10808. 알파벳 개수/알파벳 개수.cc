#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string word;
    cin >> word;

    int len = word.length();
    int arr[26] = {0};

    for(char n:word)
    {
        arr[n-'a'] += 1;
    }
    for(int i = 0; i < 26; i++)
    {
        cout << arr[i]<<" ";
    }
    return 0;
}