
//2장 recursion : 재귀 함수
//recursion을 이용해서 factorial을 계산해 보자
#include<stdio.h>
int factorial(int x) {
	//탈출 조건
	if (x == 1) {
		return 1;
	}
	return x * factorial(x - 1);
}
//recursion의 문제는 ex) x에 100을 넣었을 때 100,99,98~1까지의 값을 위한 메모리를 뺏고 다시 돌려주는 방식이기
//때문에 값이 커지면 너무 많은 값을 뺏어버린다.
int main() {
	int x = 0;
	scanf("%d", &x);
	int k = factorial(x);
	printf("factorial의 값은 %d이다.", k);
	return 0;
}

//반복을 이용한 factorial 계산
int factorial(int n) {
	int result = 1;
	int i;
	for (int i = 1; i <= n; i++) {
		result = result * i;
	}
	return result;
}

// p.50 거듭제곱값의 계산

거듭제곱 power

recursion power 빠른 버전  2^10 = 4^5  2^5 대신에 4^5를 이용하면 10에서 5로 반이 줄어든다
 2^10 = 4^5 = 4* 16^2 =  = 4* (16^2)^1
int my_power_fast(int a, int b) {
	if (b == 1) {
		return a;
	}
	//b 짝수 
	if (b % 2 == 0) {
		return my_power_fast(a * a, b / 2);
	}
	//b 홀수
	else {
		return a * my_power_fast(a * a, (b - 1) / 2);
	}
}


//recursion power  ---> o(n)
int my_power_recursion(int a, int b) {
	
	if (b == 1) {
		return a;
	}
	return a * my_power_recursion(a, b - 1);
}


//반복을 이용한 해법 ---> o(n)
int my_power(int a, int b) {
	int res =1;
	int i;
	for (int i = 1; i <= b; i++) {
		res = res * a;
	}
	return res;
}
int main() {
	int res = my_power(2, 3);
	printf("%d", res);
	return 0;
}

//p.53 피보나치 수열의 계산
//0,1,1,2,3,5,8,13
//반복 이용
//n번째 피보나치 값을 반환하는 함수
// 0번째 : 0
// 1번째 : 1
// 2번째 : 1

//recursion을 이용한 fibonachi  계산
int fibo_r(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return fibo_r(n - 2) + fibo_r(n - 1);
}
// 
// 0 1 1 2 3 5 8 13 21 
//반복을 이용한 계산
	int fibo(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;

		int pp = 0; // previous~ previous
		int p = 1; //previous
		int result = 0;// 결과값
		for (int i = 2; i < p; i++) {
			result = pp + p;
			pp = p;
			p = result;
		}
		return result;
	}

	하노이 타워 p.56
	 n: 몇 개의 접시를 옮기는지 ,,, n개의 접시를 옮겨라
	 from 폴대에서
	 temp 폴대에서 임시 사용
	 to 폴대로 옮기시오
/*
void hanoi_tower(int n , int from, int temp , int to) {
		if (n == 1) {
			printf("%d에서 %d로 돌을 한 개 움직입니다.\n", from, to);
			return; 
	    }

		hanoi_tower(2, 1, 3, 2);
		hanoi_tower(n - 1, from, to, temp);
		
		돌 하나만, from에서 to 로 옮긴다.
		printf("%d에서 %d로 돌을 한 개 움직입니다.\n", from, to);
		
		hanoi_tower(2, 2, 1, 3);
		hanoi_tower(n - 1, temp, from, to);

	}

int main() {
		hanoi_tower(3, 1, 2, 3);
		return 0;
}
