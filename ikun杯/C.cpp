#include<bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
long long up[N], down[N];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1;i <= n;i ++){
		long long x, y;
		scanf("%lld%lld",&x,&y);
		long long l = 1, r = 1e9;
		while(l < r){
			long long mid = (l + r + 1) >> 1;
			if(y * mid <= x) l = mid;
			else r = mid - 1;
		}
		up[i] = l;
		l = 1, r = 1e9;
		while(l < r){
			long long mid = (l + r) >> 1;
			if((y + 1) * mid > x) r = mid;
			else l = mid + 1;
		}
		down[i] = r;
	}
	long long res1 = down[1], res2 = up[1];
	for(int i = 1;i <= n;i ++){
		res1 = max(down[i], res1);
		res2 = min(up[i], res2); 
	}
	printf("%lld %lld", res1, res2);
	return 0;
}
