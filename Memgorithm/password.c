#include <stdio.h>

char str[102];
char passwd[102];
char* pPasswd;
int len_str;
void init()
{
	int i = 0;
	while (str[i] != '\0'){
		passwd[i] = '\0';
		str[i++] = '\0';
	}
}

int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */

	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

	for (itr = 0; itr<nCount; itr++)
	{
		
		printf("#testcase%d\n", itr + 1);
		scanf("%d", &len_str);
		getchar();
		scanf("%s", str);
		int i = 1;
		while (1) {
			if (str[i - 1] != str[i]) {
				i++;
			}
			else{
				while (1){
					i++;
					str[i - 2] = str[i];
					if (str[i] == '\0'){
						i = 1;
						break;
					}
				}
			}
			if (str[i] == '\0')break;
		}
		printf("%s\n", str);
		init();
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}