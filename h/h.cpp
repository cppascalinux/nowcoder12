#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc() (p1==p2&&(p2=(p1=buffer)+fread(buffer,1,10000000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
struct node
{
	int typ,tme,x,y;//1:modify 2:add 3:sub
	node(){}
	node(int a,int b,int c,int d)
	{
		typ=a;
		tme=b;
		x=c;
		y=d;
	}
	bool operator <(const node &p) const
	{
		return tme<p.tme||(tme==p.tme&&typ<p.typ);
	}
};
char *p1,*p2,buffer[10000009];
int n,tot,m,q,cnt;
int hd[100009],eg[200009],nxt[200009];
int dfn[100009],ed[100009];
int c[100009],sub[100009];
int fst[100009];
node p[800009];
void rd(int &x)
{
	char ch=0;
	x=0;
	while(ch<'0'||ch>'9')
		ch=gc();
	while(ch>='0'&&ch<='9')
		x=x*10+(ch&15),ch=gc();
}
void ins(int a,int b)
{
	eg[++tot]=b;
	nxt[tot]=hd[a];
	hd[a]=tot;
}
void add(int x,int val)
{
	for(;x;x-=x&-x)
		c[x]+=val;
}
int ask(int x)
{
	int val=0;
	for(;x<=n;x+=x&-x)
		val+=c[x];
	return val;
}
void dfs(int x,int fa)
{
	ed[x]=dfn[x]=++cnt;
	for(int i=hd[x];i;i=nxt[i])
	{
		dfs(eg[i],x);
		ed[x]=max(ed[x],ed[eg[i]]);
	}
}
void solve()
{
	sort(p+1,p+q+1);
	for(int i=1;i<=q;i++)
	{
		node &t=p[i];
		if(t.typ==1)
		{
			add(ed[t.x],t.y);
			add(dfn[t.x]-1,-t.y);
		}
		else if(t.typ==2)
		{
			t.y+=ask(dfn[t.x]);
		}
		else
		{
			sub[t.x]=ask(dfn[t.x]);
		}
	}
	for(int i=1;i<=q;i++)
		if(p[i].typ==2)
			printf("%d\n",p[i].y-sub[p[i].x]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("h.in","r",stdin);
	freopen("h.out","w",stdout);
#endif
	scanf("%d",&m);
	n=1;
	for(int i=1,a,b,c;i<=m;i++)
	{
		scanf("%d",&a);
		if(a==1)
		{
			scanf("%d",&b);
			b++;
			n++;
			fst[n]=i-1;
			ins(b,n);
		}
		else if(a==2)
		{
			scanf("%d%d",&b,&c);
			b++;
			p[++q]=node(1,i,b,c);
		}
		else
		{
			scanf("%d",&b);
			b++;
			p[++q]=node(2,i,b,0);
		}
	}
	for(int i=1;i<=n;i++)
		p[++q]=node(3,fst[i],i,0);
	dfs(1,0);
	solve();
	return 0;
}