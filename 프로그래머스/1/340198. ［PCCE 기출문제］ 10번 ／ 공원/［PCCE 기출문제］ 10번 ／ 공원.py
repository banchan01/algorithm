def can(i, j, mats, park)->int:
    # 돗자리 길이 순서대로
    #print(f"필터 전:{i},{j}")
    for length in mats:
        try:
            # 돗자리 최대 범위 체크
            #print(i+length-1,j+length-1)
            if (i+length-1 <= len(park)-1) and (j+length-1 <= len(park[0])-1):
                #print(f"필터 후훟:{i},{j}")
                for a in range(i,i+length):
                    for b in range(j, j+length):
                        if park[a][b] != '-1':
                            raise ValueError
                #print(f"{i},{j}일때, hello, {length}")
                return length
            # 범위 넘어갈때 처리
            else: continue
        
        except ValueError:
                continue
    # 만족하는 돗자리 자리가 없을때
    return -100

def solution(mats, park):
    answer = -1
    # 내림차순 정렬
    mats.sort(reverse=True)
    
    # 공원 각 block 왼쪽 위 기준으로 판단
    for i in range(len(park)):
        for j in range(len(park[i])):
            if (park[i][j] == '-1'):
                tmp = can(i,j,mats,park)
                if (tmp>answer):
                    answer = tmp
                
    return answer