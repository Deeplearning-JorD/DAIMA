#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

const int N=2e5+5;

int n;
int deg[N],pre[N];
set<int> out[N];
int inq[N],ql,qr;
int f[N],ref[N],sz[N];
int ans;

int getf(int u)
{
	return f[u]?f[u]=getf(f[u]):u;
}

int merge(int u,int v)
{
	if (u==v)
		return ref[u];
	int ru=ref[u],rv=ref[v],fu=getf(u);
	f[v]=fu;
	sz[fu]+=sz[v];
	if (out[ru].size()<out[rv].size())
		swap(ru,rv);
	set<int>::iterator it=out[rv].begin();
	int cnt=out[rv].size();
	for (int i=1;i<=cnt;i++)
	{
		int cur=*it;
		set<int>::iterator it2=out[ru].find(cur);
		if (it2==out[ru].end())
			out[ru].insert(cur);
		else
		{
			deg[cur]--;
			if (deg[cur]==1)
				inq[++qr]=cur;
		}
		pre[cur]=u;
		it++;
	}
	return ru;
}

void solve(int tc)
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		f[i]=pre[i]=0;
		out[i].clear();
	}
	ql=qr=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&deg[i]);
		for (int j=1;j<=deg[i];j++)
		{
			int u;
			scanf("%d",&u);
			pre[i]=u;
			out[u].insert(i);
		}
		if (deg[i]==1)
			inq[++qr]=i;
		sz[i]=1;
		ref[i]=i;
	}
	while (++ql<=qr)
	{
		int cur=inq[ql];
		int p=getf(pre[cur]);
		ref[p]=merge(p,cur);
	}
	ans=0;
	for (int i=1;i<=n;i++)
		ans=max(ans,sz[i]);
	printf("Case #%d: %d\n",tc,ans);
}

int main()
{
	int T,tc=0;
	scanf("%d",&T);
	while (T--)
		solve(++tc);
	return 0;
}