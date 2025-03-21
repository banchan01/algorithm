def solution(park, routes): 
    x = 0
    y = 0
    grid = [[x for x in contents] for contents in park]
    
    def in_range(x,y)-> bool:
        return 0<=x<len(grid) and 0<=y<len(grid[0])            
    
    # 시작 위치 정하기
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if (grid[i][j]=="S"):
                x = i
                y = j
    
    # 명령으로 움직이기
    for route in routes:
        interrupted = False
        a,b = route.split()
        n = int(b)
        
        if a == "N":
            for i in range(n+1):
                if in_range(x-i,y):
                    if grid[x-i][y] == "X":
                        interrupted = True
                    
            if (in_range(x-n,y) and not interrupted):
                x -= n
                continue
            else:
                continue
                
                
        if a == "E":
            for i in range(n+1):
                if in_range(x,y+i):
                    if grid[x][y+i] == "X":
                        interrupted = True
                    
            
            if (in_range(x,y+n) and not interrupted):
                y += n
                continue
            else:
                continue
                
        if a == "W":
            for i in range(n+1):
                if in_range(x,y-i):
                    if grid[x][y-i] == "X":
                        interrupted = True
                    
            
            if (in_range(x,y-n) and not interrupted):
                y -= n
                continue
            else:
                continue
                
        if a == "S":
            for i in range(n+1):
                if in_range(x+i,y):
                    if (grid[x+i][y] == "X"):
                        interrupted = True
                    
            
            if (in_range(x+n,y) and not interrupted):
                x += n
                continue
            else:
                continue
            
        
        
    answer = [x,y]
    return answer