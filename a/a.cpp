#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m;
pii s[100009];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d %d",&s[i].fi,&s[i].se);
	sort(s+1,s+m+1);
	int cur=0,ans=0,tmp=0;
	s[m+1].fi=n+1;
	for(int i=1;i<=m;i++)
	{
		if(s[i].fi<=cur+1)
		{
			tmp=max(tmp,s[i].se);
			if(s[i+1].fi>cur+1)
			{
				ans++;
				cur=tmp;
				tmp=0;
			}
		}
	}
	if(cur>=n)
		printf("%d",ans);
	else
		printf("-1");
	return 0;
}