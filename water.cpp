#include <bits/stdc++.h>
using namespace std;
const int MAXN=305;
inline int readInt(){
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
set<int>a[MAXN];/*O(logn)*/
int c[MAXN];
inline void init(int n)/*O(n^2)*/
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			if (i%j==0)a[i].insert(j);
}
int main(void)
{

//	freopen("water.in","r",stdin);
//	freopen("water.out","w",stdout);
	int n,m;
//	n=m=300;
	n=readInt(),m=readInt();
	init(300);
	memset(c,0,sizeof(c));
	int ans=0;
	for (int i=1;i<=m;i++)/*round count*/
		for (int j=1;j<=n;j++)
			if (a[i].count(j))
			{
				c[j]=!c[j];
			}
			
	for (int i=1;i<=n;i++)if (c[i]==0)ans++;
	cout<<ans<<endl;
	return 0;
}

