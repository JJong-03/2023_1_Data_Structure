//chap. 8, Tree, p.254

// stack, queue, SLL, DLL --> 선형

// 계층적 구조
// Tree는 계층적 구조를 표현하는 대표적 데이터구조

// node와 node를 이어주는 선을 edge라고 한다.

// Root Node => 처음 시작하는 노드
// Sub - Tree => 트리안에 트리
// ~ p.255
// parent node <=> child node
// sibling node => 자매 노드(child node 옆)
// ~ p.256 상단


// terminal node (종말, 단말 노드) child node가 X
// non-terminal node (비단말 노드) child node가 O
// child node 존재 유무에 따라서,
// ~ p.256


// degree (차수) p.256
// 노드의 자식노드 개수
// degree of a tree
// == max(degree of a node)

// Height of a tree (트리의 높이), p.256
// == max(Level)
// Level (레벨)

// p.256 마지막 용어 == Forest(나무들의 집합)
//                   == set of trees           

//	p.257, 트리의 종류
//  ---> degree of a tree <= 2 (2보다 작은 경우에는 생길 수 있기 때문에 가능하다.)
//       === binary tree 
//		 === 이진 트리 

// p.258
// left subtree, right subtree (이진 트리의 경우만 가능)

// p.259 이진 트리의 성질
// 
// 1. n개의 노드를 가진 이진트리에서
//		edge의 개수는 n-1개이다.
//		트리에서 모든 노드는 부모로 가는 edge를 가진다.
//		단, root node는 제외
		
 
// 2. (p.260)
//	  높이가 h인 이진 트리에는
//		노드가 최소 h개 있고,
//			최대 2^h - 1 만큼 있다.

// 3.(p.260)
//	n개의 노드를 가지는 이진트리의 높이는
//	최대 n이거나,
//	최소 log_2(n+1)
//		n = 2^h - 1
//		n + 1 = 2^h
//		h = log_2(n+1)
 
// p.261
// 이진트리의 분류   

// 1. full binary tree ==> 찰 수 있는 곳에는 다 차있어야 됨.
// 2. complete binary tree ==> 중간에 비어지지 않으면 됨. 위에서 아래로, 왼쪽부터 오른쪽으로

// tree --> binary tree --> binary search tree (BST) 
// 작으면 왼쪽, 크면 오른쪽으로

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;
// root node를 가르키는 포인터
node* root = 0;

void addToBST(int _v) {
	node* _new = (node*)malloc(sizeof(node));
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
	// root 를 움직일 수 없으니, 별도의 포인터 필요
	node* spear = root;
	
	while (1) {
		
		if (spear->data < _new->data) { // 오른쪽으로 가야하는데

			// 1. 그 자리가 비어있을 경우
			if (spear->right == 0) {
				spear->right = _new;
				return;
			}
			// 2. 자리가 없어서 더 내려가야하는 경우
			else {
				spear = spear->right;
			}

		}
		else { // 왼쪽으로 가야하는데
			// 1. 그 자리가 비어있을 경우
			if (spear->left == 0) {
				spear->left = _new;
				return;
			}
			// 2. 자리가 없어서 더 내려가야하는 경우
			else {
				spear = spear->left;
			}
		}

	}

}

int main() {

	addToBST(20);
	addToBST(10);
	addToBST(30);
	addToBST(40);
	addToBST(5);

	//printf("%d\n", (root->data == 20));
	//printf("%d\n", (root->left->data == 10));
	//printf("%d\n", (root->right->data == 30));
	//printf("%d\n", (root->right->right->data == 40));
	//printf("%d\n", (root->left->left->data == 5));

	return 0;
}

// Traversal (방문) 
// 3가지 방문 방법 , p.267, 이진 트리의 순회 (traversal)
// 1. pre-order traversal (전위 순회) => 자기부터 시작 왼쪽으로 쭉 갔다가 오른쪽으로 쭉 
// 2. in-order traversal  (중위 순회) => 왼쪽에서 오른쪽으로 (자동으로 오름차순 정렬)
// 3. post-order traversal(후위 순회) => Height 별로 아래부터 위로 올라감. 
// 
//
