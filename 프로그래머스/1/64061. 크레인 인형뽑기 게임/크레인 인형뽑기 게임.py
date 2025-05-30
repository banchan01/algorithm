def solution(board, moves):
    answer = 0
    # 스택선언
    stack = [0]
    for b in board:
        print(b)
    # 뽑기
    for i in moves:
        for row in board:
            if row[i-1] != 0:
                if stack[-1] == row[i-1]:
                    stack.pop()
                    answer += 2
                else:
                    stack.append(row[i-1])
                row[i-1] = 0
                break
    
    
    return answer