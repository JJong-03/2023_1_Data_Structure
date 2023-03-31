#if 0
#include <stdio.h>
#include <stdlib.h>   // malloc 때문에 필요

// linked list의 기본 요소인 node
// Linked List : LL
// Singly Linked List : SLL
typedef struct node {
	int data;
	struct node* next;
}node;
node* head = 0;
// stack에 top, queue에는 front/rear, linked list에는 head


// _v 정수값을 SLL의 끝에 추가한다.
// 점점 늘어나는 리스트의 역할
//
void addToSLL(int _v) {

	// _v값을 저장할 node를 메모리에 마련한다.
	// data type을 casting하는 이유
	//   malloc의 반환값은 void*
	//   type이 없으므로 (void), 적절한 type으로 casting
	// _new는 새로 할당받은 node 구조체의 주소를 가리키고 있다.
	//
	// 주의!! _new를 잃어버리면, 할당받은 공간을 다시 찾아갈 방법이 없음.
	//
	node* _new = (node*)malloc(sizeof(node));
	// -> 화살표를 사용하는 이유: _new가 포인터이기 때문에
	_new->data = _v;
	_new->next = 0; // 신규 노드는 뒤에 오는 노드가 없으므로, 0(null)로 초기화

	// _new를 기존 SLL에 추가

	// 경우의 수, 2가지
	// 1. 빈 SLL일 경우
	if (head == 0) {
		head = _new;
		return;
	}
	// 2. 아닌 경우

	// 2.1 기존 SLL에서 맨 끝의 노드의 주소를 알아낸다.
	node* temp = head; //new값이 들어간 head를 temp에 넣는다.
	while (temp->next != 0) {
		temp = temp->next;
	}

	// 2.2 맨끝 노드의 next에 새로운 노드의 주소를 집어넣는다.
	temp->next = _new;
	return;
}

void displaySLL(void) {

	node* temp = head;

	while (temp != 0) {

		printf("%d\n", temp->data);
		temp = temp->next;
	}
	return;
}

// SLL에 포함된 node개수를 반환
int countSLL(void) {
	node* temp = head;
	int cnt = 0;   // 노드 개수

	while (temp != 0) {
		cnt++;
		temp = temp->next;
	}
	return cnt;
}

// _v값을 가지는 노드를 찾아서,
// 그 노드의 주소를 반환
// 그래서, 반환값이 node*
// 반환값
//   - _v를 가진 노드의 주소
//   - 0 : 그런 노드가 없을 때
node* findSLL(int _v) {

	node* temp = head;

	while (temp != 0) {

		if (temp->data == _v) {
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}
void destroySLL(void) {

	node* spear = head;

	while (head != 0) {
		head = head->next;
		free(spear);
		spear = head;
	}
	return;
}

// _v를 가진 노드를 맨 앞에 추가
void addToFront(int _v) {
	// 새로운 node를 1개 할당받아서, _v를 저장, 그 노드를 _new가 가리킨다.
	node* _new = (node*)malloc(sizeof(node));
	_new->data = _v;
	_new->next = 0;

	// 경우의 수. 1 SLL== empty
	if (head == 0) {
		head = _new;
		return;
	}

	// 경우의 수. 2, SLL에 뭔가 있을 때.
	_new->next = head;   // SLL의 대원칙 == 인생의 대원칙 == 새로온 사람이 아쉽다. == 아쉽손
	head = _new;
	return;
}

int delFromFront(void) {

	if (head == 0) {
		return -999; // SLL이 텅비었다는 의미
	}

	node* spear = head;
	// head 대피
	head = head->next;
	// 데이터 복사보관
	int res = spear->data;
	// 폭파
	free(spear);
	// 저장값 반환
	return res;
}

int delFromLast(void) {

	// thank you. 1
	if (head == 0) {
		return -999;
	}

	// thank you.2,  single node
	if (head->next == 0) {
		int res = head->data;
		free(head);
		head = 0;
		return res;
	}

	// oh my god. 3
	// 1. 맨 뒤에서 두 번째 노드에 창을 꼽는다.
	node* spear = head;

	while (spear->next->next != 0) {
		spear = spear->next;
	}
	int res = spear->next->data;  // 데이터 대피
	//폭파
	free(spear->next);
	// 끝단 처리
	spear->next = 0;
	return res;
}


// _findv값을 가진 노드를 찾아서,
// 그 뒤에 _addv를 가진 새로운 노드를 추가한다.
void insertInto(int _findv, int _addv) {

	// _findv를 가진 노드가 없다면,
	node* target = findSLL(_findv);
	if (target == 0) {  // findv를 가진 노드가 없다. thank you.
		return;
	}
	node* _new = (node*)malloc(sizeof(node));
	_new->data = _addv;
	_new->next = 0;

	// 붙여넣기
	// SLL의 대원칙. 아쉽손
	_new->next = target->next;
	target->next = _new;
	return;
	
}

int main(void) {

	addToSLL(10);
	addToSLL(20);
	addToSLL(30);
	addToSLL(40);

	addToFront(90);
	addToFront(80);

	printf("%d\n", delFromFront());
	printf("%d\n", delFromFront());

	printf("%d\n", delFromLast());
	

	insertInto(20, 99);

	// SLL을 앞에서부터 뒤로 지나가면서
	// 각 노드에 저장된 값들을 출력한다.
	displaySLL();
	// countSLL  <--- SLL 안에 있는 노드 개수를 반환
	// 
	printf("SLL안의 노드 개수: %d\n\n", countSLL());

	// findSLL  <--- SLL 안에 있는 특정 노드 위치를 검색
	printf("20을 가진 노드의 주소 %x\n", findSLL(20));
	node* temp = findSLL(20);
	printf("%d\n", temp->data);  // ---> must be 20

	// destroySLL <--- SLL 노드를 모두 제거
	destroySLL();

	if (head != 0) {
		printf("제대로 destroy 하지 못했음.\n");
	}

	// done -- addToFront  <--- 맨 앞에 추가
	// done -- delFromFront <--- 맨 앞 것을 제거하고, 그 값을 반환, 
	// done -- delFromLast <--- 맨 끝 것을 제거하고, 그 값을 반환
	// done -- insertInto <--- 특정 노드를 찾아서, 그 뒤에 추가

	// 내일 하자!!! delFromSLL <--- 특정 노드를 찾아서 제거
	return 0;
}
#endif
