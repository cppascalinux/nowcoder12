#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,tot,cnt,ans;
int hd[100009],eg[600009],nxt[600009];
int dfn[100009],low[100009],ins[100009];
void add(int a,int b)
{
	eg[++tot]=b;
	nxt[tot]=hd[a];
	hd[a]=tot;
}
void dfs(int x,int fa)
{
	low[x]=dfn[x]=++cnt;
	ins[x]=1;
	for(int i=hd[x];i;i=nxt[i])
		if(eg[i]!=fa)
		{
			if(!dfn[eg[i]])
			{
				dfs(eg[i],x);
				low[x]=min(low[x],low[eg[i]]);
			}
			else if(ins[eg[i]])
				low[x]=min(low[x],dfn[eg[i]]);
		}
	ins[x]=0;
	// printf("x:%d dfn:%d low:%d\n",x,dfn[x],low[x]);
	if(dfn[x]==low[x])
		ans++;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("i.in","r",stdin);
	freopen("i.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1,a,b;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(1,0);
	printf("%d",m-ans+1);
	return 0;
}