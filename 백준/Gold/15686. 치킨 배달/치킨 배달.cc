#include <bits/stdc++.h>
using namespace std;
int arr[55][55];
vector<pair<int,int>> _home;
vector<pair<int,int>> _chicken;
vector<vector<int>> _chicken_list;
int n,m;
int ret = 987654321;


void combi(int start, vector<int>& b) {
    if(b.size()==m) {
        _chicken_list.push_back(b);
        return;
    }
    for(int i=start+1; i<_chicken.size(); i++) {
        b.push_back(i);
        combi(i,b);
        b.pop_back();
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 입력 받기
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
            if(arr[i][j]==1) _home.push_back({i,j});
            if(arr[i][j]==2) _chicken.push_back({i,j});
        }
    }
    // 선택할 치킨 집 조합 이중 벡터에 담기
    vector<int> v;
    combi(-1,v);

    for(vector<int> _chicken_candi : _chicken_list) {
        int t_chicken_dis = 0;
        for(auto home_pos : _home) {
            int _dis = 987654321;
            for(auto chicken_pos : _chicken_candi) {
                int t_dis = abs(home_pos.first - _chicken[chicken_pos].first) + abs(home_pos.second - _chicken[chicken_pos].second);
                _dis = min(_dis,t_dis);
            }
            t_chicken_dis += _dis;
        }
        ret = min(ret,t_chicken_dis);
    }

    cout << ret << '\n';
    return 0;
}