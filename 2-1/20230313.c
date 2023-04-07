
#if 0
//p.128 중위표기식을 후위표기수식으로 변환
//후위표기식: postfix expression

	//1*2 + 3 : infix
    // 1 2 * 3 + : postfix

	// 1*2 + 3 : infix
	// 1 2 3 +* : postfix(괄호를 안 써도 됨.)


//p.135 스택의 응용 미로문제
#endif

#if 0
//postfix 계산
// //stack, LIFO (last in first out) 
// 우리가 사용하는 수식 : 2 + 3 , infix
// operator 위치 기준
// 컴퓨터가 계산할 때는 postfix 형태를 사용
// 2 + 3 --> 2 3 + 
// 
// postfix의 장점
// - 괄호를 사용하지 않고도 우선순위 표기가 가능
// 2 + 3 * 5 --> 2 3 5 * +
// (2+3) * 5 --> 2 3 + 5 *
// postfix의 계산
// 왼쪽에서 오른쪽으로 읽어나가면서 ,
// 연산자(+,-...) 만나면 앞의 2개 숫자로 계산 --> 숫자로 치환
// 끝까지 읽을 때까지 반복
// 
// 사람은 infix로 입력
// 컴퓨터는 1) infix --> postfix로 전환
//          2) postfix를 계산
// 
// postfix 수식 계산
//  구현을 간단히 하기 위해서 , 1자리 숫자
//  4칙연산, +, -, *, /, 정수형 계산
//  수식에 공백없이 입력
// 
// stack을 이용해서 구현하는 알고리즘 
//  stack을 하나 마련하고, 
//  수식을 왼쪽에서 오른쪽으로 읽어가면서
//  숫자면, stack에 push
//  연산자면, stack에서 2개를 pop하고,계산해서 다시 push
//  수식 끝날 때까지 계속 
//
//
#include<stdio.h>
#define STACK_SIZE 20

int stack[STACK_SIZE];   //stack 구현, 정수를 저장하는 공간
int top = -1;            // 맨 위에 저장된 숫자 위치 (index)

//push, pop, isFull, isEmpty
int isFull() {
	return (top == STACK_SIZE - 1);
}
int isEmpty() {
	return (top == -1);
}

void push(int _v) {
	// 예외, full
	if (isFull()) {
		printf("Full");
		return;
	}
	top++;
	stack[top] = _v;
	return;
}

int pop() {
	if (isEmpty()) {
		printf("Empty");
		return -999; // -999는 비었다는 특별한 값.
	}
	int result = stack[top];
	top--;
	return result;
}
/*
	v1과 v2를 받아서 op연산을 한 결과를 반환
	op: +, -, *, /
*/
int calc_expr(char op, int v1, int v2) {

	switch (op) {
	case'+':
		return (v1 + v1);
	case'-':
		return (v2 - v1);//순서 주의
	case'*':
		return (v1 * v2);
	case'/':
		return (v2 / v1);// 순서 주의
	default:
		break;
	}
}

int main() {
	char postfix[] = "235*+"; // postfix expression
	int idx = 0; // expression에서 현재 읽는 위치
	
	//왼쪽에서 오른쪽으로 한글자씩 읽는 코드
	//expression 끝에 도달할 때까지... NULL은 expression 끝인 null을 의미
	while (postfix[idx] != NULL) {

		// 숫자, 연산자, 둘 중 하나가 나온다.
		// 숫자인 경우 처리
		char _c = postfix[idx]; // 일단 복사, 이거 안해도 됨.
		if (_c >= '0' && _c <= '9') { //숫자 확인
			push((int)(_c - '0'));
		}
		else { // 숫자 아니면 연산자 4개중 하나가 들어온다고 가정하자 이외에 다른 것이 들어오면 else if
			//  (- , /)는 나중에 pop이 된 수가 앞으로 와야함.
			int v1 = pop();
			int v2 = pop();
			int res = calc_expr(_c, v1, v2);
			push(res);
		}

		idx++;
	}
	//여기에 왔다면, 스택에는 숫자 1개가 있어야 함!!
	printf("연산결과는 %d \n", pop());
	return 0;
}

#endif

// infix에서 postfix 만들어내기

// stack 이용

