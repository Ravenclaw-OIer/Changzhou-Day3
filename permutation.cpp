#include <bits/stdc++.h>
using namespace std;
const int MAXN=16;
int readInt(){
	int x=0,f=1;char c=cin.get();
	while (c<'0'||c>'9')
	{
		if (c=='-')
			f=-1;
			c=cin.get();
	}
	while (c<='9'&&c >='0')
	{
		x=x*10+c-'0';
		c=cin.get();
	}
	return x*f;
}
int r[MAXN],p[MAXN];
set<int>a[MAXN+1];/*O(logn)*/
set<int>b[MAXN+1];
void inita(int n)/*O(n^2)*/
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			if (i%j==0)a[i].insert(j);
}
void initb(int n)
{
	for (int i=1;i<=n;i++)
		for (int j=1;j*i<=n;j++)
			b[i].insert(j*i);
}
int main(void)
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	int T=readInt();
//	cerr<<"ok"<<endl;
	inita(MAXN);
	initb(MAXN);
	while (T--)
	{
		memset(r,0,sizeof(r));
		memset(p,0,sizeof(p));
		int n;
		n=readInt();
		int ans=0;
		for (int i=1;i<=n;i++)r[i]=readInt();
		for (int i=1;i<=n;i++)p[i]=i;/*initiallze permutation*/
		do
		{
			bool ok=true;
			for (int i=1;i<=n;i++)
				if (!((r[i]==1&&b[i].count(p[i]))||(r[i]==0&&a[i].count(p[i]))))
				{
					ok=false;
					break;
				}
			if (ok)ans++;
        }while (next_permutation(p+1,p+n+1));
        cout<<ans<<endl;
	}
	return 0;
}

