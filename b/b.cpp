#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define l128 __int128
using namespace std;
ll qpow(ll a,ll b,ll p)
{
	l128 ans=1;
	for(;b;b>>=1,a=(l128)a*a%p)
		if(b&1)
			ans=ans*a%p;
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a,b,p;
		scanf("%lld%lld%lld",&a,&b,&p);
		printf("%lld\n",qpow(a,b,p));
	}
	return 0;
}