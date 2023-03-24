// p.146 Queue (큐)

// 사자성어: FIFO (first in, first out)

// stack : push, pop
// queue : enqueue (enter queue)
//         dequeue (depart from queue)
//         departure <---> arrival

// 구현
// queue의 구현에도 배열을 사용한다.
// front, rear <--- 큐에서 위치를 나타내는 변수
// front : dequeue할 것이 있는 위치
// rear  : enqueue할 위치


// 지금 여러분이 본 큐의 구현 방식을 circular queue라고 합니다.
// 
// 일반적인 큐 구현방식은, dequeue되고 나서, 데이터를 한칸씩
// 앞으로 당기는 방식... 이것은 비효율적
//
// queue도 isEmpty와 isFull이 존재
// 
// circular queue는 1칸을 비움으로써, empty와 full을 구분
//    최대 저장 용량은 N - 1

#include <stdio.h>

#define Q_SZ 10  //최대 9개, circular queue일 경우
int que[Q_SZ];
int front = 0;  // 중요한 위치 변수, 
int rear = 0;

int isEmpty() {
	return (front == rear);
}

int isFull() {  // rear 뒤에 front가 있으면, full
	return  (((rear + 1) % Q_SZ) == front);
}

void enqueue(int _v) {
	if (isFull()) {
		printf("error, full\n");
		return;
	}
	// rear가 가리키고 있는 현재 위치에 넣는다.
	que[rear] = _v;
	// rear를 1개 증가시킨다.,, 항상 한바퀴 돌아가는 경우를 생각
	rear = (rear + 1)%Q_SZ;
	return;
}

int dequeue(void) {
	// empty 체크
	if (isEmpty()) {
		return -999; // error 표시, -999
	}
	// front 위치에 있는 것 뽑기
	int result = que[front];

	// front 조정
	front = (front + 1) % Q_SZ;

	// 뽑아 놓은 것 반환
	return result;
}

int main(void) {

	enqueue(4);
	enqueue(5);
	enqueue(7);

	while (!isEmpty()) {
		printf("%d\n", dequeue());  // 4, 5, 7
	}

	return 0;
}