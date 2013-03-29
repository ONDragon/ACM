#include <iostream>
using namespace std;
const int maxn = 90005;
const int inf = 1000000000;
int dis[maxn];
int n,m,em,st,ed;
struct Node
{
    int u,v,d;
};
Node edage[maxn]; 
bool BellmanFord(int src)
{
 	 int i,j,u,v;
 	 for(i = st;i <= ed;i ++) dis[i] = -inf;
 	 dis[src] = 0;
	 bool sign ;
	 for(i = st;i < ed;i ++) //����n-1���ɳڲ���.
	 {
         sign = true;
         for(j = 0;j < em;j ++)
		 {
            u = edage[j].u;
            v = edage[j].v;
            if(dis[v]  < dis[u] + edage[j].d) { dis[v] = dis[u]+ edage[j].d; sign = false;}
   		 }
   		 if(sign) break;  //����û���ɳڣ���ô��һ�غ�Ҳ�����е��ˡ�
  	 }
  	 for(j = 0;j < em;j ++)  //�жϸ��Ļ�·��
	{
         u = edage[j].u;
         v = edage[j].v;
         if(dis[v] < dis[u] + edage[j].d) return false;
   	} 
  	 return true;
}
void read()
{
 	 int i,x,y;
 	 n = maxn;
 	 while(scanf("%d",&m)!=EOF)
 	 {
         em = 0;
         for(i =0, st = maxn, ed = 0;i < m;i ++)
         {
           scanf("%d%d",&x,&y);
		   y ++;  //��Ϊ������������ʼ�㡣 
		   if(x < st) st = x;
           if(y > ed) ed = y;
           edage[em].u = x; edage[em].v = y;  // y - x >= 2; ����С�� 
           edage[em++].d = 2;
   		 }
		 for(i = st+1;i <= ed;i ++)
		 {
		   edage[em].u = i-1; edage[em].v = i;
           edage[em++].d = 0;
		   edage[em].u = i; edage[em].v = i-1;
           edage[em++].d = -1;
		 }
   		 BellmanFord(st);
   		 printf("%d\n",dis[ed]);
	 }
}

int main()
{
    read();
    return 0;
}
