#include <stdio.h>


int canvas[1000][1000];
int num;
int most_right;
int most_up;
int gap_left;
int gap_down;
void init()
{
	for (int i = 0; i < 1000; i++){
		for (int j = 0; j < 1000; j++){
			canvas[i][j] = 0;
		}
	}
	num = 0;
	most_right = 0;
	most_up = 0;
	gap_left = 0;
	gap_down = 0;
}
int cal_area();
void painting(int left, int down);
int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);
		scanf("%d\n",&num);
		for (int i = 0; i < num; i++){
			scanf("%d %d\n", &gap_left, &gap_down);
			painting(gap_left, gap_down);
		}
		printf("%d\n", cal_area());


		init();
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
void painting(int left, int down)
{
	for (int i = down; i < down + 10; i++){
		for (int j = left; j < left + 10; j++){
			canvas[i][j] = 1;
		}
	}
	if (left + 10 > most_right) most_right = left + 10;
	if (down + 10 > most_up) most_up = down + 10;
	//for (int i = 0; i < most_up; i++){
	//	for (int j = 0; j < most_right; j++){
	//		printf("%d ", canvas[i][j]);
	//	}
	//	printf("\n");
	//}
	//printf("\n");
	//printf("\n");
}
int cal_area()
{
	int total = 0;
	for (int i = 0; i <= most_up; i++){
		for (int j = 0; j <= most_right; j++){
			if (canvas[i][j] == 1) total++;
		}
	}
	return total;
}