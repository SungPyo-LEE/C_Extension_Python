# Cpython_algo_study
Cpython으로 공부하는 알고리즘

## C언어로 Python 라이브러리 컴파일 하기
* 1 Hello World!
** C로 컴파일 된 Python 모듈 만들기 첫단계

 ```sh
$ python hello_setup.py install
$ python
>> import hello
>> print(hello.hello_world())
Hello, World!
>> print(hello.hello("SAXYCOW!"))
Hello, SAXYCOW!
```

* 2 덧셈 모듈 만들기
** C로 컴파일 된 Python 덧셈 모듈 만들어보기

 ```sh
$ python plus_mod_setup.py install
$ python test.py
```
간단한 테스트. C로 돌린 덧셈 반복문과 python 덧셈 반복문의 시간차이

* 3 배열 반환하기
** C함수에서 배열값을 반환하기 위해 Numpy를 사용하자
***1 Numpy Array를 C함수로 Return 할 수 있다.

* 4 배열을 Input 값으로 받기
** C에서 파이썬 List 자료형을 input 값으로 받아보자.
***1 python 공식적으로 적용하는 C api Pyobejct O!를 이용. List를 Input 값으로 받을 수 있다.
***2 Numpy Array를 Input 값으로 받기
 ```sh
$ python setup.py install
$ python
>> import input_arr
>> a = [1,2,3,4,5]
>> print(input_arr.list_size(a))
5
>> 2d_list = [[1,2,3],[4,5,6]]
>> print(input_arr.list_size(2d_list))
2
>> print(input_arr.list_size(2d_list[0]))
3
>> import numpy as np
>> np_arr = np.array([1,2,3,4,5])
>> print(input_arr.array_size(np_arr))
5
>> np_2d_arr = np.array([[1,2,3],[4,5,6]])
>> print(input_arr.array_size(np_2d_arr))
3
```
*** array size와 list size 함수의 차이점. 나중에 더 자세히 살펴보자.
*** 일단은 Numpy와 Python 기본 List 자료형을 모두 Input 값으로 받았다.

* 5 이제 재귀함수부터 해보자.
** Python에서 포인터를 사용 할 수 있다는 가능성을 봤다.
1 recursive sum을 이용하여 재귀적으로 덧셈을 해보자. 역시 메모리 비효율적
2 일반 반복문 덧셈과 별로 차이가 안 난다.
3 피보나치 수열을 재귀함수로 뽑아보자. 메모리 주소 프린트는 덤이다.