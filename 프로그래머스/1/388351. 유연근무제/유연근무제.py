def solution(schedules, timelogs, startday):
    answer = len(schedules)
    # 토,일요일 index설정
    sat = 7-startday
    sun = 7-startday+1
    if sun <= 0:
        sun += 7
    if sat <= 0:
        sat += 7
    # 토,일요일 무조건 통과로 취급 -> 02시로 바꾸기
    for timelog in timelogs:
        timelog[sat-1] = 200
        timelog[sun-1] = 200
    # 시간을 분으로 바꾸기
    # 1. timelogs
    for timelog in timelogs:
        for i in range(len(timelog)):
            timelog[i] = (timelog[i]//100) * 60 + timelog[i]%100
    # 2. schedules
    for i in range(len(schedules)):
        schedules[i] = (schedules[i]//100) * 60 + schedules[i]%100
    # 검사
    for i in range(len(schedules)):
        schedule = schedules[i]
        timelog = timelogs[i]
        for j in range(len(timelog)):
            if schedule+10 < timelog[j]:
                answer -= 1
                break
    return answer