#include<stdio.h>
#define MAZE_SIZE 6
#define STACK_SIZE MAZE_SIZE * MAZE_SIZE
char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},  // e : entrance
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},  // x : exit
	{'1','1','1','1','1','1'}
};
typedef struct {
    int r;
    int c;
}LOC;

LOC stack[STACK_SIZE];
int top = -1;
int isEmpty(){
return(top == -1);
}
int isFull(){
return(top == (STACK_SIZE - 1));
}
LOC pop(){
if(isEmpty()){
    LOC err_code = {-1, -1};
    return err_code;
}
LOC temp = stack[top];
top --;
return temp;
}

void push(int r, int c){
if(isFull()){
    printf("Full!!");
    return;
}
if(r<0 || c<0){
    return;
}
if(maze[r][c] == '1'|| maze[r][c] == '.'){
    return;
}
LOC temp = {r,c};
top++;
stack[top]= temp;
return;
}

void printMaze(){
    for(int i = 0; i<MAZE_SIZE; i++){
        for(int j = 0; j<MAZE_SIZE; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}


int main(){
    LOC cur = {1, 0}; //시작 지점으로 초기화 e가 있는 곳
    while(1){
        if(maze[cur.r][cur.c] == 'x'){
            printf("탈출");
            return 0;
        }
        
        maze[cur.r][cur.c] = '.';
        printMaze();

        push(cur.r - 1, cur.c);
        push(cur.r + 1, cur.c);
        push(cur.r, cur.c - 1);
        push(cur.r, cur.c + 1);

        cur = pop();
        if ((cur.r == -1) && (cur.c == -1)) {
			printf("탈출 실패!");
			return -1;
		}
    }

    return 0;
}
