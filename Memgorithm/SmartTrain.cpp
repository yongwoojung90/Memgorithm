#include <stdio.h>


int boarding[4];
int landing[4];
int total;
int max;
void init()
{
	for (int i = 0; i < 4; i++){
		boarding[i] = 0;
		landing[i] = 0;
	}
	total = 0; max = 0;
}
int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */
	total = 0; max = 0;

	for (itr = 0; itr<nCount; itr++)
	{
		printf("#testcase%d\n", itr + 1);

		for (int i = 0; i < 4; i++){
			scanf("%d %d", &landing[i], &boarding[i]);
		}
		for (int i = 0; i < 4; i++){
			total += boarding[i];
			total -= landing[i];
			if (total > max){
				max = total;
			}
		}
		printf("%d\n", max);
		init();
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}