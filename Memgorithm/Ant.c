#include <stdio.h>
#include <stdlib.h>
typedef struct _Pos{
	int x;
	int y;
}Pos;
int width = 0;
int height = 0;
Pos cur;
Pos* path;
int deltaX;
int deltaY;
unsigned long long time;
int real_t;
void init()
{
	cur.x = 0; cur.y = 0;
	width = 0; height = 0;
	deltaX = 0; deltaY = 0;
	time = 0; real_t = 0;
	free(path);
}

int main()
{
	int itr;
	int nCount;
	scanf("%d", &nCount);
	for (itr = 0; itr < nCount; itr++)
	{
		deltaX = 1;
		deltaY = 1;
		printf("#testcase%d\n", itr + 1);
		scanf("%d %d\n", &width, &height);
		scanf("%d %d\n", &cur.x, &cur.y);
		scanf("%llu", &time);
		real_t = (time % ((width + 1)*(height + 1)));
		path = malloc(width*height*sizeof(Pos));
		while (real_t-- > 0){
			//if ((cur.x > 1 && cur.x < width) && (cur.y > 1 && cur.y < height)) {
			//	cur.x += deltaX;
			//	cur.y += deltaY;
			//	continue;
			//}
			if (cur.x + deltaX > width || cur.x + deltaX < 0){
				deltaX *= -1;
				cur.x += deltaX;
			}
			else{ cur.x += deltaX; }
			if (cur.y + deltaY > height || cur.y + deltaY < 0){
				deltaY *= -1;
				cur.y += deltaY;
			}
			else { cur.y += deltaY; }
		}
		printf("%d %d\n", cur.x, cur.y);
		init();
	}
	return 0;
}