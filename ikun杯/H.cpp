/*
 * @Author: JorD
 * @LastEditTime: 2023-04-12 18:58:23
 */
/*
 * @Author: JorD
 * @LastEditTime: 2023-04-12 18:54:03
 */
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long tr[N << 2];
int a[N], pre[N], ne[N];
inline void build(int l, int r, int p){
	if(l == r){
		tr[p] = a[l];
		return;
	} 
	int mid = (l + r) >> 1;
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1|1);
	tr[p] = min(tr[p << 1], tr[p << 1|1]);
}
inline int query(int l, int r, int p){
	if(l == r){
		return l;
	}
	int mid = l + r >> 1;
	if(tr[p << 1] <= tr[p << 1|1]) return query(l, mid, p << 1);
	return query(mid + 1, r, p << 1|1);
} 
inline long long query(int pos, int l, int r, int p){
	if(l == r){
		return tr[p];
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) return query(pos, l, mid, p << 1);
	return query(pos, mid + 1, r, p << 1|1);
} 
inline void modify(int pos, int l, int r, int p, int k){
	if(l == r){
		if(k == -1) tr[p] = 1e18;
		else tr[p] += k;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) modify(pos, l, mid, p << 1, k);
	else modify(pos, mid + 1, r, p << 1|1, k);
	tr[p] = min(tr[p << 1], tr[p << 1|1]);
	return;
}
int st[N];
int main(){
	int n, k;
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i ++){
		scanf("%d",&a[i]);
		pre[i] = i - 1;
		ne[i] = i + 1;
	} 
	build(1, n, 1);
	for(int i = 1;i <= k;i ++){
		int now = query(1, n, 1);
		long long w = tr[1];
		int l = pre[now], r = ne[now];
		ne[l] = r;
		pre[r] = l;
		modify(now, 1, n, 1, -1);
		modify(l, 1, n, 1, w);
		modify(r, 1, n, 1, w);
		st[now] = -1;
	}
	for(int i = 1;i <= n;i ++)if(st[i] != -1){
		printf("%lld ", query(i, 1, n, 1));
	}
	return 0;	
}
