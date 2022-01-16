# Basic

* 개념 정비

## python

* data structure
  * list
    ```python
    list_ = [1,2,3,4,1,2,3,4]
    list_.count(2) #2
    ```

  * set
    * use set
      ```python
      list = [1,2,3,4,4,1]
      print(set(list)) #{1,2,3,4}
      ```
    * operator
      ```python
      list1 = [1,2,3,4]
      list2 = [2,3,4,5]
      print([set(list1) & set(list2)]) #[2,3,4]
      print([set(list1) | set(list2)]) #[1,2,3,4,5]
      print([set(list1) - set(list2)]) #[1]
      ```

  * dictionary
    ```python
    dict = {1:'one',2:'two'}
    print(dict[1]) #one
    ```

* util
  * map
    ```python
    list(map(lambda x:x*x, [1,2,3,4])) #[1,4,9,16]
    list(map(lambda a,b:a*b,[1,2,3,4],[-1,1,-1,1])) #[-1,2,-3,4]
    ```

* 순열, 조합
  * 순열
    ```py
    from itertools import permutations # 순열
    
    goTos = list(permutations([1,2])) # [(1,2),(2,1)]
    ```
    * 순서가 있는 조합, 중복은 포함하지 않음((1,1)등)
  * 중복 순열
    ```py
    from itertools import product      # 중복 순열

    # [-1,1]에서 나올 수 있는 모든 순서있는 조합 구하기
    directions = list(product(*[[-1,1]]*2)) # * : unpacking , *[[-1,1]]*2 : [-1, 1] [-1, 1]
    # 결과 : [(-1, -1), (-1, 1), (1, -1), (1, 1)]
    ```
    * 순서가 있는 조합, 중복 포함