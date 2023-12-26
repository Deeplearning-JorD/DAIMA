#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int dp[N];
int T[N], D[N], L[N];
void Solve(){
	memset(dp, 0x3f, sizeof(dp));
	int n;
	scanf("%d",&n);
	dp[0] = 0;
	for(int i = 1;i <= n;i ++){
		scanf("%d%d%d",&T[i],&D[i],&L[i]);
	}
	for(int i = 0;i < (1 << n);i ++){
		for(int j = 0;j < n;j ++){
			if((i >> j & 1) == 0){
				int now = i | (1 << j);
				if(dp[i] <= T[j + 1] + D[j + 1])
					dp[now] = min(dp[now], max(T[j + 1], dp[i]) + L[j + 1]);
			}
		}
	}
	int last = (1 << n) - 1;
	if(dp[last] != 0x3f3f3f3f) printf("YES\n");
	else printf("NO\n");
	return;
}
int main(){
	int t; scanf("%d",&t);
	while(t --) Solve();
	return 0;
}
