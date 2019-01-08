## 수학1
- 나머지
    - https://www.acmicpc.net/problem/10430
	- [내 소스](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/Mod.cpp)
    ```
    (A + B) % C = ((A % C) + (B % C)) % C
    (A * B) % C = ((A % C) * (B % C)) % C
    (A - B) % C = ((A % C) - (B % C) + C) % C
    나누기의 경우에는 성립하지 않음 (Modular Inverse를 구해야한다)
    ```