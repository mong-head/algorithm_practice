from collections import deque


T = int(input())
# 여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    '''
    입력
    '''
    recept_num, repair_num, customer_num, target_recept, target_repair = map(int, input().split())
    recept_time = list(map(int, input().split()))
    repair_time = list(map(int, input().split()))
    customer_time = list(map(int, input().split()))

    '''
    결과
    '''
    result = 0

    '''
    로직
    '''
    # 방문 기록 저장
    customer_info = [[-1, -1] for _ in range(customer_num)]  # -1 : 아무것도 안정해진 상태
    # 기다리고 있는 고객 리스트
    recept_wait = deque()
    repair_wait = deque()
    # 창구 남은 시간
    recept_desks_left_time = [0] * recept_num
    repair_desks_left_time = [0] * repair_num
    # 처리 중인 고객
    recept_desks = [-1] * recept_num
    repair_desks = [-1] * repair_num

    time = 0
    flag = True
    while flag:
        # 접수 웨이팅
        for customer_id in range(customer_num):
            if customer_time[customer_id] == time:
                recept_wait.append(customer_id)

        # 접수 창구
        for recept_desk_id in range(recept_num):
            # 웨이팅 고객 접수 창구 넣기
            if recept_desks_left_time[recept_desk_id] == 0 and len(recept_wait) > 0:
                customer_id = recept_wait.popleft()
                recept_desks_left_time[recept_desk_id] = recept_time[recept_desk_id] - 1  # 시간 카운팅
                customer_info[customer_id][0] = recept_desk_id
                recept_desks[recept_desk_id] = customer_id
            elif recept_desks_left_time[recept_desk_id] != 0:
                recept_desks_left_time[recept_desk_id] -= 1  # 시간 카운팅

            # 수리 웨이팅
            if recept_desks_left_time[recept_desk_id] == 0 and recept_desks[recept_desk_id] != -1:
                repair_wait.append(recept_desks[recept_desk_id])
                recept_desks[recept_desk_id] = -1

        # 수리 창구
        for repair_desk_id in range(repair_num):
            # 웨이팅 고객 수리 창구 넣기
            if repair_desks_left_time[repair_desk_id] == 0 and len(repair_wait) > 0:
                customer_id = repair_wait.popleft()
                repair_desks_left_time[repair_desk_id] = repair_time[repair_desk_id] - 1  # 시간 카운팅
                customer_info[customer_id][1] = repair_desk_id
                repair_desks[repair_desk_id] = customer_id
            elif repair_desks_left_time[repair_desk_id] != 0:
                repair_desks_left_time[repair_desk_id] -= 1

            # 처리가 끝난 고객
            if repair_desks_left_time[repair_desk_id] == 0 and repair_desks[repair_desk_id] != -1:
                repair_desks[repair_desk_id] = -1

        time += 1
        # 모든 손님이 처리가 되었는지 확인
        all_customer_result = []
        for customer_id in range(customer_num):
            if customer_info[customer_id][1] == -1:  # 처리 안됨
                all_customer_result.append(False)
            else:
                all_customer_result.append(True)
        if False not in all_customer_result:
            flag = False

    # 타겟에 맞는 고객
    for customer in range(customer_num):
        if customer_info[customer][0] == target_recept - 1 and customer_info[customer][1] == target_repair - 1:
            result += customer + 1

    '''
    결과 출력
    '''
    print(f'#{test_case} {result if result > 0 else -1}')
