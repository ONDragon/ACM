#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int inf = 100000000;
int flag;
//ģ��ԭ�Ͳ�������hdu hh��ģ��
typedef long long LL;
#define FF(i,A,s) for(int i = A[s];i != s;i = A[i])
const int maxm = 804000;
const int maxn = 400;
int used[1400],sr[1400];
int sign[400];
int n,m,d;
int map[100][100];
int si[1300],ei[1300];
void init()
{
	memset(used,0,sizeof(used));
	memset(sign,0,sizeof(sign));
}

struct DLX{
	int R[maxm],L[maxm],U[maxm],D[maxm];
	int col[maxm],row[maxm];
	int s[maxn];bool hash[maxn]; //�ظ�����
	int pre,first,sz,NV,limit;
	void init(int n)  //�е���Ŀ
	{
		int i;
		for(i = 0;i <= n;i ++)
		{
			U[i] = i;D[i] = i;
			col[i] = i;   //
			L[i] = i-1,R[i] = i+1;
		}
		NV = n;sz = n+1;pre = -1;first = 0;
		memset(s,0,sizeof(s));
	}
	void insert(int i,int j)    //һ��һ�еĲ�������i��j��
	{
		if(i != pre)  //pre��ʾǰһ�У������ͬ���͸���ǰ�����е�����
		{
			R[sz-1] = first;L[first] = sz -1;
			pre = i;first = sz;
		}
		L[sz] = sz - 1;R[sz] = sz+1;  //���Խ�j�п����������ײ�.
		D[U[j]] = sz;
		D[sz] = j;U[sz] = U[j];U[j] = sz;
		row[sz] = i,col[sz] = j,s[j] ++;
		sz ++;
	}
	void finish() { R[sz-1] = first;L[first] = sz - 1;}
	void EXremove(int c){    //ɾ��c��,������c���ظ����о�ȷ����
		L[R[c]] = L[c];R[L[c]] = R[c];
		FF(i,D,c) FF(j,R,i) U[D[j]] = U[j],D[U[j]] = D[j],--s[col[j]];
	}
	void EXresume(int c){   //�ָ�c��,������c���ظ�����
		FF(i,U,c) FF(j,L,i) ++s[col[j]],U[D[j]] = j,D[U[j]] = j;
		L[R[c]] = c;R[L[c]] = c;
	}
	//ѡ���У�ʹÿһ�н���һ��
	bool dfs(const int &k) //��ȷ���ǣ�ѡ����k���ˡ�
	{
		//if(k >= flag) return false;
		if(flag) return true;
		if(R[0] == 0||R[0] > n*d)
		{
			//if(flag > k) flag = k;
			flag = 1;
			return true;
		}
		//if(R[0] == 0) return true; //�ҵ���
		int idx = R[0],i;
		for(i = R[0] ;i != 0&&i <= n*d;i = R[i]) if(s[idx] > s[i]) idx = i;
		EXremove(col[idx]);
		FF(i,D,idx){
			used[row[i]] = 1;
			FF(j,R,i) EXremove(col[j]);
			if(dfs(k+1)) return true;  //������һ����
			FF(j,L,i) EXresume(col[j]);
			used[row[i]] = 0;
		}
		EXresume(col[idx]);
		return false;
	}
	//�ظ�����,ѡ�������У����е��б�����,������ӵġ�
	void remove(int & c) { FF(i,D,c) L[R[i]] = L[i],R[L[i]] = R[i]; } //ȥ��ĳ��
	void resume(int & c) { FF(i,U,c) L[R[i]] = i,R[L[i]] = i; }
	int h(){  //f��������
		int ret = 0;
		memset(hash,false,sizeof(hash));
		for(int c = R[0];c != 0;c = R[c]) if(!hash[c]){ //�����޸�c !=  0����
			hash[c] = true;  ret ++;
			FF(i,D,c)
				FF(j,R,i) hash[col[j]] = true;
		}
		return ret;
	}
	//�ظ����ǣ�ֻɾ���в�ɾ����
	bool dfs(const int & k,int & limit)
	{
		if(k+h() >= limit) return false;
		if(R[0] == 0)
		{
			if(k < limit) limit = k; return true;
		}
		int idx = R[0],i;
		for(i = R[0] ;i != 0;i = R[i]) if(s[idx] > s[i]) idx = i;
		FF(i,D,idx){
			remove(i);
			FF(j,R,i) remove(j);
			if(dfs(k+1,limit)) return true;
			FF(j,L,i) resume(j);
			resume(i);
		}
		return false;
	}
	int astar()  //or ���֡�
	{
		limit = h();
		while(!dfs(0,limit)) limit ++;  //�޸ĵ㣬limit�������
		return limit;
	}
};
DLX dlx;

int main()
{
	int i,j,k,l1,l2,a,b,nt = 0,row;
	while(scanf("%d%d%d",&n,&m,&d)!=EOF)
	{
		init();
		nt ++;
		dlx.init(n*(d+1));
		for(i = 0;i < m;i ++)
		{
			scanf("%d%d",&a,&b);
			map[a][b] = map[b][a] = nt;
		}
		/*You can choose a sub-range of the available range as the working time for each station.
		Note that you can only choose one sub-range for each available range,
		that is, once the station stops working, you cannot restart it again.
		Of course, it is possible not to use any of them.
		*/
		//��һ��wa�����ǿ��α�����.
		row = 1;
		for(i = 1;i <= n;i ++)
		{
			scanf("%d%d",&a,&b); //ÿһ����ׯ�������ʱ��
			for(k = a;k <= b;k ++)
			{
				for(j = k;j <= b;j ++)
				{
					dlx.insert(row,n*d+i); //�����Լ���ȷ��ֻ��ѡһ��
					for(l1 = k;l1 <= j;l1 ++)
					{
						dlx.insert(row,(l1-1)*n+i);
						for(l2 = 1;l2 <= n;l2 ++)
						 if(map[i][l2] == nt) dlx.insert(row,(l1-1)*n+l2);
					}
					sr[row] = i;
					si[row] = k;
					ei[row++] = j;
				}
			}
		}
		dlx.finish();
		flag = 0;
		if(dlx.dfs(0))
		{
		for(i = 1;i < row;i ++)
		{
			if(used[i]) sign[sr[i]] = i;
		}
		for(i = 1;i <= n;i ++)
			if(sign[i]) printf("%d %d\n",si[sign[i]],ei[sign[i]]);
			else puts("0 0");
		}else puts("No solution");
		printf("\n");
	}
	return 0;
}