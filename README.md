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
1 Numpy Array를 C함수로 Return 할 수 있다.

* 4 배열을 Input 값으로 받기
** C에서 파이썬 List 자료형을 input 값으로 받아보자.
1 python 공식적으로 적용하는 C api Pyobejct O!를 이용 
2 Numpy Array를 Input 값으로 받기