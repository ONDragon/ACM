/*�û�Ⱥ ��С����Ȩ
��һ��״̬��polyaѭ������С���Ǹ��� ȥ���������ݽ�����
����: sum+(len-2)*min2��
�ڶ���״̬:����������С�����������뽻������󻻻�ȥ:
����: sum+min2+(len+1)*min;
������ 1 + ѭ�� len -1 + ��ȥ 1 = len+1;
min2 ��ȥ1 + ���� 1 = 2�� 
*/ 

#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1000000000;
const int maxn = 10005;
int v[maxn],b[maxn],n;
int hash[maxn*10];
bool sign[maxn];
int main()
{
    int ans,min,min2,sum;
    int i,j,t,len;
    while(scanf("%d",&n)!=EOF)
    {
       min = inf;
       for(i = 0;i < n;i ++) 
       {
             scanf("%d",&v[i]);
             b[i] = v[i];
             sign[i] = false;
             if(min > v[i]) min = v[i];
       }
       sort(b,b+n);
       for(i = 0;i < n;i ++) hash[b[i]] = i;
       ans = 0;
       for(i = 0;i < n;i ++)
       {
          if(!sign[i])
          {
             t = i;
			 min2 = v[i];
             len = 0;sum = 0;
             sign[i] = true;
             do{
                len ++;
                sum += v[t];
                sign[t] = true;
                if(min2 > v[t]) min2 = v[t];
                t = hash[v[t]];
             }while(t != i);
             int ans1,ans2;
             ans1 = sum+(len-2)*min2;
             ans2 = sum+min2+(len+1)*min;
             ans += ans1 > ans2 ? ans2:ans1;
          }
       }
       printf("%d\n",ans);
    }
    return 0;
}
