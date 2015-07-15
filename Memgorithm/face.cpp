#include <stdio.h>

char table[50][50];
int row;
int col;
int cnt;
int face[4];
void init(){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			table[i][j] = '\0';
		}
	}
	row = 0;
	col = 0;
	cnt = 0;
	face[0] = 0;
	face[1] = 0;
	face[2] = 0;
	face[3] = 0;
}
void face_c(char c)
{
	switch (c)
	{
	case 'f':
		face[0] = 1;
		break;
	case 'a':
		face[1] = 1;
		break;
	case 'c':
		face[2] = 1;
		break;
	case 'e':
		face[3] = 1;
		break;
	default:
		break;
	}
}
int check_face(int row, int col)
{
	int count = 0;
	face[0] = 0;
	face[1] = 0;
	face[2] = 0;
	face[3] = 0;
	face_c(table[row][col]);
	face_c(table[row + 1][col]);
	face_c(table[row][col + 1]);
	face_c(table[row + 1][col + 1]);
	count += face[0];
	count += face[1];
	count += face[2];
	count += face[3];
	if (count == 4) return 1;
	else return 0;
}
int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr < nCount; itr++)
	{
		printf("#testcase%d\n", itr + 1);
		scanf("%d %d\n", &row, &col);
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				scanf("%c", &table[i][j]);
			}
			getchar();
		}

		//count face
		for (int i = 0; i < row - 1; i++){
			for (int j = 0; j < col - 1; j++){
				cnt += check_face(i, j);
			}
		}
		printf("%d\n", cnt);
		init();
	}

	return 0;
}