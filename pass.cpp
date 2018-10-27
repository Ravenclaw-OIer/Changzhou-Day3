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
bool check(int x,int y,int a,int b,int mid)
{
	if(floor(x*a/100.0+y*b/100.0+mid*(100-a-b)/100.0)>=60)return true;
	else if (fabs(floor(x*a/100.0+y*b/100.0+mid*(100-a-b)/100.0))-60<=1e-4)return true;
	return false;
}
int main(void)
{
	freopen("pass.in","r",stdin);
	freopen("pass.out","w",stdout);
	int T=readInt();
	while (T--)
	{
		int x,y,z,a,b;
		x=readInt();
		y=readInt();
		a=readInt();
		b=readInt();
		int mid,lbound,ubound;
		lbound=0;
		ubound=100;
		if (floor(x*a/100.0+y*b/100.0+100*(100-a-b)/100.0)<60)
		{
			cout<<"poor little A!"<<endl;
			continue;
		}
		while (lbound<ubound)
		{
			mid=(lbound+ubound)>>1;
			if (floor(x*a/100.0+y*b/100.0+mid*(100-a-b)/100.0)>=60||
				fabs(x*a/100.0+y*b/100.0+mid*(100-a-b)/100.0-60)<=1e-4)
				ubound=mid;
			else
				lbound=mid+1;
		}
		cout<<lbound<<endl;
	}
	return 0;
}

