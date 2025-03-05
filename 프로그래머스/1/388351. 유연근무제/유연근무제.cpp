#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    // 주말은 3000으로 만들기
    for(vector<int>& person : timelogs)
    {
        if (startday == 7)
        {
            person[7-startday] = 0;
            person[6] = 0;
        }
        else
        {
            person[7-startday] = 0;
            person[6-startday] = 0;   
        }
    }
    // schedules + 10 보다 작으면 answer 에 +1
    int seq = 0;
    bool flag = false;
    for(vector<int>& person : timelogs)
    {   
        flag = false;
        // 50분 이면 다음시간으로 넘겨주기
        int temp_time = schedules[seq];
        if(temp_time%100 >= 50)
        {
            temp_time += 50;
        }
        else
        {
            temp_time += 10;
        }
        int deadline = temp_time;
        //cout << "deadline:" << deadline << '\n';
        for(int& time : person)
        {   
            //cout << "time:" << time << ' ';
            if (time > deadline)
            {
                flag = true;
                continue;
            }
        }
        if (flag == false)
        {
            answer += 1;   
        }
        seq += 1;
    }
    
    
    return answer;
}