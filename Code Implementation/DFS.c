#include<stdio.h>
#include<stdlib.h>
#define NUM_VTX 6

typedef struct node {
	int vtx;
	struct node* next;
}node;
node* graph[NUM_VTX];

int stack_dfs[NUM_VTX];
int top = -1;

void push(int v) {
	if (top == NUM_VTX - 1) return;
	top++;
	stack_dfs[top] = v;
	return;
}
int pop() {
	if (top == -1) return -999;
	int temp = stack_dfs[top];
	top--;
	return temp;
}
void _addEdge(int v1, int v2) {
	node* _v2 = (node*)malloc(sizeof(node));
	_v2->vtx = v2;
	_v2->next = 0;

	node* cur = graph[v1];
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

void addEdge(int v1, int v2) {
	_addEdge(v1, v2);

	_addEdge(v2, v1);
	return;
}

int checkDuplication(int v) {

	if (top == -1) {
		return 0;
	}

	for (int i = 0; i <= top; i++) { // stack을 다 뒤지면서 v가 있는지 검사
		if (stack_dfs[i] == v) {
			return 1;
		}

	}
	return 0;
}
void do_DFS(int v) {
	int visited[NUM_VTX] = { 0, };
	
	push(v);

	while (1) {
		int m = pop();
		if (m == -999) {
			break;
		}
		visited[m] = 1;
		printf("%d vertex를 방문했음 \n", m);
		node* _cur = graph[m];
		while (_cur != 0) {
			if (checkDuplication(_cur->vtx) == 0 && visited[_cur->vtx] == 0) { //중복 제외 + 방문 x
				push(_cur->vtx);
			}
			_cur = _cur->next;
		}
	}
}

int main() {
	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(0, 3); 
	addEdge(1, 4);
	addEdge(2, 4);
	addEdge(2, 3);
	addEdge(3, 5);
	addEdge(4, 5);

	do_DFS(0); // 0번 vertex부처 시작해서 DFS 시행

	return 0;
}
