#if 0
//_v값을 가진 노드를 찾아서 삭제
void delFromSLL(int _v) {

	//_v값을 가진 노드를 찾는다.
	struct node* spear = findSLL(_v);

	if (spear == 0) { //못 찾으면, thank you
		return;
	}

	//주의할 케이스
	//지워야 하는 것이 head인 경우

	if (head == spear) {
		//head 대피
		head = head->next;
		//폭파
		free(spear);
		return;
	}

	//나머지 케이스
	//spear 꽂힌 노드가 중간에 있는 경우

	struct node* prev = head;
	//prev가 창꽂힌 노드의 직전 노드가 될 때까지 이동

	while (prev->next != spear) {
		prev = prev->next;
	}

	prev->next = spear->next;
	free(spear);
	return;

}

int main() {
	addToSLL(10);
	addToSLL(20);
}
#endif

#if 0
void addToDLL(int _v) {
	struct node* _new = createNode(_v);

	if (head == 0) { //비어있는 경우
		head = _new;
		return;
	}

	//끝을 찾아서 추가
	struct node* spear = head;
	while (spear->next != 0) { //맨 끝의 노드를 찾아가는 과정
		spear = spear->next;
	}

	//이순간, spear는 마지막 노드를 콕 찌르고 있음
	//팔 연결, 악수!!
	spear->next = _new;
	_new->prev = spear;

	return;
}

//뒤에서부터 앞으로 하나씩 출력

void displayReverseDLL(void) {

	//empty list 확인
	if (head == 0) {
		return;
	}

	struct node* spear = head;
	while (spear->next != 0) {
		//spear는 맨 끝의 node를 가리키고 있음
		spear = spear->next;
	}

	//거꾸로 오면서 하나씩 출력
	while (spear != 0) {
		printf("%d\n", spear->data);
		spear = spear->prev;
	}

	return;
}

//_t를 가진 node를 찾아서
//주소를 반환 

struct node* findNode(int _t) {
	struct node* spear = head;

	while (spear != 0) {
		if (spear->data == _t) {
			return spear;
		}
		spear = spear->next;
	}
	return spear;
}

//_t: 찾아야 할 노드
//_v: 추가해야 할 노드

void insertIntoDLL(int _t, int _v) {

	//_t를 가진 노드 찾기
	struct node* spear = findNode(_t);

	if (spear == 0) {
		return; //_t를 가진 노드가 없음
	}

	//이제, 추가하자... spear 뒤에...
	struct node* _new = createNode(_v);

	//아쉬운 애가 손을 연결한다.
	_new->prev = spear;
	_new->next = spear->next; //null인 경우도 상관없음
	spear->next = _new;

	//여기가 중요!!!
	//내 뒤에 누가 있는 경우에만,
	if (_new->next != 0) { //반드시 null이 아닐 경우를 체크해주어야 함.
		_new->next->prev = _new;

	}
}

//_t를 가진 노드를 삭제
void delFromDLL(int _t) {
	//_t를 가진 노드를 찾는다.
	struct node* spear = findNode(_t);
	if (spear == 0) { //thank you
		return;
	}

	//인생 꼬이는 경우

	//1. 하필 spear == head, head 주의
	if (spear == head) {
		//head 대비
		head = head->next;
		//폭파
		free(spear);
		if (head != 0) {
			head->prev = 0;
		}

		return;
	}


	//2. 중간 혹은 끝에 있는 노드
	spear->prev->next = spear->next; //죽겠지...
	if (spear->next != 0) {// 내 뒤에 누가 있을 때만
		spear->next->prev = spear->prev;
	}
	free(spear); //폭파
	return;

}

int main() {
	addToDLL(10);
	addToDLL(20);
	addToDLL(30);

	//displaDLL();
	//20을 가진 노드를 찾아서, 90을 가진 노드를 뒤에 추가
	insertIntoDLL(20, 90);
	displayReverseDLL(90); //90을 가진 노드를 찾아서 가져온다

	displayReverseDLL();


	return 0;
}
#endif

