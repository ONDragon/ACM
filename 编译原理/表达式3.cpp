�Զ����µ��﷨�����C�ݹ��½������C���ʽ��ֵ
�����ҵ����ʵ���ȷ�Ĳ���ʽ��Ȼ���ڲ���ʽ��Ϊÿ�����ս��дһ���ݹ麯�����ɡ�

���磬���ʽ��ֵ�����������²���ʽ��

Expression->Term|Expression+Term|Expression-Term

Term->Factor|Term*Factor|Term/Factor

Factor->(Expression)| number

�ò����������ȷ�ı�ʾ���ʽ�﷨��

���ڸò���ʽ�к�����ݹ飨��E->E+T������ʽ)��ֱ���õݹ��½���������д�����������ѭ����

�����ڱ������У�E->E+T��E->T+E�����������Ե����о��Ӷ�����ͬ�ģ�����˵�����ķ��ǵȼ۵ģ������ԣ��Ҿ���Ϊֱ�ӰѸ÷����ĳɳɣ�

Expression->Term|Term+Expression|Term-Expression

Term->Factor|Factor*Term|Factor/Term

Factor->(Expression)| number

��󣬳���д��֮�����ʱ���֣�1-2-3����ʽ�ӵĽ���������⣬������Ĳ���ʽ�õ��Ľ���ǣ�2.��Ϊ��������������2-3=-1.
��ʽ��(�ű�ʾ��)
A->Ab|a��A->aA2,A2->bA2|���ǵȼ۵ġ�����
�õ����ۣ�������˵�����ķ��ȼ۾���˵�������ķ��Ϳ������κ�ʱ�����⻥����

Ȼ������ͨ��������ݹ�ķ���д������ʽ��

E->TE2
E2->+TE2 | -TE2 | ��
T->*FT2
T2->*FT2 | /FT2 |��
F->(E) | i

Ȼ�󣬳���ͺ�д�ˡ�����ĳ���ֻ������������һλ���������

#include<cstdio>
char expr[100]="(1+8)/(5-2)-2*3-1";
int start=0;
double T();
double T2();
double F();
double E2();
double E()
{
	return T()+E2();
}
double E2()
{
	switch(expr[start])
	{
	case '+':start++;return T()+E2();
	case '-':start++;return -T()+E2();
	default:return 0;
	}
}
double T()
{
	return F()*T2();
}
double T2()
{
	double a,b;
	switch(expr[start])
	{
	case '*':start++;return F()*T2();
	case '/':start++;a=F(),b=T2();
		return b/a;
	default:return 1;
	}

}
double F()
{
	if(expr[start]=='(')
	{
		double a;
		start++;
		a=E();
		start++;
		return a;
	}
	return expr[start++]-'0';
}

int main()
{
	printf("%f\n",E());
}
