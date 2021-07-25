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
