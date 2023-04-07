03.배열, 구조체, 포인터 p.70
배열: 같은 데이터타입, 순차적으로, 0번 ~n - 1번p.73 구조체
- 새로운 데이터타입을 만드는 기능
- 데이터 타입이 다른 것들을 모아서 만들 수 있다.
사람에 한 데이터를 저장하고 시다
사람마다 고유 번호가 있고 , 나이 정보를 저장하고 싶다.
*/
//typedef struct() {
//	int id;
//	int age;
//	float height;
//}person;
//
//int main() {
//	person a;
//	a.id = 1;
//	a.age = 20;
//	a.height = 170.0;
//
//}
//
//p.89 포인터, pointer
//데이터 타입 중의하나
//int char : 값을 담는 데이터 타입
//pointer type : 주소를 담는 데이터 타입

#if 0
int main() {
	int = 10;
	
	//변수가 저장된 위치(주소)를 접근하기 위한
	//수단 ===> pointer

	//주소를 저장하기 위한 데이터 형, pointer type

	int*// *:주소를 저장하는 타입 의미, 
		 //int:포인터를 이용해서 그 위치에서 1번에 읽고 쓸 수 있는 데이터량, int == 4 byte
		//pa와 pc가 차지하는 메모리 공간의 크기는 다를까? 1번에 읽고 쓸 수 있는 데이터량은 4byte,1byte인데
		//but 주소를 가져오는 것이기 때문에 pa와 pc가 차지하는 메모리 공간의 크기는 같다. 4byte
	int* pa;
	char* pc;
	float* pf;
	//p.91 null pointer
	//아무것도 가리키지 않는 포인터.
	//NULL, 0 ==> 포인터 변수 안에 저장된 주소가 올바른 것인지, 아닌지 구분해 주는 역할
	int* pa; = 0;
	int* pb = NULL;

	//p.90 포인터 연산자
	//1. 주소 연산자, &
	//int a = 10;
	//&a // 변수 a가 저장되어 있는 메모리 상의 주소
	//int* pa = 0;
	//&pa //포인터가 가리키는 주소상의 주소

	//2. 간접참조연산자, *
	// 주의!!!!! 포인터변수에 대해서만 적용가능.
	//먼저 a의 주소를 100 , pa의 주소를 400이라고 가정한다.
	int a = 20;
	int* pa = &a; // a의 주소에 있는 값을 pa에 넣어준다. 100번지 a에 20이 들어가 있다면 *pa는 20을 출력한다. 
	printf("%d %d\n", a, *pa);
	printf("%d %d %d\n", &a, pa, &pa); // &a는 a의 주소인 100을 출력, pa는 a의 주소값인 100을 출력, &pa는 pa의 주소인 400을 출력한다. 
	
	
	
	
	
	return 0;
}
#endif
#if 0 
//p.91 함수 매개변수로 포인터 사용하기
//call by reference <---포인터 함수 이용
void change_two_num(int *a, int *b) {
	int temp;
	temp = *b;
	*b = *a; //왼쪽 write , 오른쪽 read
	*a = temp;
	return;
}

int main() {
	int a = 10;
	int b = 20;
	printf("%d %d\n", a, b);
	change_two_num(&a, &b);
	printf("%d %d\n", a, b);
	return 0;
}
#endif
#if 0
//p.92. 배열과 포인터
// 친밀한 관계
// 배열 : 같은 데이터형의 값들이 메모리의 "연속된 공간"에 저장되어 있는 것
// int a[10]; 10개 공간이 쭈루룩...
// 
int main() {

	int a[10];
	printf("%d %d\n", a[0], a[9]);

	//배열 이름은 포인터 그 자체
	printf("%d\n", a); //배열이 저장된 곳의 시작 위치, 주소, 배열이름은 포인터 그 자체.
	// a == &a[0]
	//a+1 == &a[1] // 인덱스 1의 위치와 a+1은 서로 같은 의미
	return 0;
}
#endif

#if 0
#include<stdlib.h> //standard library <== malloc, free

typedef struct{
	int a;
	char b;
}AAA;
int main() {
	//p.94, 동적 메모리 할당
	// 정적메모리: 컴파일할 때 사용하는 메모리양을 모두 결정
	// 동적메모리: 수행하면서 메모리 할당, 속도가 느려, 운영체제가 대빵, 그러나 원하는만큼 딱
	//					단, free를 안하면 메모리 낭비
	//					프로그램이 계속 수행되면, Malloc만 계속하고,free를 안 하면, Memory Leak
	// malloc(memory allocation)
	// free(메모리 해제)
	char* c = (char*)malloc(100);// 100바이트 공간을 할당해서 , 시작주소를 반환한다.
	char* p = (char*)malloc(sizeof(char) * 100);
	if (p == 0) {
		printf("메모리 없음!! \n");
		return -100;
	}
	p = (char*)malloc(200);
	free(c);
	free(p); //할당받은 공간을 운영체제에게 반환
	return 0;

	char* q = p;
	free (q);
	//p.96 구조체와 포인터
	AAA a;
	a.a = 10;
	a.b = 'a';

	AAA* pa;
	pa = &a;
	pa.a = 40;
	pa.b = 'c'

	pa = (AAA*)maloc(sizeof(AAA));
	pa.a = 50;
	pa.b = 'd';
	free(pa);
}
#endif

