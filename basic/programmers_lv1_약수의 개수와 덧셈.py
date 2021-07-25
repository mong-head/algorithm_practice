def solution(left, right):
    nums = list(range(left,right+1))
    square = [i*i for i in range(1,32)]
    return sum(list(map(lambda num: -1 * num if num in square else num, nums)))  
