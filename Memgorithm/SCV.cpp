#include <stdio.h>


int map[101][101];
int total[101][101];
int num;
int main()
{
	scanf("%d\n", &num);
	for (int i = 1; i <= num; i++){
		for (int j = 1; j <= num; j++){
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= num; i++){
		for (int j = 1; j <= num; j++){
			if (total[i - 1][j] > total[i][j - 1]){
				total[i][j] = map[i][j] + total[i - 1][j];
			}
			else{
				total[i][j] = map[i][j] + total[i][j - 1];
			}
		}
	}
	printf("%d\n", total[num][num]);
	
	return 0;
}