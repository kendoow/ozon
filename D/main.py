def solution(pic):
    pass  # Ваша реализация функции solution

def main():
    t = int(input())
    
    arts = []
    for _ in range(t):
        pic = []
        solution(pic)
        arts.append(pic)

    for i in range(t):
        for line in arts[i]:
            print(line)
        print()

main()
