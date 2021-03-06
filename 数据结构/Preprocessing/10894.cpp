#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1005;

char v[61][6]=
{
"*****",
"*....",
"*****",
"....*",
"*****",
".....",
".***.",
"*...*",
"*****",
"*...*",
"*...*",
".....",
"*...*",
"*...*",
"*...*",
".*.*.",
"..*..",
".....",
"*****",
"*....",
"***..",
"*....",
"*****",
".....",
".....",
".....",
"*...*",
"*...*",
"*****",
"*...*",
"*...*",
".....",
"*****",
"*...*",
"*****",
"*.*..",
"*..**",
".....",
"*****",
"..*..",
"..*..",
"..*..",
"*****",
".....",
"***..",
"*..*.",
"*...*",
"*..*.",
"***..",
".....",
"*****",
"*...*",
"*...*",
"*...*",
"*****",
".....",
"*...*",
".*.*.",
"..*..",
"..*..",
"..*.."
};

char h[5][62]=
{
"*****..***..*...*.*****...*...*.*****.*****.***...*****.*...*",
"*.....*...*.*...*.*.......*...*.*...*...*...*..*..*...*..*.*.",
"*****.*****.*...*.***.....*****.*****...*...*...*.*...*...*..",
"....*.*...*..*.*..*.......*...*.*.*.....*...*..*..*...*...*..",
"*****.*...*...*...*****...*...*.*..**.*****.***...*****...*.."
};

void draw(int n)
{
	int i,j,k,l;
	if(n > 0)
	{
		for(i = 0;i < 5;i ++)
		{
			for(j = 0;j < n;j ++)
			{
				for(l = 0;h[i][l] != '\0';l ++)
				{
					for(k = 0;k < n;k ++)
					{
						printf("%c",h[i][l]);
					}
				}
				printf("\n");
			}
		}
	}else{
		n = -n;
		for(i = 0;i < 61;i ++)
		{
			for(j = 0;j < n;j ++)
			{

				for(l = 0;v[i][l] != '\0';l ++)
				{
					for(k = 0;k < n;k ++)
					{
						printf("%c",v[i][l]);
					}
				}
				printf("\n");
			}
		}
	}
}
int main()
{
	int n;
	//freopen("1.txt","w",stdout);
	while(scanf("%d",&n),n)
	{
		draw(n);
		printf("\n\n");
	}
	return 0;
}