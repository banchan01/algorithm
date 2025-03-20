def solution(bandage, health, attacks):
    time = 0
    keep_time = bandage[0]
    heal_amount = bandage[1]
    extra_heal = bandage[2]
    cur_health = health
    attack_cnt = 0
#    print(f"attack_cnt : {attack_cnt}")

    while(True):            
        # 체력 있고, 공격 다씀
        if(attack_cnt >= len(attacks)):
            return cur_health
        
        attack_flag = False
        print(f"cur_health : {cur_health}")
        print(f"time : {time}")
        time+=1
        
        # 이번 시간에 공격 있을때
        if attacks[attack_cnt][0] == time:
            print(f"attack_cnt : {attack_cnt}")
            cur_health -= attacks[attack_cnt][1]
            if (cur_health <= 0):
                return -1
            keep_time = bandage[0]
            attack_cnt += 1
            attack_flag = True
            
        # 이번 시간에 공격 없을때
        if not attack_flag:
            if (cur_health < health):
                if(cur_health + heal_amount >= health):
                    cur_health = health
                else:
                    cur_health += heal_amount
                keep_time -= 1
                
            if (keep_time == 0 and cur_health < health):
                if(cur_health + extra_heal >= health):
                    cur_health = health
                else:
                    cur_health += extra_heal
                keep_time = bandage[0]