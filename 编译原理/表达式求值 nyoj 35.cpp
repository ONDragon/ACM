E��ʾ�����ʽ��
T��ʾ������ʽ;
F��ʾ����ʽ;
i��ʾ��һ����;
���ķ�G[E]Ϊ��
E��T|E+T|E-T
T��F|T*F|T/F
F��(E)|i
c�棺strrev()���Ǳ�׼C���ԵĿ⺯���ĵ���forѭ��ʵ�ַ�ת����;

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str[1005];
int start;
char s[50],ss[50];int i,j;
double Term();double Expression();double Factor();
double Term()
{
    double f=Factor(),t;
    --start;
    if(str[start]=='*')
    {
        t=Term();
        return t*f;
    }
    else if(str[start]=='/')
    {
        t=Term();
        return t/f;
    }
    else {++start;return f;}
}
double Expression()
{
    double t=Term(),e;
    --start;
    if(str[start]=='+')
    {
        e=Expression();
        return e+t;
    }
    else if(str[start]=='-')
    {
        e=Expression();
        return e-t;
    }
    else {++start;return t;}
}
double Factor()
{
    --start;
    double ret;
    if(str[start]==')')
    {
        ret=Expression();
        --start;
        return ret;
    }
    else
	{//���һ��double����
		i=0;
		memset(ss,0,sizeof(ss));
		while((str[start]>='0'&&str[start]<='9')||str[start]=='.')
			s[i++]=str[start--];
		++start;
		for(j=0;j<i;j++)
		{
			ss[j]=s[i-1-j];
		}
		return atof(ss);
	}
}
int main()
{
	//freopen("1.txt","r",stdin);
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",str);
		start=strlen(str)-1;
		printf("%.2lf\n",Expression());
	}
}