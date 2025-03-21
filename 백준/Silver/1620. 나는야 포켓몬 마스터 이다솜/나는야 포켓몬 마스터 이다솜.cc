#include <bits/stdc++.h>
using namespace std;

int n,m;
map<int, string> dogam;
map<string, int> dogamgam;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        string pokemon;
        cin >> pokemon;
        dogam[i+1] = pokemon;
        dogamgam[pokemon] = i+1;
    }

    for(int i=0;i<m;i++) {
        string quiz;
        cin >> quiz;
        if (atoi(quiz.c_str())) {
            int idx = atoi(quiz.c_str());
            cout << dogam[idx] << '\n';
        }
        else cout << dogamgam[quiz] << '\n';
    }
}