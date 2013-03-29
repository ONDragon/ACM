#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
//��С����ͼ ���޶��㣩 ���ⶨ���� n;
const int inf = 0x3fffffff;
const int maxn = 1005;
const int maxe = 110000;
struct Node{
	int u,v,d;
	int ou,ov;   //����Ѱ����������,���Ա���ԭ���ڵ���Ϣ
	void set(int ul,int vl,int cl,int oul,int ovl)
	{
		u = ul; v = vl; d = cl;
		ou = oul; ov = ovl;
	}
};
Node eda[1100000];
int em;
int n,m;
int pre[maxn],belong[maxn],in[maxn],vis[maxn],sroot,w;
void addEda(int u,int v,int d) //��������
{
	if(u == v) return ;
	eda[em].set(u,v,d,u,v);
	em ++;
}
int solve(int oldroot,int cw) //cw ������Ȩ��+1
{
	int i,j,k,v;
	int sum = 0,root = 0,num = 0;
	root = oldroot;
	for(i = 0;i < n;i ++)  //ԭ������0 ~ n-1
		addEda(root,i,cw);
	n ++;
	while(1)
	{
		for(i = 0;i < n;i ++)
			in[i] = inf;
		for(i = 0;i < em;i ++)  //����ÿ�������Ȩ��С�ıߣ�����¼ǰ��
		{
			if(in[eda[i].v] > eda[i].d && eda[i].u != eda[i].v)
			{
				if(eda[i].ou == oldroot) sroot = eda[i].ov;  //���һ�θ��µĵ�һ����ѡ��
				pre[eda[i].v] = eda[i].u;
				in[eda[i].v] = eda[i].d;
			}
		}
		memset(vis,-1,sizeof(vis));
		memset(belong,-1,sizeof(belong));
		in[root] = 0;
		for(num = 0,i = 0;i < n;i ++) //���һ�
		{
			if(in[i] == inf && i != root) return -1; //û��������С����ͼ
			sum += in[i];
			j = i;
			while(vis[j] != i && belong[j] == -1 && j != root)
			{
				vis[j] = i; j = pre[j];
			}
			if(vis[j] == i)
			{
				for(k = pre[j];k != j;k = pre[k])
					belong[k] = num;
				belong[j] = num ++;
			}
		}
		if(!num) return sum;
		for(i = 0;i < n;i ++)   //������µ���
			if(belong[i] == -1) belong[i] = num ++;
		//���ı� + ����
		for(i = 0;i < em;i ++)
		{
			v = eda[i].v;
			eda[i].u = belong[eda[i].u];
			eda[i].v = belong[eda[i].v];
			eda[i].d -= in[v];
		}
		root = belong[root];
		n = num;
	}
	return sum;	
}

int main()
{
	int i,j,a,b,c,sum;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		em = 0;
		w = 0;
		for(i = 0;i < m;i ++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a != b) w += c;
			addEda(a,b,c);
		}
		sum = solve(n,w+1);
		if(sum == -1) printf("impossible\n\n");
		else
		{
			sum -= w+1;
			if(sum > w) printf("impossible\n\n");
			else printf("%d %d\n\n",sum,sroot);
		}
	}
	return 0;
}