from string import punctuation
import re

def solution(new_id):
    symbols = punctuation.replace('-', '').replace('_', '').replace('.','')
    
    # 1
    answer = new_id.lower()
    
    # 2
    for symbol in symbols : 
        answer = answer.replace(symbol,'')
        
    # 3
    answer = re.sub('\.\.+','.',answer)
    
    # 4
    if answer.startswith('.'):
        answer = answer[1:]
    if answer.endswith('.'):
        answer = answer[:-1]
    
    # 5
    if answer == "":
        answer += 'a'
    
    # 6
    if len(answer) > 15 :
        answer = answer[:15]
    if answer.endswith('.'):
        answer = answer[:-1]

    # 7
    if len(answer) < 3:
        while len(answer)!=3:
            answer += answer[-1]
    
    
    
    return answer