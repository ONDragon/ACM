#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
//ϵͳ�ɿ���  �� һά����
const int maxn = 10000;
int p[maxn],c[maxn];
int dp[maxn];
int main()
{
	int n,m,i,j;
	while(scanf("%d%d",&n,&m)!= EOF)  //n �������� �� m �������� ,ÿ��������������������
	{
		for(i = 0;i < m;i ++)
		{
			scanf("%d%d",&c[i],&p[i]);
		}
		memset(dp,0,sizeof(dp));
		for(i = 0;i < m;i ++)
		{
			for(j = c[i];j <= n;j ++)
			{
				dp[j] = max(dp[j],dp[j-c[i]] + p[i]);
			}
		}
		// dp �������Ǹ���������
	}
	return 0;
}