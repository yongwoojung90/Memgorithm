#include <stdio.h>

char str[1000][21];
int cnt = 0;

int checkEnd(char* str);
int len_str(char*str);
void clearStr(char* str);
void printReverse(char* str);
void init()
{

	cnt = 0;
	while (1){
		if (checkEnd(str[cnt++])){
			clearStr(str[cnt - 1]);
			break;
		}
		else{
			clearStr(str[cnt-1]);
		}
	}
	cnt = 0;
}
int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	scanf("%d", &nCount);
	for (itr = 0; itr < nCount; itr++)
	{
		printf("#testcase%d\n", itr + 1);

		while (1){
			scanf("%s", str[cnt]);
			if (checkEnd(str[cnt++])){
				//printReverse(str[cnt-1]);
				break;
			}
			else{
				printReverse(str[cnt-1]);
			}
		}
		//cnt = 0;
		//while (1){
		//	printf("%s\n", str[cnt]);
		//	if (checkEnd(str[cnt++])){
		//		break;
		//	}
		//}

		init();

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
int checkEnd(char* str)
{
	int len = 0;
	len = len_str(str);
	if (len != 3){
		return 0;
	}
	if (str[0] != 'E'){
		return 0;
	}
	if (str[1] != 'N'){
		return 0;
	}
	if (str[2] != 'D'){
		return 0;
	}
	return 1;

}
int len_str(char*str)
{
	int len = 0;
	while (str[len++] != '\0');
	return len - 1;
}
void clearStr(char* str)
{
	int len = 0;
	len = len_str(str);
	for (int i = 0; i < len + 1; i++){
		str[i] = '\0';
	}
}
void printReverse(char* str)
{
	int len = 0;
	len = len_str(str);
	for (int i = 0; i < len; i++){
		printf("%c", str[len - 1 - i]);
	}
	printf("\n");
}