#include <stdio.h>
#include <stdlib.h>

int num_node;
int num_edge;
int** graph;
int** cpGraph;
int* path;
int cnt = 0;

void printPath();
void copyGraph()
{
	for (int i = 0; i < num_node; i++){
		for (int j = 0; j < num_node; j++){
			cpGraph[i][j] = graph[i][j];
		}
	}
}
void init()
{
	for (int i = 0; i < num_node; i++){
		free(graph[i]);
		free(cpGraph[i]);
	}
	free(graph);
	free(cpGraph);
	free(path);
	num_node = 0;
	num_edge = 0;
}
int DFS(int startNode)
{
	int i = 0;
	int flag = 1;
	path[cnt++] = startNode;



	for (i = 0; i < num_node; i++)
	{
		if (cpGraph[startNode][i])
		{
			flag = 0;
			break;
		}
	}
	if (flag){
		return 1;
	}
	else{
		printf("path : ");
		printPath();
		for (int ii = 0; ii < num_node; ii++){
			for (int j = 0; j < num_node; j++){
				printf("%2d", cpGraph[ii][j]);
			}
			printf("\n");
		}
		cpGraph[startNode][i] = 0;
		cpGraph[i][startNode] = 0;


		DFS(i);
		return 1;
	}


}
void printPath()
{
	for (int i = 0; i < num_edge + 1; i++){
		printf("%d ", path[i] + 1);
	}
	printf("\n");
}
int isSuccessed()
{
	for (int i = 0; i < num_node; i++){
		for (int j = 0; j < num_node; j++){
			if (cpGraph[i][j] == 1) return 0;
		}
	}
	return 1;
}
void clearPath()
{
	for (int i = 0; i < num_edge + 1; i++){
		path[i] = 0;
	}
}
int main()
{
	scanf("%d %d", &num_node, &num_edge);
	int flag = 0;
	//
	graph = (int**)malloc(num_node*sizeof(int*));
	cpGraph = (int**)malloc(num_node*sizeof(int*));
	for (int i = 0; i < num_node; i++){
		graph[i] = (int*)malloc(num_node*sizeof(int));
		cpGraph[i] = (int*)malloc(num_node*sizeof(int));
		for (int j = 0; j < num_node; j++){
			graph[i][j] = 0;
			cpGraph[i][j] = 0;
		}
	}

	//
	path = (int*)malloc((num_edge + 1)*sizeof(int));
	clearPath();

	//
	int row, col;
	for (int i = 0; i < num_edge; i++){
		scanf("%d %d", &row, &col);
		graph[row - 1][col - 1] = 1;
		graph[col - 1][row - 1] = 1;
	}
	for (int i = 0; i < num_node; i++){
		copyGraph();
		DFS(i);
		if (isSuccessed()) {
			flag = 1;
			break;
		}
		else{
			clearPath();
			cnt = 0;
		}
	}

	if (flag)
		printPath();
	else
		printf("0\n");

	init();



	return 1;
}