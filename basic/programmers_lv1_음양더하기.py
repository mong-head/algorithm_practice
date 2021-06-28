def solution(absolutes, signs):
    signs = [1 if i is True else -1 for i in signs ]
    answer = [absolutes[i]*signs[i] for i in range(len(signs))] 
    return sum(answer)