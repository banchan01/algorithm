def solution(players, callings):
    ranking = [i+1 for i in range(len(players))]
    a = dict(zip(ranking,players))
    b = dict(zip(players, ranking))
    
    for calling in callings:
        cur_rank = b[calling]
        pre_rank = cur_rank - 1 
        
        origin = a[pre_rank]
        a[pre_rank] = calling
        a[cur_rank] = origin
        
        b[origin] = cur_rank
        b[calling] = pre_rank
        
        
    answer = []
    
    for _,b in a.items():
        answer.append(b)
        
    return answer