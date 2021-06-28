import re

def solution(new_id):
    
    # 1
    answer = new_id.lower()
    
    # 2
    answer = re.sub('[^a-z0-9\-_.]','',answer)
    
    # 3
    answer = re.sub('\.+','.',answer)
    
    # 4
    answer = re.sub('^[.]|[.]$','',answer)
    
    # 5,6
    answer = 'a' if len(answer) == 0 else answer[:15]
    answer = re.sub('^[.]|[.]$','',answer)
    
    # 7
    answer = answer + "".join([answer[-1] for i in range(3-len(answer))]) if len(answer) <= 2 else answer
    
    return answer