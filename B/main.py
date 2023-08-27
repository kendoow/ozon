def is_visible(i, j, k, grid):
    
    for l in range(k):
        if grid[l][i][j] != '.':
            return False
    return True

def main():
    t = int(input())  

    for _ in range(t):
        k, n, m = map(int, input().split()) 
        grid = [] 

       
        for _ in range(k):
            relief = [list(input().strip()) for _ in range(n)]
            grid.append(relief)
            input()  
        
       
        for l in range(k):
            for i in range(n):
                for j in range(m):
                    if grid[l][i][j] in ['/', '\\'] and not is_visible(i, j, l, grid):
                       
                        grid[l][i][j] = '.'

       
        for relief in grid:
            for row in relief:
                print(''.join(row))
            print()  

main()
