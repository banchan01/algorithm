def solution(X, Y):
    num = []
    dx = {}
    dy = {}
    for k in X:
        if k in dx.keys():
            dx[k] += 1
        else: dx[k] = 1
        
    for k in Y:
        if k in dy.keys():
            dy[k] += 1
        else: dy[k] = 1
    
    for k in dx.keys():
        if k in dy.keys():
            for _ in range(min(dx[k], dy[k])):
                num.append(int(k))

    answer = ""
    
    if len(num)==0:
        answer = "-1"
        
    else: 
        num.sort(reverse=True)
        answer = ''
        for x in num:
            answer += str(x)
    if sum(num) == 0 and len(num) >= 2:
        answer = "0"
        
    return answer