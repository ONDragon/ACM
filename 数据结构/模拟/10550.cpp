#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;

int a,b,c,d;
int main()
{
	int ans;
	while(scanf("%d%d%d%d",&a,&b,&c,&d),a|b|c|d)
	{
		ans = 1080;
		//ans += a*9;
	
		ans += ((a-b+40)%40)*9; //˳ʱ��
		
		ans += ((c-b+40)%40)*9; //��ʱ��
		
		ans += ((c-d+40)%40)*9; //˳ʱ��

		printf("%d\n",ans);
	}
	return 0;
}