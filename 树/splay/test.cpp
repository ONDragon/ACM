#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Pr.h"

using namespace std;
typedef int LL;
/*
���������ԣ� ����ʱ��s
��ҵ�����ԣ� ���빤��ʱ��ti + ����ʱ�䣨si ��Ӧ��������ʦҪ����ӣ�

�����㷨 = �������� + ��δ��ʼ���� 

*/
int scan()
{
	char c[104];
	int num,i;
	while(gets(c))
	{
		num = 0;
		for(i = 0;c[i] != '\0';i ++)
			if(c[i] >= '0' && c[i] <= '9') num = num*10 + c[i] - '0';
			else 
			{
				printf("��������������:\n");
				break;
			}
		if(c[i] == '\0'&&i != 0) break;
	}
	return num;
}
class Jq{
public:
	int s,pos;
	Jq():s(0){}
};
struct Jcmp{
	bool operator()(const Jq & t1,const Jq & t2)
	{
		if(t1.s != t2.s) return t1.s < t2.s;
		else return t1.pos < t2.pos;
	}
};
class Rw{
public:
	int si,ti,pos;
	Rw(int s = 0,int t = 0):si(s),ti(t) {};
};
struct cmp{
	bool operator()(const Rw & t1,const Rw & t2)  //�������ĵ���̰���㷨�� �ȵ��������������
	{
		if(t1.si != t2.si) return t1.si < t2.si;
		return t1.ti > t2.ti;
	}
};
struct cmp2{
	bool operator()(const Rw & t1,const Rw & t2)  //�������ĵ���̰���㷨�� �ȵ��������������
	{
		return t1.ti > t2.ti;
	}
};

int main()
{
	int n,m,i,j,s,t;
	Jq jtm;
	Rw tm;
	Pq<Jq,Jcmp> js;
	Pq<Rw,cmp> ls;
	Pq<Rw,cmp2> jxls;
	while(1)
	{
		js.cls();ls.cls();jxls.cls();
		printf("�������������Ȼ��س���\n");
		m = scan();
		for(i = 1;i <= m;i ++)
		{
			jtm.pos = i;
			jtm.s = 0;
			js.push(jtm);
		}
		printf("��������������Ȼ��س���\n");
		n = scan();
		srand(unsigned (time(NULL)));
		//printf("������n������ʼ��ʱ�� + ��Ҫ���봦��ʱ��\n");
		printf("�����  ����ʱ�� ���봦��ʱ\n");
		for(i = 1;i <= n;i ++)
		{
			//scanf("%d%d",&s,&t);   
			s = rand()%100; t = rand()%100+1; //��������ĵ���ʱ�� + ���빤��ʱ��
			s = 0;
			printf("%d     %d     %d\n",i,s,t);
			tm.si = s; tm.ti = t;tm.pos = i;
			ls.push(tm);
		}
		printf("����   ������  ����ʱ��  ����ʱ��\n");
		for(i = 1;i <= n;i ++)
		{
			jtm = js.front();  //ĳ���п��еĴ�����
			js.pop();
			if(jxls.empty())  //���������ǿյģ���ô�������ȴ�
			{
				tm = ls.front();
				if(tm.si > jtm.s)
				{
					jtm.s = tm.si;
				}		
			}
			while(!ls.empty())  //ȡ�����е�������񣬴����������
			{
				tm = ls.front();
				if(tm.si <= jtm.s)
				{
					jxls.push(tm);
					ls.pop();
				}else break;
			}
			//ȡ�����������񣬽��д���
			tm = jxls.front();
			jxls.pop();
			printf("%-9d%-9d%-9d%-9d\n",tm.pos,jtm.pos,jtm.s,jtm.s+tm.ti);
			if(jtm.s < tm.si) jtm.s = tm.si;
			jtm.s += tm.ti;
			js.push(jtm);		
		}
		while(!js.empty())
		{
			jtm = js.front();
			js.pop();
		}
		printf("�������������ʱ��%d\n",jtm.s);
	}
	return 0;
}
