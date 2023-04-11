// chap. 8, Tree, p. 254

// stack, queue, SLL, DLL
// --> 선형

// 계층적 구조
// Tree는 계층적 구조를 표현하는 대표적 데이터구조
// ~ p.255

// ~ p.256 상단부

//  terminal node (종말, 단말 노드)
//  non-terminal node (비단말 노드)
//  child node 존재 유무에 따라서,
// p.256

// degree of a node (차수)  p.256
// 노드의 자식노드 개수
// degree of a tree
// == max(degree of a node)

// Height of a tree (트리의 높이), p.256
// == max(level)
// Level (레벨) 

// p.256 마지막 용어 == Forest (나무들의 집합)
//                    == set of trees

// p.257, 트리의 종류
//  ---> degree of a tree == 2
//       === binary tree
//       === 이진 트리

// p. 258 
// left subtree, right subtree

// p.259 이진트리의 성질

// 1. n개의 노드를 가진 이진트리에서
//      edge의 개수는 n-1개다.
//    트리에서 모든 노드는 부모로 가는 edge를 가진다.
//    단, root node는 제외

// 2. (p.260)
//    높이가 h인 이진 트리에는
//       노드가 최소 h개 있고,
//             최대 2^h - 1 만큼 있다.

// 3. (p. 260)
//    n개의 노드를 가지는 이진트리의 높이는
//    최대 n이거나,
//    최소 log_2(n+1)
//       n <= 2^h - 1
//       n + 1 <= 2^h
//       log_2(n+1) <= h

// p. 261
// 이진트리의 분류

// 1. full binary tree
// 2. complete binary tree

// tree --> binary tree --> binary search tree (BST)

// Traversal (방문)
// 3가지 방문 방법, p.267, 이진 트리의 순회 (traversal)
// 1. pre-order traversal (전위 순회)
// 2. in-order traversal  (중위 순회)
// 3. post-order traversal (후위 순회)

#include <stdio.h>
#include <stdlib.h>

#define STACK_SZ 10
#define QUEUE_SZ 10

// BST의 노드를 표현
struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct combo {
	struct node* parent;
	struct node* me;
};

struct node* stack[STACK_SZ];
int top = -1;

struct node* queue[QUEUE_SZ];
int front = 0;
int rear = 0;

// root node를 가리키는 포인터
struct node* root = 0;

void enqueue(struct node* _cur) {
	// queue full
	if ((rear + 1) % QUEUE_SZ == front) {
		return;
	}
	queue[rear] = _cur;
	rear = (rear + 1) % QUEUE_SZ;
	return;
}

struct node* dequeue(void) {
	// queue empty
	if (front == rear) {
		return 0;
	}
	struct node* res = queue[front];
	front = (front + 1) % QUEUE_SZ;
	return res;
}




void push(struct node* _cur) {
	if (top == (STACK_SZ - 1)) {
		// stack full
		return;
	}
	top++;
	stack[top] = _cur;
}

struct node* pop(void) {

	if (top == -1) {
		return 0;  //  if stack is empty, null을 반환,
	}
	struct node* temp = stack[top];
	top--;
	return temp;
}
// 비재귀적으로 inorder traversal을 수행
void nonrecurvise_inorder(struct node* _cur) {
	while (1) {
		while (1) {  // 왼쪽으로 내려가면서 push
			if (_cur != 0) {
				push(_cur);
				_cur = _cur->left;
			}
			else {
				break;
			}
		}
		_cur = pop();
		if (_cur == 0) {
			break;
		}
		printf("%d\n", _cur->data);
		_cur = _cur->right;
	}
}



// _v값을 가지는 노드를 만들어서 BST에 추가
void addToBST(int _v) {
	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->left = 0;
	_new->right = 0;
	_new->data = _v;

	// BST에 노드를 추가
	// 1. BST가 텅텅 비어있는 경우
	if (root == 0) {
		root = _new;
		return;
	}

	// 2. BST에 뭔가 있는 경우,
	// 이 때는 자기 위치를 찾아 가야 한다. 어디가서 붙어야 하는지
	// root를 움직일 수 없으니, 별도의 포인터 필요
	struct node* spear = root;

	while (1) {

		if (spear->data < _new->data) {  // _new는 오른쪽에 추가되어야 하는 상황

			// 1. 그 자리가 비었네,
			if (spear->right == 0) {   // 빈자리에 넣고 끝!!!!
				spear->right = _new;
				return;
			}
			else {
				// 2. 아, 누군가 그 자리를 차지하고 있어서, 더 내려가 봐야 하는 상황
				spear = spear->right;
			}
		}
		else {  // 왼쪽으로 가야하는데....

			// 1. 그 자리가 비었네,
			if (spear->left == 0) {   // 빈자리에 넣고 끝!!!!
				spear->left = _new;
				return;
			}
			else {
				// 2. 아, 누군가 그 자리를 차지하고 있어서, 더 내려가 봐야 하는 상황
				spear = spear->left;
			}
		}
	}
}

