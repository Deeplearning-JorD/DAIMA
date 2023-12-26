/*
 * @Author: JorD
 * @LastEditTime: 2023-04-11 17:51:52
 */
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dp[N], l[N], r[N];
bool st[N]; 
int now;
int n;
void dfs(int i, int st, int up){
	if(n - i + 1 <= st){
		printf("%d", now);
		exit(0); 
	}
	if(i > n) return;
	if(l[i] == up || up == -1)
	dfs(i + 1, st, r[i]);
	dfs(i + 1, st - 1, up);
}
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		int x; scanf("%d",&x);
		int now = 0;
		r[i] = x % 10;
		while(x){
			now = now * 10 + (x % 10);
			x /= 10; 
		}
		l[i] = now % 10;
	}
	for(int i = 1;i <= n;i ++){
		now = i;
		dfs(1, i, -1);
	}
	return 0;
}
