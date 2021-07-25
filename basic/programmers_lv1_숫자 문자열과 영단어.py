def solution(s):
    num_dic = {'0':'zero','1':'one','2':'two','3':'three','4':'four','5':'five','6':'six','7':'seven','8':'eight','9':'nine'}
    for num in num_dic :
        if num_dic[num] in s :
            s = s.replace(num_dic[num],num)
    return int(s)
