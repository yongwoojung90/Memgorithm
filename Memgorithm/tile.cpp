#include <stdio.h>

//unsigned long N, M;
//unsigned long big, small;
//unsigned long temp;
//unsigned long GCD;

unsigned __int64 N, M;
unsigned __int64 big, small;
unsigned __int64 temp;
unsigned __int64 GCD;

void init()
{
	temp = GCD = N = M = big = small = 0;
}
int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr < nCount; itr++)
	{
		printf("#testcase%d\n", itr + 1);
		scanf("%d %d", &N, &M);
		if (N > M){
			big = N; small = M;
		}
		else{
			big = M; small = N;
		}
		while (1){
			temp = big % small;
			if (temp == 0){
				GCD = small;
				break;
			}
			else{
				big = small;
				small = temp;
			}
		}
		printf("%d\n", (N / GCD)*(M / GCD));

		init();
	}

	return 0;
}