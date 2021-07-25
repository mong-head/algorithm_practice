def solution(lottos, win_nums):
    min = sum([-1 if lotto in win_nums else 0 for lotto in lottos]) + 7
    max = min + sum([-1 if lotto == 0 else 0 for lotto in lottos])
    answer = [1 if max < 1 else 6 if max > 6 else max, 6 if min > 6 else min]
    return answer
