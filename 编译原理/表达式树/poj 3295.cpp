b�൱��!a||b)��E��ʾ"��ֵ" ����һ��ʽ���Ƿ�������ʽ������ʽ��������:ö��p,q,r,s,t��0��1������������� ps: && ||��· [c] ..." />

���⣺��K��ʾ���ҡ�,A��ʾ����,N��ʾ���ǡ�,C��ʾ���Ƶ���(�൱��a->b�൱��!a||b)��E��ʾ����ֵ��
����һ��ʽ���Ƿ�������ʽ������ʽ����
����:ö��p,q,r,s,t��0��1�������������
ps: && ||��·

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 105;

bool sign[6];
char c[maxn];
int pos;

bool val()
{
	bool a,b;
	switch(c[pos++])
	{
	case 'K':
		a = val();b = val();
		return a&b;
		break;
	case 'A':
		a = val();b = val();
		return a|b;
		break;
	case 'N':
		a = val();
		return !a;
		break;
	case 'C':
		a = val();b = val();
		return (!a)|b;
		break;
	case 'E':
		a = val();b = val();
		return !(a^b);
		break;
	default:
		return sign[c[pos-1]-'p'];
	}
}

bool check()
{
	int p,q,r,s,t;
	bool ans = true;
	for(p = 0;p < 2;p ++)
	{
		sign[0] = p;
		for(q = 0;q < 2;q ++)
		{
			sign[1] = q;
			for(r = 0;r < 2;r ++)
			{
				sign[2] = r;
				for(s = 0;s < 2;s ++)
				{
					sign[3] = s;
					for(t = 0;t < 2;t ++)
					{
						sign[4] = t;
						pos = 0;
						ans = val();
						if(!ans) return false;
					}
				}
			}
		}
	}
	return ans;
}
int main()
{
	while(scanf("%s",c)!=EOF)
	{
		if(c[0] == '0') break;
		if(check()) printf("tautology\n");
		else printf("not\n");
	}
	return 0;
}