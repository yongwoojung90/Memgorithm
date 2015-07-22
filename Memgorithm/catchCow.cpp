#include <stdio.h>

typedef struct _Node{
	int val;
	int level;
}Node;
Node queue[110001];
int visit[100001];
Node* front = queue;
Node* rear = queue;
int flag = 1;
int posCow;
int posJohn;
Node* curNode;

void init()
{
	int i = 0;
	for (i = 0; i < 100001; i++){
		queue[i].val = 0;
		queue[i].level = 0;
		visit[i] = 0;
	}
	flag = 1;
}

void enqueue(int val, int level)
{
	visit[val] = 1;
	if (flag == 1){
		rear->val = val;
		rear->level = level;
		flag = 0;
	}
	else{
		(++rear)->val = val;
		rear->level = level;
	}
}
Node* dequeue()
{
	Node* retval = NULL;
	if (front == rear + 1) //underflow
	{
		return retval;
	}
	else{
		retval = front;
		//front->level = 0;
		//front->val = 0;
		front++;
		return retval;
	}
}
int checkCow(Node* nextNode)
{
	if (nextNode->val - 1 == posCow)
		return 1;
	if (nextNode->val * 2 == posCow)
		return 1;
	if (nextNode->val + 1 == posCow)
		return 1;
	return 0;
}

int main()
{
	scanf("%d %d", &posJohn, &posCow);
	if (posCow == posJohn){
		printf("0");
		return 1;
	}
	enqueue(posJohn, 0);

	while (1){
		curNode = dequeue();
		if (checkCow(curNode)){
			printf("%d\n", curNode->level + 1);
			break;
		}
		if (curNode->val - 1 > -1 && visit[curNode->val - 1] != 1){
			enqueue(curNode->val - 1, curNode->level + 1);
		}
		if (visit[curNode->val * 2] != 1 && curNode->val * 2 < 100001){
			enqueue(curNode->val * 2, curNode->level + 1);
		}
		if (visit[curNode->val + 1] != 1 && curNode->val + 1 < 100001){
			enqueue(curNode->val + 1, curNode->level);
		}
	}
	return 1;
}