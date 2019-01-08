## 수학 1
- 나머지
    - https://www.acmicpc.net/problem/10430
	- [내 소스](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/Mod.cpp)
    ```
    (A + B) % C = ((A % C) + (B % C)) % C
    (A * B) % C = ((A % C) * (B % C)) % C
    (A - B) % C = ((A % C) - (B % C) + C) % C
    나누기의 경우에는 성립하지 않음 (Modular Inverse를 구해야한다)
    ```
- 최대공약수와 최소공배수
    - https://www.acmicpc.net/problem/2609
    - [내 소스 1](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/GCDandLCM.cpp.cpp)
    - [내 소스 2_유클리드 호제법 사용](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/GCDandLCMwithEuclidean.cpp)
    - [유클리드 호제법이란?](https://hellowoori.tistory.com/27)