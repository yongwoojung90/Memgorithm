#include <stdio.h>

double table[2001000];
int len=0;
void init()
{

}
int check(double val);

int main()
{
	int D1, D2;
	double i = 0;
	double j = 0;
	//int temp
	scanf("%d %d", &D1, &D2);

	for (i = D1; i <= D2; i++){
		for (j = 0; j <= i - 1; j++){
			if (check(j / i)){
				table[len++] = j / i;
			}
		}
	}
	printf("%d", len);
	init();
	return 1;
}
int check(double val)
{
	int i = 0;
	for (i = 0; i < len; i++){
		if (table[i] == val)
			return 0; //똑같은게 이미 있음
	}
	return 1; //똑같은게 없음
}