// 알고리즘
// 관찰점: 숫자 순서는 안바뀜
// 왼쪽에서 오른쪽으로 1글자씩 읽어나가면서,
// 숫자면 출력
// 연산자면 ???
//  - 기본적으로 push
//	- 단, 나보다 연산순위가 낮은 것이 있으면 
//		아니면, 연산순위 높은 것을 빼내고 push
//		1 + 2 * 3 --> 1 2 3 * +    --> 곱하기가 더하기를 깔아버림.
//		1 + 2 - 3 --> 1 2 + 3 -
//      1 + 2 - 3 * 5 --> 1 2 + 3 5 * -      --> 바로 다음 연산순위가 높은 것일 때 그 앞에 하나를 깔아버림. 아니면 그대로.
//	- 괄호가 나왔다. 2가지 종류, 여는 괄호 (, 닫는 괄호)
//		.. 여는 괄호는 무조건 push
//		.. 여는 괄호의 우선순위는 최하위로 취급
//		.. 닫는 괄호가 나오면, 여는 괄호 최초나올 때까지 pop하면서 연산자 출력
//    1 * (2 + 3) --> 1 2 3 + *
//	  1 * (2 / (3 + 4)) --> 1 2 3 4 + / *	 

#if 0
#include<stdio.h>
#define STACK_SIZE 20

char stack[STACK_SIZE];   //stack 구현, 기호가 들어가는 공간
int top = -1;            // 맨 위에 저장된 숫자 위치 (index)

//push, pop, isFull, isEmpty
int isFull() {
	return (top == STACK_SIZE - 1);
}
int isEmpty() {
	return (top == -1);
}

void push(char _v) {
	// 예외, full
	if (isFull()) {
		printf("Full");
		return;
	}
	top++;
	stack[top] = _v;
	return;
}

int pop() {
	if (isEmpty()) {
		printf("Empty");
		return '\0'; // \0은 비었다는 특별한 값.
	}
	char result = stack[top];
	top--;
	return result;
}


int amIHigher(char _c) {
//stack[top] 보다 현재의 연산 우선순위가 높으면 1반환.
	if (stack[top] == '(') { //호구 케이스
		return 1;
	}
	else if (_c == '*' || _c == '/') {
		if (stack[top] == '+' || stack[top] == '-') {
			return 1;
		}
	}
	// _c가 +, - 인 경우는 우선순위가 높을 수가 없다.
}

// 가정
// 숫자는 한자리, 1+2, 0 ~ 9
// 공백없음.
int main() {

	char infix_expr[] = "1*(2+3)"; // 1 2 3 + *
	int idx = 0;

	while (infix_expr[idx] != NULL) {
		// 1. 숫자면 출력
		//
		if (infix_expr[idx] >= '0' && infix_expr <= '9') {
			printf("%c", infix_expr[idx]);
		}
		else { //연산자, (, ), - 세 개 중에 하나
			if (infix_expr[idx] == '(') {
				push(infix_expr[idx]);
			}
			else if (infix_expr[idx] == ')') { //닫는 괄호면, 여는 괄호나올 때까지 pop하면서 연산자 출력
				
				while (1) {
					char _d = pop();
					if (_d == '(') {
						break;  // 더 이상 pop을 하지 않고, 넘어간다.
					}
					printf("%c", _d);
				}
			}
			else { // +, -, *, /
				// 가. 스택이 비어있는 --> push만 하면 됨.
				// 나. 스택이 안 비어있는데, (가 내 밑이면 --> push만 하면 됨.
				// 다. 스택이 안 비어있는데, 연산자 우선순위를 따져야 하는 경우, --> 인생케이스
				if (isEmpty()) {
					push(infix_expr[idx]); // 가, Case
				}
				else {  //나, 다 경우 처리 : 스택이 안 비어있는 경우
					// infix_expr와 stack[top]의 우선순위를 따져서,
					// infix_expr가 높으면 ---> push : 그나마 괜찮은
					// infix_expr가 낮으면 ---> 높은 애들 다 pop해서 출력하고, push ---> 고생케이스
					
					// amIHigher(infix_expr) 함수: infix_expr의 우선순위가 stack[top]보다 높으면 1, 아니면 0
					while (1) {
						if (!amIHigher(infix_expr[idx])) {
							printf("%c", pop());
						}
						else {
							break;
						}
					}
					push(infix_expr[idx]);
				}

			}

		}
		
		idx++;
	}
	
	// 다 읽고 나면, 무엇을 해야 하나요?
	// 스택이 empty될 때까지, pop하면서 출력
	while (isEmpty() != 1) {
		printf("%c", pop());
	}
	printf("\n");
	return 0;
}
#endif 
