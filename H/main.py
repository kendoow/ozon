def solve(n, k, blacklist):
    subnets = set()
    for ip in blacklist:
        x, y = map(int, ip.split('.')[2:])
        subnets.add((x, y))
    
    subnets = sorted(subnets, key=lambda x: -x[0])  # Сортировка по убыванию размера подсети
    
    banned_count = 0
    used_entries = 0
    filter_entries = []
    
    for x, y in subnets:
        if banned_count == 0:
            filter_entries.append(f"100.200.{x}.0/24")
            used_entries += 1
            banned_count += 255
        filter_entries.append(f"100.200.{x}.{y}")
        used_entries += 1
        banned_count += 1
    
    if banned_count < n:
        for x in range(256):
            for y in range(256):
                filter_entries.append(f"100.200.{x}.{y}")
                used_entries += 1
                banned_count += 1
                if banned_count == n:
                    break
            if banned_count == n:
                break
    
    return used_entries, filter_entries

# Чтение входных данных
n, k = map(int, input().split())
blacklist = [input() for _ in range(n)]

# Решение задачи
used_entries, filter_entries = solve(n, k, blacklist)

# Вывод результатов
print(sum(1 for x in filter_entries if '/' in x))  # Количество запрещенных подсетей
print(used_entries)  # Количество использованных записей в файле
for entry in filter_entries:
    print(entry)  # Записи фильтрующего файла
