def solution(nums):
    set_nums = set(nums)
    return len(set_nums) if len(set_nums) < len(nums)/2 else len(nums)/2
