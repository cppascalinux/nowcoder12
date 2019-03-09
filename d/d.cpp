#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n,m;
int vis[1000009],pm[1000009],mu[1000009];
ll sm[1000009],f[1000009],ans[1000009];
void init()
{
	vis[1]=mu[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			pm[++m]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=m&&i*pm[j]<=n;j++)
		{
			int p=i*pm[j];
			vis[p]=1;
			if(i%pm[j]==0)
			{
				mu[p]=0;
				break;
			}
			mu[p]=-mu[i];
		}
	}
}
void getf()
{
	for(int i=1;i<=n;i++)
		sm[i]=sm[i-1]+i;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			f[j]+=i*mu[i]*sm[j/i];
}
void solve()
{
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			ans[j]+=f[j/i];
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	scanf("%d",&n);
	init();
	getf();
	solve();
	for(int i=1;i<=n;i++)
		printf("%lld\n",ans[i]);
	return 0;
}