void traversal_preorder(struct node* _cur) {
	if (_cur == 0) {
		return;
	}
	printf("%d\n", _cur->data);
	traversal_preorder(_cur->left);
	traversal_preorder(_cur->right);
}

void traversal_inorder(struct node* _cur) {

	if (_cur == 0) {
		return;
	}
	traversal_inorder(_cur->left);
	printf("%d\n", _cur->data);
	traversal_inorder(_cur->right);
}

// 재귀함수는 위험해!!!,
// 재귀함수없이 inorder를 구현해 보자.
// 어떻게???-->p.277

// 레벨 순회 --> p. 279

int which_is_bigger(int a, int b) {

	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

// 높이 구하기,  p. 289
int get_height(struct node* _cur) {

	if (_cur == 0) {  // NULL
		return 0;    // height
	}

	return(1 + which_is_bigger(get_height(_cur->left), get_height(_cur->right)));
}

// 노드 갯수 구하기, p.288
int get_node_count(struct node* _cur) {
	if (_cur == 0) {
		return 0;
	}

	return 1 + get_node_count(_cur->left) + get_node_count(_cur->right);
}

// p.289, 단말노드 갯수 구하기
int get_terminalnode_count(struct node* _cur) {

	// 탈출조건
	if (_cur == 0) {
		return 0;
	}
	else if (_cur->left == 0 && _cur->right == 0) {
		return 1;
	}

	return get_terminalnode_count(_cur->left) + get_terminalnode_count(_cur->right);

}

// p. 283
// 8.7 트리의 응용: 수식 트리 처리
// 그림 8-32


// p. 289끝!!!
void level_order(struct node* _cur) {
	if (_cur == 0) {  // BST에 아무 것도 없는 경우
		return;
	}
	enqueue(_cur);

	while (1) {
		if (front == rear) {
			break;
		}
		_cur = dequeue();
		printf("%d\n", _cur->data);
		if (_cur->left != 0) {
			enqueue(_cur->left);
		}
		if (_cur->right != 0) {
			enqueue(_cur->right);
		}
	}
}
struct combo findNodeCombo(int _v) {
	struct node* spear = root;

	if (root == 0) {
		struct combo res = { 0, 0 };
		return res;
	}
	if (root->data == _v) {
		struct combo res = { 0, root };
		return res;
	}
	struct node* parent = 0;
	while (1) {
		if (spear == 0) {
			struct combo res = { 0, 0 };
			return res;
		}
		if (spear->data == _v) {
			struct combo res = { parent, spear };
			return res;
		}
		if (spear->data < _v) {
			parent = spear;
			spear = spear->right;
		}
		else {
			parent = spear;
			spear = spear->left;
		}
	}
}
struct node* findNode(int _v) {
	struct node* spear = root;

	while (1) {
		if (spear == 0 || spear->data == _v) {
			return spear;
		}
		if (spear->data < _v) {
			spear = spear->right;
		}
		else {
			spear = spear->left;
		}
	}
}

void delFromBST(int _v) {
	struct combo res = findNodeCombo(_v);
	if (res.me == 0) {
		return;
	}

	if (res.me->left == 0 && res.me->right == 0) { // 무자식
		if (res.parent == 0) {  // root
			root = 0;
			free(res.me);
			return;
		}
		free(res.me);
		if (res.parent->left == res.me) {
			res.parent->left = 0;
		}
		else {
			res.parent->right = 0;
		}
		return;
	}
	else if (res.me->left != 0 && res.me->right != 0) {
		// 쌍자식
		struct node* spear = res.me->right;
		while (spear->left != 0) {
			spear = spear->left;
		}
		int saved = spear->data;
		delFromBST(saved);
		res.me->data = saved;
		return;
	}
	else {
		if (res.me->left != 0) {  // 남은 왼자식
			if (res.parent->left == res.me) {
				res.parent->left = res.me->left;
			}
			else {
				res.parent->right = res.me->left;
			}
			free(res.me);
			return;
		}
		else {  // 남은 오른자식
			if (res.parent->left == res.me) {
				res.parent->left = res.me->right;
			}
			else {
				res.parent->right = res.me->right;
			}
			free(res.me);
			return;
		}
	}
}

int main(void) {

	addToBST(20);
	addToBST(10);
	addToBST(30);
	addToBST(40);
	addToBST(5);

	/*
		findNode
	*/
	//struct node* temp = findNode(6);
	//if (temp == 0) {
	//	printf("cannot find\n");
	//}
	//else {
	//	printf("found %d\n", temp->data);
	//}

	/*
		findNodeCombo
	*/
	//struct combo res = findNodeCombo(20);
	//if (res.parent == 0 && res.me == 0) {
	//	printf("not found\n");
	//}
	//else if (res.parent == 0 && res.me != 0) {
	//	printf("root found %d\n", res.me->data);
	//}
	//else {
	//	printf("%d   %d  \n", res.parent->data, res.me->data);
	//}

	delFromBST(30);
	level_order(root);

	return 0;
}
