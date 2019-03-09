#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
char s[1000009],t[1000009];
int pos[27][1000009],tp[27];
void init()
{
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		s[i]-='a'-1;
	for(int i=1;i<=n;i++)
		pos[s[i]][++tp[s[i]]]=i;
	// for(int i=1;i<=26;i++)
	// {
	// 	printf("%c ",i+'a'-1);
	// 	for(int j=1;j<=tp[i];j++)
	// 		printf("%d ",pos[i][j]);
	// 	printf("\n");
	// }
}
void solve()
{
	int l=strlen(t+1);
	for(int i=1;i<=l;i++)
		t[i]-='a'-1;
	int cur=0;
	for(int i=1;i<=l;i++)
	{
		int p=t[i];
		int nxt=upper_bound(pos[p]+1,pos[p]+tp[p]+1,cur)-pos[p];
		if(nxt==tp[p]+1)
		{
			puts("No");
			return;
		}
		// printf("cur:%d\n",cur);
		cur=pos[p][nxt];
	}
	puts("Yes");
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("j.in","r",stdin);
	freopen("j.out","w",stdout);
#endif
	scanf("%s",s+1);
	init();
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",t+1);
		solve();
	}
	return 0;
}