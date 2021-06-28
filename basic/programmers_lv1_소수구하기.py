from itertools import combinations

def solution(nums):
    combis = combinations(nums,3)
    combi_sum = [sum(combi) for combi in list(combis)]
    
    # 소수 list
    a = [False,False] + [True]*(max(combi_sum)-1)
    primes=[]
    for i in range(2,max(combi_sum)+1):
        if a[i]:
            primes.append(i)
            for j in range(2*i, max(combi_sum)+1, i):
                a[j] = False
    
    result = [num for num in combi_sum if num in primes]
    
    return len(result)