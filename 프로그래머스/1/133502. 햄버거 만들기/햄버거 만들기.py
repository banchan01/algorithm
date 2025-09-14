def solution(ingredient):
    answer = 0
    seq = [1,2,3,1]
    stk = []
    for i in range(0,len(ingredient)):
        stk.append(ingredient[i])
        if(stk[-4:] == seq):
            answer += 1
            for _ in range(4):
                stk.pop()
    return answer