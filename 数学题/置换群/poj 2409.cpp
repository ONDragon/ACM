#include <iostream>
#include <cmath>
using namespace std;
int c,s;
int gcd(int a,int b)
{
    if(b == 0) return a;
    else  return gcd(b,a%b);
}
int polya(int n,int m)
{
    int ans,i;
    __int64 tmp = 0;
    for(i = 0;i < n;i ++)
    {
       tmp += pow(m*1.0,1.0*gcd(n,i)); //n��ѭ��  �ƶ�����λ�� 
    }
    if(n&1)
    {
      tmp += n*pow(m*1.0,(n+1)/2.0);  //n��ѭ��  һ�������Ӧ�߶��е����� 
    }else
    {
      tmp += n/2*pow(m*1.0,n/2+1)+n/2*pow(m*1.0,n/2);  //n��ѭ��  �ֱ�Ϊ���������� ��������߶��е����ߡ� 
    }
    ans = tmp/(2*n);
    return ans;
}
int main()
{
    while(scanf("%d%d",&c,&s),c|s)
    {
       printf("%d\n",polya(s,c));
    }
    return 0;
}
