def solution(new_id):
    answer = ''
    # 1단계
    new_id = new_id.lower()
    
    # 2단계
    tmp = ""
    allowed = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890-_."
    for w in new_id:
        if w in allowed:
            tmp += w
    
    # 3단계
    tmp_3 = ""
    pre_w = ""
    for w in tmp:
        if w == "." and pre_w == ".":
            continue
        tmp_3 += w
        pre_w = w
    # 4단계
    tmp_4 =""
    for i in range(len(tmp_3)):
        if i==0 or i==len(tmp_3)-1:
            if tmp_3[i] == ".":
                continue
        tmp_4 += tmp_3[i]
    
    # 5단계
    if len(tmp_4) == 0:
        tmp_4 += "a"
        
    # 6단계
    tmp_6 = tmp_4
    if len(tmp_4) >= 16:
        tmp_6 = tmp_4[:15]
        
    if tmp_6[-1] == ".":
        tmp_6 = tmp_6[:-1]
    print(tmp_6)
    
    # 7단계
    if len(tmp_6) <=2:
        lw = tmp_6[-1]
        while(len(tmp_6)<3):
            tmp_6 += lw
    answer = tmp_6
    return answer