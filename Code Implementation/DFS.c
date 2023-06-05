#include <stdio.h>
#include <stdlib.h>

#define NUM_VTX 6

struct node {
	int vtx;
	struct node* next;
};

struct node* graph[NUM_VTX];

// DFS를 위한 stack 구현
int stack_dfs[NUM_VTX];
int top = -1;

// BFS를 위한 queue 구현
int queue_bfs[NUM_VTX];
int front = 0;
int rear = 0;

void enqueue(int v) {

	if (front == (rear + 1) % NUM_VTX) {
		return; // que full
	}
	queue_bfs[rear] = v;
	rear = (rear + 1) % NUM_VTX;

}
int dequeue() {
	if (front == rear) {  // queue empty
		return -999;
	}
	int res = queue_bfs[front];
	front = (front + 1) % NUM_VTX;
	return res;
}

void push(int v) {
	if (top == NUM_VTX - 1) {
		return;
	}
	top++;
	stack_dfs[top] = v;
	return;
}
int pop() {
	if (top == -1) {
		return -999; // stack이 비었음
	}
	int res = stack_dfs[top];
	top--;
	return res;
}
void _addEdge(int v1, int v2) { // v1 --> v2
	
	// v2로 가는 노드를 만든다.
	struct node* _v2 = (struct node*)malloc(sizeof(struct node));
	_v2->vtx = v2;
	_v2->next = 0;

	struct node* cur = graph[v1];

	if (cur == 0) {
		graph[v1] = _v2;
		return;
	}
	else {
		while (cur->next != 0) {
			cur = cur->next;
		}
		cur->next = _v2;
		return;
	}
}

void addEdge(int v1, int v2) {   // v1 --> v2, v2 --> v1
	// v1 --> v2
	_addEdge(v1, v2);
	// v2 --> v1
	_addEdge(v2, v1);
}

// _v에서 시작하여, DFS 시행
void do_DFS(int _v) {
	int visited[NUM_VTX] = { 0, }; // 모두 다 방문하지 않았음.
	
	push(_v);
	while (1) {
		int m = pop();
		if (m == -999) {
			break;
		}
		printf("%d vertex를 방문했음 \n", m);

		struct node* _cur = graph[m];
		while (_cur != 0) {
			if (visited[_cur->vtx] == 0) {
				visited[_cur->vtx] = 1;
				push(_cur->vtx);
			}
			_cur = _cur->next;
		}
	}
}

void do_BFS(int v) {

	int visited[NUM_VTX] = { 0, };

	enqueue(v);
	while (1) {

		int m = dequeue();
		if (m == -999) {
			break;
		}
		if (visited[m] != 1) {
			visited[m] = 1;
			printf("%d vertex를 방문하였음\n", m);
		}
		else {
			printf("%d----- 중복\n", m);
		}
		struct node* _cur = graph[m];
		while (_cur != 0) {
			if (visited[_cur->vtx] == 0) {
				enqueue(_cur->vtx);
			}
			_cur = _cur->next;
		}
	}

}

int main(void) {

	addEdge(0, 3); // 3 --> 0
	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(1, 4);
	addEdge(2, 3);
	addEdge(2, 4);
	addEdge(3, 5);
	addEdge(4, 5);
	
	do_DFS(0); // 0번 vertex부터 시작해서 DFS 시행
	//do_BFS(0); // 1번 vertex부터 시작해서 BFS 시행
	return 0;
}
