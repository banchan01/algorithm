def solution(id_list, report, k):
    # report 를 set으로 만들어서 겹치는 부분 삭제
    report = set(report)
    report = list(report)

    answer = []
    # 신고횟수 딕셔너리 선언
    cnt_dict = {}
    for id in id_list:
        cnt_dict[id] = 0
    
    # 사람당 신고당한 횟수 저장
    for i in range(len(report)):
        name = report[i].split()[1]
        cnt_dict[name] += 1
            
    # k보다 큰 애들 선별
    candidate = []
    for name,cnt in cnt_dict.items():
        if cnt>=k:
            candidate.append(name)
    
    # result_dict 선언
    result_dict = {}
    for id in id_list:
        result_dict[id] = 0
    
    # report 에서 신고자 필터
    for i in range(len(report)):
        name = report[i].split()[0]
        if report[i].split()[1] in candidate:
            result_dict[name] += 1
    # 결과 저장
    for i in result_dict.values():
        answer.append(i)
        
    return answer