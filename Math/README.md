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
    - [내 소스 1](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/GCDandLCM.cpp)
    - [내 소스 2_유클리드 호제법 사용](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/GCDandLCMwithEuclidean.cpp)
    - [유클리드 호제법이란?](https://hellowoori.tistory.com/27)
- 최소공배수
    - https://www.acmicpc.net/problem/1934
    - [내 소스 1_비재귀](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/LCM.cpp)
    - [내 소스 2_재귀](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/LCM_recursive.cpp)
- GCD의 합
    - https://www.acmicpc.net/problem/9613
    - [내 소스](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/SumOfGCD.cpp)
- 진법 변환 2
    - https://www.acmicpc.net/problem/11005
    - [내 소스](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/ConvertFromDecimalToBaseN.cpp)
    ```
    - 10진법 수 N을 B진법으로 바꾸려면 N이 0이 될때까지 나머지를 계속해서 구하면 된다.
    - 11을 3진법으로 바꾸는 방법
    - 11 / 3 = 3 ... 2
    -  3 / 3 = 1 ... 0
    -  1 / 3 = 0 ... 1
    - 따라서 11은 3진법으로 102이다.
    ```
- 진법 변환
    - https://www.acmicpc.net/problem/2745
    - [내 소스](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/ConvertFromBaseNToDecimal.cpp)
    ```
    - B진법 수 N을 10진법 수로 바꾸려면 B^k를 곱하면서 더해가면 된다.
    - 3진법 수 102 = 1 * 3^2 + 0 * 3^1 + 2 * 3^0 = 11
    ```
- 2진법 8진법 ⚠️
    - https://www.acmicpc.net/problem/1373
    - [내 소스](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/ConvertFromBinaryToOctal.cpp)
- 8진법 2진법 ⚠️
    - https://www.acmicpc.net/problem/1212
    - [내 소스](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/ConvertFromOctalToBinary.cpp)
- -2진수
    - https://www.acmicpc.net/problem/2089
    - [내 소스](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/ConvertFromDecimalToMinusBinary.cpp)
- Base Conversion
    - https://www.acmicpc.net/problem/11576
    - [내 소스](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/BaseConversion.cpp)
- 소수 찾기
    - https://www.acmicpc.net/problem/1978
    - [내 소스](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/FindPrime.cpp)
- 소수 구하기 ⚠️
    - https://www.acmicpc.net/problem/1929
    - [내 소스](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/FindPrime2.cpp)
- 골드바흐의 추측
    - https://www.acmicpc.net/problem/6588
    - [내 소스](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/Goldbach's_Conjecture.cpp)
- 소인수분해 ⚠️(최적화해서 다시 풀어보기!)
    - https://www.acmicpc.net/problem/11653
    - [내 소스](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/PrimeFactorization.cpp)
- 팩토리얼
    - https://www.acmicpc.net/problem/10872
    - [내 소스](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/Factorial.cpp)
- 팩토리얼 0의 개수
    - https://www.acmicpc.net/problem/1676
    - [내 소스](https://github.com/HelloWoori/AlgorithmStudyWithBaekjoon/blob/master/Math/FactorialTheNumOfZeros.cpp)