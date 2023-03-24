// infix에서 postfix 만들어내기
// stack 이용

#include <stdio.h>
#define STACK_SIZE 20

char stack[STACK_SIZE];
int top = -1;

int isFull() {
	return(top == (STACK_SIZE - 1));
}
int isEmpty() {
	return(top == -1);
}
void push(char c) {
	if (isFull()) {
		printf("Full");
		return;
	}
	top++;
	stack[top] = c;
	return;
}
char pop() {
	if (isEmpty()) {
		return '\0'; // error
	}
	char temp = stack[top];
	top--;
	return temp;
}

int amIHigher(char _c) {

	if (stack[top] == '(') {   // 간단한 경우.
		return 1;
	}
	else if (_c == '*' || _c == '/') {
		if (stack[top] == '+' || stack[top] == '-') {
			return 1;
		}
	}
	// c가 +, - 인 경우는 우선순위가 높을 수가 없다.
	return 0;

}
int main() {
	char infix_expr[] = "1*(2+3)";
	int idx = 0;

	while (infix_expr[idx] != '\0') {
		char c = infix_expr[idx];
		if (c >= '0' && c <= '9') {
			printf("%c", c);
		}
		else { //일단 여기서는 수를 제외한 나머지 문자는 모두 연산자라고 가정한다.
			if (c == '(') {
				push(c);
			}
			else if (c == ')') {  // 닫는 괄호면, 여는 괄호나올 때까지 pop하면서 연산자 출력
				while (1) {
					char _d = pop();
					if (_d == '(') {
						break;
					}
					printf("%c", _d);
				}
			}
			else {  // +, -, *, / 와 같은 연산자
			   // 가. 스택이 비어있는 --> push만 하면 됨.
			   // 나. 스택이 안 비어있는데, (가 내 밑이야 --> push만 하면 됨
			   // 다. 스택이 안 비어있는데, 연산자 우선순위를 따져야 하는 경우amIHigher 함수를 이용해 우선순위를 따짐
				if (isEmpty()) {
					push(c);
				}
				else { //나, 다 경우 처리 : 스택이 안 비어있는 경우
					   // _c와 stack[top]의 우선순위를 따져서, 
					   // _c가 높으면 ---> push 
					   //      낮으면 ---> 높은 애들 다 pop해서 출력하고, push 

					   // amIHigher(_c) 함수: _c의 우선순위가 stack[top]보다 높으면 1, 아니면 0 
					while (1) {
						if (!amIHigher(c)) {
							printf("%c", pop());
						}
						else {
							break;
						}
					}
					push(c);
				}
			}
		}


		idx++;
	}
	while (isEmpty() != 1) {
		printf("%c", pop());
	}
	printf("\n");

	return 0;

}