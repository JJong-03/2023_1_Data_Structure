
#if 1
//p.146 큐(FIFO)
//stack : push, pop
//queue : enqueue (enter queue)
//		  dequeue (depart from queue)
//        departure <---> arrival
// 

//구현
//queue의 구현에도 배열을 사용한다.
// front, rear <--- 큐에서 위치를 나타내는 변수
// front : dequeue할 것이 있는 위치
// rear  : enqueue할 위치
// 
// 기본적인 queue의 방식이 circular queue이다.
// 일반적인 큐 구현방식은, dequeue되고 나서, 데이터를 한칸씩
// 앞으로 당기는 방식... 이것은 비효울적
// 
// queue도 isEmpty와 isFull이 존재
// 
// circular queue는 1칸을 비움으로서, empty와 full을 구분
// ********* 최대 저장 용량은 N - 1******
// 
#endif
#if 0
#include<stdio.h>
#define Q_SZ 5 // 최대 9 개, circular queue 일 경우
int que[Q_SZ];
int front = 0;// 중요한 위치 변수.
int rear = 0;

int isEmpty() {
	return (front == rear);
}
int isFull() { //rear 뒤에 front가 있으면 , full
	return ((rear + 1) % Q_SZ == front); 
}

void enqueue(int _v) {
	if (isFull()) {
		printf("error, Full\n");
		return;
	}
	// rear가 가리키고 있는 현재 위치에 놓는다
	que[rear] = _v;
	//rear을 1 증가시킨다...항상 한바퀴 돌아가는 행위를 생각
	rear = (rear + 1) % Q_SZ;
}

int dequeue(void) {
	//empty 체크
	if (isEmpty()) {
		return -999;// error표시
	}
	//front 위치에 있는 것 뽑기
	int result = que[front];
	//front 조정
	front = (front + 1) % Q_SZ;
	//뽑아 놓은 것 반환
	return result;
}

int main() {


	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	enqueue(5);
	enqueue(6);
	printf("%d\n", que[0]);
	printf("%d\n", que[1]);
	printf("%d\n", que[4]);




	return 0;
}
#endif


//p.162 덱
//deque (double ended queue)
// 
#if 0
#include<stdio.h>
#define Q_SZ 10 // 최대 9 개, circular queue 일 경우
int que[Q_SZ];
int front = 0;// 중요한 위치 변수.
int rear = 0;

int isEmpty() {
	return (front == rear);
}
int isFull() { //rear 뒤에 front가 있으면 , full
	return ((rear + 1) % Q_SZ == front);
}

void enqueue(int _v) {
	if (isFull()) {
		printf("error, Full\n");
		return;
	}
	// rear가 가리키고 있는 현재 위치에 놓는다
	que[rear] = _v;
	//rear을 1 증가시킨다...항상 한바퀴 돌아가는 행위를 생각
	rear = (rear + 1) % Q_SZ;
}

int dequeue(void) {
	//empty 체크
	if (isEmpty()) {
		return -999;// error표시
	}
	//front 위치에 있는 것 뽑기
	int result = que[front];
	//front 조정
	front = (front + 1) % Q_SZ;
	//뽑아 놓은 것 반환
	return result;
}
//deque이 되기 위한, 2가지 함수
//1, add_to_front
//먼저 front를 -1 움직여,,, 한바퀴 도는 것은 좀 생각
// front 위치에 _v를 넣는다                                                                                                                                                                                                                                          
void add_to_front(int _v) {
	if (isFull()) {
		printf("queue full");
		return;
	}
	front = (front - 1 + Q_SZ) %Q_SZ;     //<----한바퀴 역으로 도는 거
	que[front] = _v;
	return;

}
//2. del_from_rear
int del_from_rear() {
	//empty 인지 체크
	if (isEmpty()) {
		return -999;
	}
	//rear를 조정
	rear = (rear - 1 + Q_SZ) % Q_SZ;

	//rear위치의 값을 반환
	return que[rear];
}

int main() {

	add_to_front(10);
	enqueue(20);
	enqueue(30);
	add_to_front(40);
	while (!isEmpty()) {
		printf("%d\n", del_from_rear());
	}
}
#endif
