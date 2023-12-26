#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<pair<int,int>> son[N];
int depth[N], fat[N][25], zson[N], id[N], c[N], siz[N];
int dist[N];
void dfs(int now, int fa){
	fat[now][0] = fa;
	depth[now] = depth[fa] + 1;
	for(int i = 1;i <= 23;i ++){
		fat[now][i] = fat[fat[now][i - 1]][i - 1];
	}
	for(auto u:son[now]){
		int x = u.first, w = u.second;
		if(x == fa) continue;
		id[x] = w;
		dfs(x, now);
	}
} 
int lca(int x, int y){
	if(depth[x] > depth[y]) swap(x, y);
	for(int i = 23;i >= 0;i --){
		if(depth[fat[y][i]] >= depth[x]) y = fat[y][i];
	}
	if(x == y) return x;
	for(int i = 23;i >= 0;i --)if(fat[x][i] != fat[y][i]){
		x = fat[x][i];
		y = fat[y][i];
	}
	return fat[x][0];
}
void ddfs(int now, int fa){
	for(auto u:son[now]){
		int x = u.first;
		if(x == fa) continue;
		ddfs(x, now);
		c[now] += c[x];
	}
}
int main(){
	int n, m; scanf("%d%d",&n,&m);
	for(int i = 1;i < n;i ++){
		int x, y;
		scanf("%d%d",&x,&y);
		son[x].push_back({y, i});
		son[y].push_back({x, i});
	}
	dfs(1, 0);
	for(int i = 1;i <= m;i ++){
		int x, y;
		cin >> x >> y;
		c[x] ++;
		c[y] ++;
		c[lca(x, y)] -= 2;
	}	
	ddfs(1, 0);
	int res = -1;
	for(int i = 1;i <= n;i ++){
		if(c[i] == m){
			res = max(res, id[i]);
		}
	}
	printf("%d", res);
	return 0;
}
