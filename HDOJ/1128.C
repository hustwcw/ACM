#include<stdio.h>

float intersection(float x1,float y1,float w1,float h1,float x2,float y2,float w2,float h2);

void main()
{
	float rect[100][4];
	float area=0.0;
	int i,j;
	int n;
	int case_num=1;
	freopen("C:\\in.txt","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{
		area=0.0;/*initialize*/
		for(i=0;i<n;i++)/*读取n行数据*/
		{
			scanf("%f%f%f%f",&rect[i][0],&rect[i][1],&rect[i][2],&rect[i][3]);
			area+=(rect[i][2]-rect[i][0])*(rect[i][3]-rect[i][1]);
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				area-=intersection(rect[i][0],rect[i][1],rect[i][2],rect[i][3],rect[j][0],rect[j][1],rect[j][2],rect[j][3]);
			}
		}
		printf("Test case #%d\nTotal explored area:%.2f\n\n",case_num,area);
		case_num++;
		scanf("%f",&area);
	}
}
float intersection(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{	if(x3>=x1&&x3<=x2&&y3>=y1&&y3<=y2)
		return (((x2<x4)?x2:x4)-x3)*(((y2<y4)?y2:y4)-y3);
	else if(x1>=x3&&x1<=x4&&y1>=y3&&y1<=y4)
		return (((x4<x2)?x4:x2)-x1)*(((y4<y2)?y4:y2)-y1);
	return 0;
}
