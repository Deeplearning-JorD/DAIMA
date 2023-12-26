#include<bits/stdc++.h>
using namespace std;
const int N = 66;
char f[N][N];
int st[N][N];
int mp[N][N];
int idx = 0;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int cnt;
void bfs(int sx, int sy){
	queue<pair<int,int>> q;
	q.push({sx, sy});
	st[sx][sy] = ++ idx;
	int i = 0;
	vector<pair<int,int>> v(n + 1);
	for(int i = 1;i <= n;i ++){
		v[i].first = 100;
		v[i].second = 0;
	} 
	bool kunkun = 0;
	int siz = 0;
	while(q.size()){
		pair<int,int> t = q.front(); q.pop();
		v[t.first].first = min(v[t.first].first, t.second);
		v[t.first].second = max(v[t.first].second, t.second);
		for(int i = 0;i < 4;i ++){
			int x = t.first + dx[i], y = t.second + dy[i];
			if(x == sx && y == sy){
//				cout << x << ' ' << y << "?" << endl;=
				kunkun = 1;
			}
			if(x < 1 || x > n || y < 1 || y > m || f[x][y] == '0' || st[x][y]) continue;
			q.push({x, y});
			st[x][y] = idx;
		}
	}
	if(!kunkun) return;
	bool cc = false;
	for(int i = 1;i <= n;i ++){
		if(v[i].first == 100 && v[i].second == 0){
			continue;
		}
		for(int j = v[i].first;j <= v[i].second;j ++){
			if(mp[i][j]) cc = true;
		}
	}
	if(cc) return;
	cnt ++;
//	cout << sx << ' ' << sy << endl;
	for(int i = 1;i <= n;i ++){
		if(v[i].first == 100 && v[i].second == 0){
			continue;
		}
		for(int j = v[i].first;j <= v[i].second;j ++){
			mp[i][j] = cnt;
		}
	}
	return;
}

//1
//5 5
//11111
//10001
//10101
//10001
//11111

//2
//5 5
//01111
//11001
//10101
//10001
//11111
//5 6
//111111
//100001
//010101
//100001
//111111
void Solve(){
	idx = 0;
	cnt = 0;
	memset(st, 0, sizeof st);
	memset(mp, 0, sizeof mp);
	cin >> n >> m; 
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			cin >> f[i][j];
		}
	}
	bool rule = 0;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++)if(!st[i][j] && f[i][j] != '0'){
			bfs(i, j);
		}
	}
//	cout << "cnt:" << cnt << endl;
	set<int> s;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			s.insert(mp[i][j]);
		}
	}
	vector<bool> use(idx + 1, 0);
	int js = 0;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++)if(f[i][j] == '1' && !mp[i][j] && !use[st[i][j]]){
			use[st[i][j]] = 1;
			js ++;			
//			cout << i << ' ' << j << endl;
		}
	}
	if(*s.begin() == 0) js --;
//	cout << cnt << endl;
	cout << s.size() + js << '\n';
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t --) Solve();
	return 0;
}
