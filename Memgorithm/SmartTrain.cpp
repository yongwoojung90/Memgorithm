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
	int nCount;		/* ������ �׽�Ʈ ���̽� */

	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */
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

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}