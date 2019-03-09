#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
using namespace std;
int n,m,mx,tp;
int vis[100009];
ll v[100009],sm[100009];
ll tmp[100009];
pii st[100009];
void rebuild()
{
	memset(tmp,0,sizeof(tmp));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=tp;i++)
	{
		int p=st[i].fi;
		tmp[p]+=st[i].se;
		vis[p]=1;
	}
	for(int i=1;i<=n;i++)
		if(vis[i])
			for(int j=i;j<=n;j+=i)
				v[j]+=tmp[i];
	for(int i=1;i<=n;i++)
		sm[i]=sm[i-1]+v[i];
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d sm;%lld\n",i,tmp[i]);
	tp=0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	mx=sqrt(n*20);
	for(int i=1,a,b,c;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
		{
			st[++tp]=pii(b,c);
			if(tp>mx)
				rebuild();
		}
		else
		{
			ll ans=sm[c]-sm[b-1];
			for(int j=1;j<=tp;j++)
			{
				int d=st[j].fi;
				ans+=(ll)(c/d-(b-1)/d)*st[j].se;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}