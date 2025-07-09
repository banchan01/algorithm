#include <iostream>
#include <map>
using namespace std;

int n, ts, p, score,result=1;
map<int,int,greater<int>> scores;

int main(){
    cin >> n >> ts >> p;
    if (n==0) {
        cout << 1;
        return 0;
    }
    for(int i=0; i<n; i++) {
        cin >> score;
        scores[score] += 1;
    }

    for (pair<int,int> item : scores) {
        //cout << "result : " << result << '\n';
        if (ts==item.first) {
            int tmp = result + item.second-1;
            if(tmp == p){
                cout << -1;
                return 0;
            } 
            if (result == 1) {
                cout << 1;
                return 0;
            }
            cout << result;
            return 0;
        }
        if (ts>item.first) {
            if(result>p) {cout << -1; return 0;}
            cout << result;
            return 0;
        }

        // result : 현재 item 등수 
        result += 1;
        if (item.second != 1) {
            result += item.second-1;
        }
    }
    if (result>p) {cout << -1; return 0;}
    cout << result;

    return 0;
}