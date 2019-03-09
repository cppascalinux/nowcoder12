// #pragma GCC optimize(2)
// #pragma GCC optimize(3)
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("-falign-jumps")
// #pragma GCC optimize("-falign-loops")
// #pragma GCC optimize("-falign-labels")
// #pragma GCC optimize("-fdevirtualize")
// #pragma GCC optimize("-fcaller-saves")
// #pragma GCC optimize("-fcrossjumping")
// #pragma GCC optimize("-fthread-jumps")
// #pragma GCC optimize("-funroll-loops")
// #pragma GCC optimize("-fwhole-program")
// #pragma GCC optimize("-freorder-blocks")
// #pragma GCC optimize("-fschedule-insns")
// #pragma GCC optimize("inline-functions")
// #pragma GCC optimize("-ftree-tail-merge")
// #pragma GCC optimize("-fschedule-insns2")
// #pragma GCC optimize("-fstrict-aliasing")
// #pragma GCC optimize("-fstrict-overflow")
// #pragma GCC optimize("-falign-functions")
// #pragma GCC optimize("-fcse-skip-blocks")
// #pragma GCC optimize("-fcse-follow-jumps")
// #pragma GCC optimize("-fsched-interblock")
// #pragma GCC optimize("-fpartial-inlining")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("-freorder-functions")
// #pragma GCC optimize("-findirect-inlining")
// #pragma GCC optimize("-frerun-cse-after-loop")
// #pragma GCC optimize("inline-small-functions")
// #pragma GCC optimize("-finline-small-functions")
// #pragma GCC optimize("-ftree-switch-conversion")
// #pragma GCC optimize("-foptimize-sibling-calls")
// #pragma GCC optimize("-fexpensive-optimizations")
// #pragma GCC optimize("-funsafe-loop-optimizations")
// #pragma GCC optimize("inline-functions-called-once")
// #pragma GCC optimize("-fdelete-null-pointer-checks")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 1000000007
#define ll long long
using namespace std;
int n;
int sm[13000009],bs[13000009];
inline int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)
			ans=(ll)ans*a%mod;
	return ans;
}
void solve2()
{
	int b=n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		sm[i]=1;
		bs[i]=i;
	}
	for(;b;b>>=1)
	{
		if(b&1)
			for(int i=1;i<=n;i++)
				sm[i]=(ll)sm[i]*bs[i]%mod;
		for(int i=1;i<=n;i++)
			bs[i]=(ll)bs[i]*bs[i]%mod;
	}
	for(int i=1;i<=n;i++)
		ans^=sm[i];
	printf("%d",ans);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	scanf("%d",&n);
	solve2();
	// int ans1=0,ans2=0,ans3=0,ans4=0,cur=0;
	// for(int i=1;i<=n;i+=4)
	// {
	// 	int sm1=1,a1=i,b1=n;
	// 	for(;b1;b1>>=1,a1=(ll)a1*a1%mod)
	// 		if(b1&1)
	// 			sm1=(ll)sm1*a1%mod;
	// 	ans1^=sm1;
		
	// 	int sm2=1,a2=i+1,b2=n;
	// 	for(;b2;b2>>=1,a2=(ll)a2*a2%mod)
	// 		if(b2&1)
	// 			sm2=(ll)sm2*a2%mod;
	// 	ans2^=sm2;

	// 	int sm3=1,a3=i+2,b3=n;
	// 	for(;b3;b3>>=1,a3=(ll)a3*a3%mod)
	// 		if(b3&1)
	// 			sm3=(ll)sm3*a3%mod;
	// 	ans3^=sm3;

	// 	int sm4=1,a4=i+3,b4=n;
	// 	for(;b4;b4>>=1,a4=(ll)a4*a4%mod)
	// 		if(b4&1)
	// 			sm4=(ll)sm4*a4%mod;
	// 	ans4^=sm4;

	// 	cur=i+3;
	// }
	// for(int i=cur+1;i<=n;i++)
	// 	ans1^=qpow(i,n);
	// printf("%d",ans1^ans2^ans3^ans4);
	return 0;
}