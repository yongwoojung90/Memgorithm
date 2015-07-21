#include <stdio.h>

int numTree[1001][1001];
int total[1001][1001];
int level;

int main()
{

	scanf("%d\n", &level);
	int cnt = 1;
	int max = 0;
	for (int i = 1; i <= level; i++){
		for (int j = 1; j <= cnt; j++){
			scanf("%d ", &numTree[i][j]);
		}
		cnt++;
	}
	cnt = 1;

	for (int i = 1; i <= level; i++){
		for (int j = 1; j <= cnt; j++){
			if (total[i - 1][j - 1] > total[i - 1][j]){
				total[i][j] = numTree[i][j] + total[i - 1][j - 1];
			}
			else{
				total[i][j] = numTree[i][j] + total[i - 1][j];
			}
		}
		cnt++;
	}
	for (int i = 1; i <= level; i++){
		if (total[level][i] > max) max = total[level][i];
	}
	printf("%d", max);


	return 1;
}