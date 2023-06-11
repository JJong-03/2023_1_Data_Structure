#define _CRT_SECURE_NO_WARNINGS
#if 1
#include<stdio.h>
#include<stdlib.h>
#define SZ 5

int graph[SZ][SZ];
void addEdge(int v1, int v2, int w) {
	graph[v1][v2] = w;
	graph[v2][v1] = w;
}

void prim(int svertex) {
	int visited[SZ] = { 0, };
	visited[svertex] = 1;
	for (int i = 0; i < SZ - 1; i++) {
		int mindist = 9999;
		int visited_vtx = -1;
		int nonvisited_vtx = -1;
		for (int j = 0; j < SZ; j++) {
			if (visited[j] == 1) {
				for (int k = 0; k < SZ; k++) {
					if (visited[k] == 0) {
						if (graph[j][k] > 0 && graph[j][k] < mindist) {
							mindist = graph[j][k];
							visited_vtx = j;
							nonvisited_vtx = k;
						}
					}
				}
			}
		}
		printf("%d --- %d \n", visited_vtx, nonvisited_vtx);
		visited[nonvisited_vtx] = 1;
	}
}
void kruskal() {
	int family[SZ] = { 0,1,2,3,4 };

	for (int i = 0; i < SZ - 1; i++) {
		int v1 = -1;
		int v2 = -1;
		int mindist = 999999;

		for (int j = 0; j < SZ; j++) {
			for (int k = j + 1; k < SZ; k++) {
				if (graph[j][k] > 0 && mindist > graph[j][k] && family[j] != family[k]) {
					mindist = graph[j][k];
					v1 = j;
					v2 = k;
				}
			}
		}
		printf("%d --- %d\n", v1, v2);
		int newfamily = family[v1];
		int oldfamily = family[v2];
		for (int b = 0; b < SZ; b++) {
			if (family[b] == oldfamily) {
				family[b] = newfamily;
			}
		}
	}
}

int main(void)
{
	addEdge(0, 1, 100); // 0 --> 1 edge, weight = 100
	addEdge(0, 2, 10);
	addEdge(1, 2, 40);
	addEdge(1, 3, 50);
	addEdge(2, 3, 1);
	addEdge(3, 4, 10);

	// MST by Prim
	//prim(0); // graph에 대해서, start vertex = 0로 하여 MST를 Prim알고리즘으로 찾는다.

	// MST by Kruskal
	kruskal();
}
#endif
