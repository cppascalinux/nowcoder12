#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{
	return !b?a:gcd(b,a%b);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("g.in","r",stdin);
	freopen("g.out","w",stdout);
#endif
	ll a,b;
	scanf("%lld%lld",&a,&b);
	printf("%lld",gcd(a,b));
	return 0;
}