// Chapter 4
// Stack : LIFO형태이다 Last In First Out 
#if 0
void fun3() {
	return;
}

void fun2() {
	fun3();
}

void fun1() {
	fun2();
}

void fun3() {
	fun1();
}
//이러한 방식이 Call Stack 
#endif 
#if 0
//구현?
//입력되는 숫자를 저장하는 stack을 구현해 보자.
// 입력: push <-- stack에 값을 저장하는 operation
// 출력: pop  <-- stack에서 값을 꺼내는 operation
int main() {
	push(4);
	push(5);
	push(1);

	printf("%d\n", pop()); // --> 1
	printf("%d\n", pop()); // --> 5
	printf("%d\n", pop()); // --> 4 LIFO형태를 늘 기억하기

	return 0;
}
#endif
#if 0
#define STACK_SZ 10// 10개 까지만 push되는 stack

int stack[STACK_SZ];
int top = -1;// 현재 스택의 맨 꼭대기 위치 index
//stack이 full인지 검사
//full --> 1을 반환
//아니면 --> 0을 반환
int isFull(void) {
	return (top == (STACK_SZ - 1));
}
// stack이 비어있는지 확인
// 1: 비어있으면, 
// 0: 아니면
int isEmpty() {
	return(top == -1);
}
//push, pop
void push(int _v) {
	
	if (isFull()) { // 더이상 push가 불가능
		printf("Error, Stack Full");
		return;
	}
	top++;
	stack[top] = _v;
	return;
}
int pop() {
	
	
	// 1% 아주 가끔 일어나는 에러상황
	if (isEmpty()) {
		printf("Stack Empty");
		return -999; /// -999는 에러상황을 나타내는 특수숫자로 가정
	}
	// 99% 확률로 일어나는 일
	int result = stack[top]; // top에 있는 것을 넣어주고
	top--;
	return result;
}

int main() {
	push(4);
	push(5);
	push(6);
	push(7);

	pop();
	printf("%d\n", pop()); // 올바르게 스택이 구현되었다면 ,6

	return 0;
}
#endif	
#if 0
#include<stdio.h>
//미로부터 그려보자
// 2차원 배열 ,char
// '1'이 저장되어 있으면, 벽
// '0'가 저장되어 있으면, 공간
//미로의 크기, 가로 6칸, 세로 6칸

// x,y좌표를 저장하는 데이터형
//row, column 좌표를 저장하는 데이터형
#define MAZE_SIZE 6
#define STACK_SIZE MAZE_SIZE *MAZE_SIZE
typedef struct{
	int r;
	int c;
}LOC;

LOC stack[STACK_SIZE];
int top = -1;

char maze[6][6] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'}, // e : entrance
	{'1','0','0','0','1','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','0','x'}, // x : exit
	{'1','1','1','1','1','1'}
};

//미로를 예쁘게 출력해보는 함수
void printMaze() {
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			printf("%c ", maze[i][j]);
		}
		printf("\n");
		
	}
}

int isFull() {
	return (top == (STACK_SIZE - 1));
}

int isEmpty() {
	return (top == -1);
}
//push할 좌표(_r, _c)를 받아서,
//앞으로 갈 곳들만 stack 에 push한다.
//벽('1'), 지나온 곳('0'), 음수 좌표등은 모두 제외.
void push(int _r, int _c) {
	
	//음수 좌표를 거르자
	if ((_r < 0) || (_c < 0)) {
		return;//무시
	}
	//벽, 지나온 곳 거르기
	if (maze[_r][_c] == '1' || maze[_r][_c] == '.'){
		return;
	}

	//full 인지 검사
	if (isFull()) return;

	//걸러내기 끝 이제 진짜로 push
	LOC temp = { _r,_c };
	top++;
	stack[top] = temp;
	return;
}
LOC pop() {
	//에러조건 
	if (isEmpty()) {
		LOC err_loc = { -1, -1 }; // 스택이비었다는 의미
		return err_loc;
	}
	LOC result = stack[top];
	top--;
	return result;
}
int main() {

	LOC cur = { 1,0 }; // 시작 위치
	while (1) {
		//탈출 조건 ==> x에 도착하면 끝
		if (maze[cur.r][cur.c] == 'x') {
			printf("길 찾았음... 집간다. \n");
			return 0;
		}
		//내가 다녀갔음을 표시 
		maze[cur.r][cur.c] = '.'; // 나의 발자국을 남긴다. Why? 다시 오지 않기 위해서

		//잠깐, 지도를 보자
		printMaze();

		// 현재 위치에서 갈 수 있는 곳들을 모두 stack 에 집어 넣는다.
		//모두 4군데, 상/하/좌/우.
		push(cur.r - 1, cur.c);
		push(cur.r + 1, cur.c);
		push(cur.r, cur.c - 1);
		push(cur.r, cur.c + 1);

		//스택에 저장된 좌표를 꺼내서 반복적으로 시행한다.
		cur = pop();

		//스택이 비어있는지 확인. 만약 비었다면 ===> 길 없음.
		if ((cur.r == -1) && (cur.c == -1)) {
			printf("길 없음");
				return -1;
		}
	}

	return 0;
}

#endif
