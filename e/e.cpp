#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n,k;
int l[200009];
int judge(int x)
{
	ll sm=0;
	for(int i=1;i<=n;i++)
		sm+=l[i]/x;
	return sm>=k;
}
int bin()
{
	int l=0,r=1000000000,mid;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(judge(mid))
			l=mid;
		else
			r=mid-1;
	}
	return l;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
#endif
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",l+i);
	printf("%d",bin());
	return 0;
}