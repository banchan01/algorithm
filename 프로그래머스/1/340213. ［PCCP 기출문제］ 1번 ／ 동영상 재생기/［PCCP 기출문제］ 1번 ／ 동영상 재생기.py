def cts(time):
    minute = time.split(":")[0]
    second = time.split(":")[1]
    return int(minute)*60 + int(second)

def solution(video_len, pos, op_start, op_end, commands):
    # 전부 초 단위로 바꾸기
    video_len = cts(video_len)
    pos = cts(pos)
    op_start = cts(op_start)
    op_end = cts(op_end)
    print(video_len, pos, op_start,op_end)
    # 명령따라서 commands 루프
    for command in commands:
        # 첫 조건문 -> 오프닝 에 pos 들어잇는가?
        if op_start<=pos and pos<=op_end:
            pos = op_end
        
        # 명령따라 움직이기 -> 첫, 끝 조건 챙기기
        if command == "next":
            pos += 10
            # 오프닝 체크
            if op_start<=pos and pos<=op_end:
                pos = op_end
            # 영상 끝 여부 체크
            if video_len <= pos:
                pos = video_len
            # 오프닝 체크
            if op_start<=pos and pos<=op_end:
                pos = op_end
        else:
            pos -= 10
            # 오프닝 체크
            if op_start<=pos and pos<=op_end:
                pos = op_end
            # 영상 시작 여부 체크
            if pos<=0:
                pos = 0
            # 오프닝 체크
            if op_start<=pos and pos<=op_end:
                pos = op_end
            
    # 마지막에 오프닝체크 한번더 (루프 밖에서)
    if op_start<=pos and pos<=op_end:
        pos = op_end
    # 결과형식으로 변환
    minute = pos//60
    second = pos%60
    if len(str(minute)) == 1:
        minute = "0"+str(minute)
    if len(str(second)) == 1:
        second = "0" + str(second)
    answer = str(minute)+":"+str(second)
    return answer