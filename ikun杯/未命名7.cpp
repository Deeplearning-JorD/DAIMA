#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<pair<int,int>> son[N];
int depth[N], fat[N][25], num[N];
long long pre[N];
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
		pre[x] = pre[now] + w;
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
int n, m;
long long get(int x, int y){
	if(x < 1 || y > n || y < 1) return 0;
	long long sum = 0;
	sum = pre[x] + pre[y] - 2 * pre[lca(x, y)];
	return sum;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i < n;i ++){
		int x, y, c;
		scanf("%d%d%d",&x,&y,&c);
		son[x].push_back({y, c});
		son[y].push_back({x, c});
	}
	dfs(1, 0);
	long long sum = 0;
	for(int i = 1;i <= m;i ++){
		scanf("%d", &num[i]);
		sum += get(num[i - 1], num[i]);
	}
	for(int i = 1;i <= m;i ++){
		printf("%lld ", sum - get(num[i - 1], num[i]) - get(num[i], num[i + 1]) + get(num[i - 1], num[i + 1]));
	}
	return 0;
}
