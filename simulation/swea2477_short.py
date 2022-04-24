t = lambda x: list(map(lambda y: y-1 if y > 0 else y, x))
list_input = lambda x: list(map(int, input().split()))
for T in range(int(input())):
    recept_num, repair_num, customer_num, target_recept, target_repair = map(int, input().split())
    recept_time = list_input(0)
    recept_desks_left_time = [-1] * recept_num
    recept_desks = [[]for _ in range(recept_num)]

    repair_time = list_input(0)
    repair_desks_left_time = [0] * repair_num
    repair_desks = [[]for _ in range(repair_num)]

    customer_time = list_input(0)
    recept_wait = []
    repair_wait = []
    n = 1
    customer_id = 0
    while customer_id != customer_num:
        if 0 in customer_time:
            recept_wait.append(n)
            customer_time.pop(0)
            n += 1
            continue
        while -1 in recept_desks_left_time and recept_wait:
            ni = recept_desks_left_time.index(-1)
            recept_desks_left_time[ni] = recept_time[ni]
            recept_desks[ni].append(recept_wait.pop(0))
        recept_desks_left_time = t(recept_desks_left_time)
        while 0 in recept_desks_left_time:
            ni = recept_desks_left_time.index(0)
            repair_wait.append(recept_desks[ni][-1])
            recept_desks_left_time[ni] = -1
        while 0 in repair_desks_left_time and repair_wait:
            customer_id += 1
            mi = repair_desks_left_time.index(0)
            repair_desks_left_time[mi] = repair_time[mi]
            repair_desks[mi].append(repair_wait.pop(0))
        repair_desks_left_time = t(repair_desks_left_time)
        customer_time = t(customer_time)

    result = sum(set(recept_desks[target_recept-1]) & set(repair_desks[target_repair-1]))
    print(f'#{T+1}', result if result != 0 else-1)