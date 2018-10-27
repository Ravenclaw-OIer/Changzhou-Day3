#include <bits/stdc++.h>
using namespace std;
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
string ans[501];
bool ak;
bool zero;
int str_size;
vector<string>vec;
bool check(int n,int m,int k1,int k2,string str)
{
	int x=0,y=0;
	for (int i=0;i<n;i++)
	{
		bool ac=true;
		bool wa=true;
		for (int j=0;j<m;j++)
			if (str[j]==ans[i][j])
				wa=false;
			else
				ac=false;
		if (wa)y++;
		if (ac)x++;
		if (x>k1||y>k2)return false;//prune
	}
	if (x==k1&&y==k2)
		return true;
	else
		return false;
}
bool done=false;
void dfs(int n,int m,int k1,int k2,int dep,string res)
{

	if (dep==m)
  		vec.push_back(res);
	else
	{
		if (k1==0||k2==0){//prune
			int x=0,y=0;
			for (int i=0;i<n;i++)
			{
				bool ok=false;
				bool ac,wa;
				ac=wa=false;
				for (int j=0;j<dep;j++)
					if (ans[i][j]==res[j])wa=0;else ac=0;
				if (ac)x++;
				if (wa)y++;
				if (x>k1||y>k2)
				{
					cout<<-1<<endl;
					done=true;
					return;
				}
			}
		}
		dfs(n,m,k1,k2,dep+1,res+"N");
		dfs(n,m,k1,k2,dep+1,res+"Y");
		
	}
}

int main(void)
{
	freopen("accepted.in","r",stdin);
	freopen("accepted.out","w",stdout);
	int T;
	T=readInt();
	while (T--)
	{
		bool found=false;done=false;
		int n,m,k1,k2;
		n=readInt();
		m=readInt();
		k1=readInt();
		k2=readInt();
		for (int i=0;i<n;i++)cin>>ans[i];
		dfs(n,m,k1,k2,0,"");
		if (done)continue;
		for (int i=0;i<vec.size();i++)
		if (check(n,m,k1,k2,vec[i]))
		{
			cout<<vec[i]<<endl;
			found=true;
			break;
		}
//		cerr<<found<<endl;
		if (!found)cout<<-1<<endl;
//		cerr<<"--------------"<<endl;
		vec.clear();
	}

	return 0;
}

