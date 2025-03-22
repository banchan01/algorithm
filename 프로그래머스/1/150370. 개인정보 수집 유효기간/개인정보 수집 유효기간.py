def solution(today, terms, privacies):
    idx = 0
    answer = []
    
    # 오늘날짜 날짜 단위로 바꾸기
    t_year, t_month, t_date = int(today.split('.')[0]),int(today.split('.')[1]),int(today.split('.')[2])
    today_day = t_year*12*28 + t_month*28 + t_date
    
    # terms 딕셔너리로 저장
    term_d = {}
    for term in terms:
        type, gigan = term.split()[0], term.split()[1]
        term_d[type] = int(gigan)
    
    # 날짜 더하기
    for privacy in privacies:
        idx+=1
        day, ctg = privacy.split()[0], privacy.split()[1]
        s_year, s_month, s_date = int(day.split('.')[0]),int(day.split('.')[1]),int(day.split('.')[2])
        #print(s_year, s_month, s_date)
        
        # 날짜 단위로 바꾸기
        total_day = s_year*12*28 + s_month*28 + s_date
        
        # term에서 더할 기간 가져오기
        add_month = term_d[ctg]
        add_day = add_month*28
        
        # 날짜 더하기
        total_day += add_day
        
        # 오늘이랑 total 비교하기
        if(total_day <= today_day):
            answer.append(idx)
            
    return answer