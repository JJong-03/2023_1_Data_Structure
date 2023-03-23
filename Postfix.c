#if 1
#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 20
int stack[STACK_SIZE];
int top = -1; 

int isFull(){
    return (top == (STACK_SIZE -1));
}
int isEmpty(){
    return (top == -1);
}
void push(char _v){
    if(isFull()) return;
    top++;
    stack[top] = _v;
    return;
}
int pop(){
    if(isEmpty()) return -999;
    int temp = stack[top];
    top --;
    return temp;
}
int Calc_expr(char op, int v1, int v2) {

	switch (op) {
	case '+':
		return (v1 + v2);
	case '-':
	    return (v2 - v1); 
	case '*':
		return (v1 * v2);
	case '/':
		return (v2 / v1); 
	default:
		break;
	}
}

int main(){
char Postfix[] = "235*+";
int idx = 0;

while(Postfix[idx] != '\0'){
    char c = Postfix[idx];
    if((c>='0')&&(c<='9')){
        push((int)(c - '0'));
    }
    else{//연산자만 들어간다고 가정했을 때
        int v1 = pop();
        int v2 = pop();
        int result = Calc_expr(c,v1,v2);
        push(result);
    }
   
    idx++;
}
 printf("%d", pop());
return 0;
}
#endif