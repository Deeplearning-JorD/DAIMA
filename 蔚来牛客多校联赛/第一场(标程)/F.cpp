#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int inf = 0x3f3f3f3f;

struct dp{
	int f[2][2];
}neg = {-inf, -inf, -inf, -inf};

inline dp up(dp l, dp r){
	dp x;
	x.f[0][0] = max({l.f[0][0], r.f[0][0], l.f[0][0] + r.f[1][0], l.f[0][1] + r.f[0][0]});
	x.f[0][1] = max({l.f[0][1], r.f[0][1], l.f[0][0] + r.f[1][1], l.f[0][1] + r.f[0][1]});
	x.f[1][0] = max({l.f[1][0], r.f[1][0], l.f[1][0] + r.f[1][0], l.f[1][1] + r.f[0][0]});
	x.f[1][1] = max({l.f[1][1], r.f[1][1], l.f[1][0] + r.f[1][1], l.f[1][1] + r.f[0][1]});
	return x;
}

struct Node{
	int son[2], sum;
	dp f;
}t[maxn * 100];

#define ls(x) (t[x].son[0])
#define rs(x) (t[x].son[1])

inline void up(int x){
	t[x].f = up(t[ls(x)].f, t[rs(x)].f);
	t[x].sum = t[ls(x)].sum + t[rs(x)].sum;
}

int cnt;

void split(int &a, int &b, int l, int r, int ll, int rr){
	if(!a || ll <= l && r <= rr){
		b = a, a = 0;
		return;
	}
	int mid = l + r >> 1, L = 0, R = 0;
	if(mid >= ll) split(ls(a), L, l, mid, ll, rr);
	if(mid < rr) split(rs(a), R, mid + 1, r, ll, rr);
	if(L || R){
		b = ++cnt, ls(b) = L, rs(b) = R;
		up(a), up(b);
	}
}

int merge(int a, int b){
	if(!a || !b) return a | b;
	ls(a) = merge(ls(a), ls(b)), rs(a) = merge(rs(a), rs(b)), up(a);
	return a;
}

void modify(int x, int l, int r, int pos){
	if(l == r){
		t[x].f = neg;
		t[x].f.f[pos & 1][pos & 1] = 1;
		t[x].sum = 1;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x) = ++cnt, l, mid, pos);
	else modify(rs(x) = ++cnt, mid + 1, r, pos);
	up(x);
}

dp query(int x, int l, int r, int ll, int rr){
	if(!x) return neg;
	if(ll <= l && r <= rr) return t[x].f;
	int mid = l + r >> 1;
	dp ans = neg;
	if(mid >= ll) ans = up(query(ls(x), l, mid, ll, rr), ans);
	if(mid < rr) ans = up(ans, query(rs(x), mid + 1, r, ll, rr));
	return ans;
}

int queryL(int x, int l, int r, int d){
	if(l == r) return l;
	int mid = l + r >> 1;
	if(t[ls(x)].sum >= d) return queryL(ls(x), l, mid, d);
	return queryL(rs(x), mid + 1, r, d - t[ls(x)].sum);
}

int queryR(int x, int l, int r, int d){
	if(l == r) return l;
	int mid = l + r >> 1;
	if(t[rs(x)].sum >= d) return queryR(rs(x), mid + 1, r, d);
	return queryR(ls(x), l, mid, d - t[rs(x)].sum);
}

namespace Seg{
	dp sum[maxn << 2];
	
	#undef ls
	#undef rs
	
	#define ls(x) (x << 1)
	#define rs(x) (x << 1 | 1)
	
	inline void up(int x){
		sum[x] = up(sum[ls(x)], sum[rs(x)]);
	}
	
	void modify(int x, int l, int r, int pos, dp d){
		if(l == r){
			sum[x] = d;
			return;
		}
		int mid = l + r >> 1;
		if(mid >= pos) modify(ls(x), l, mid, pos, d);
		else modify(rs(x), mid + 1, r, pos, d);
		up(x);
	}
	
	dp query(int x, int l, int r, int ll, int rr){
		if(ll <= l && r <= rr) return sum[x];
		int mid = l + r >> 1;
		dp ans = neg;
		if(mid >= ll) ans = up(query(ls(x), l, mid, ll, rr), ans);
		if(mid < rr) ans = up(ans, query(rs(x), mid + 1, r, ll, rr));
		return ans;
	}
}

int n, m, x;
int opt, l, r;

typedef tuple<int, int, int, int> tup;// r, l, rt, opt

set<tup> st;

void add(int l, int r, int rt, int opt){
	st.insert(make_tuple(r, l, rt, opt));
	dp d = t[rt].f;
	if(opt == 2) swap(d.f[0][1], d.f[1][0]);
	Seg::modify(1, 1, n, l, d);
}

int main(){
	t[0].f = neg;
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		int rt = ++cnt;
		modify(rt, 1, n, x);
		add(i, i, rt, 1);
	}
	while(m--){
		scanf("%d%d%d", &opt, &l, &r);
		if(opt <= 2){
			int rt = 0;
			while(1){
				auto it = st.lower_bound(make_tuple(l, 0, 0, 0));
				if(it == st.end() || get<1>(*it) > r) break;
				tup x = *it;
				st.erase(it);
				int L = get<1>(x), R = get<0>(x), Rt = get<2>(x), Opt = get<3>(x);
				Seg::modify(1, 1, n, L, neg);
				if(l <= L && R <= r){
					rt = merge(rt, Rt);
				}else if(L < l && r < R){
					int lrt, rrt;
					if(Opt == 1){
						split(Rt, lrt, 1, n, 1, queryL(Rt, 1, n, l - L));
						split(Rt, rrt, 1, n, queryR(Rt, 1, n, R - r), n);
					}else{
						split(Rt, lrt, 1, n, queryR(Rt, 1, n, l - L), n);
						split(Rt, rrt, 1, n, 1, queryL(Rt, 1, n, R - r));
					}
					add(L, l - 1, lrt, Opt), add(r + 1, R, rrt, Opt);
					rt = Rt;
					break;
				}else if(R <= r){
					int lrt;
					if(Opt == 1){
						split(Rt, lrt, 1, n, 1, queryL(Rt, 1, n, l - L));
					}else{
						split(Rt, lrt, 1, n, queryR(Rt, 1, n, l - L), n);
					}
					add(L, l - 1, lrt, Opt);
					rt = merge(rt, Rt);
				}else if(L <= r){
					int rrt;
					if(Opt == 1){
						split(Rt, rrt, 1, n, queryR(Rt, 1, n, R - r), n);
					}else{
						split(Rt, rrt, 1, n, 1, queryL(Rt, 1, n, R - r));
					}
					add(r + 1, R, rrt, Opt);
					rt = merge(rt, Rt);
					break;
				}
			}
			add(l, r, rt, opt);
		}else{
			auto it = st.lower_bound(make_tuple(l, 0, 0, 0));
			tup x = *it;
			int L = get<1>(x), R = get<0>(x), Rt = get<2>(x), Opt = get<3>(x);
			dp ans;
			if(L <= l && r <= R){
				if(Opt == 1){
					ans = query(Rt, 1, n, queryL(Rt, 1, n, l - L + 1), queryR(Rt, 1, n, R - r + 1));
				}else{
					ans = query(Rt, 1, n, queryL(Rt, 1, n, R - r + 1), queryR(Rt, 1, n, l - L + 1));
				}
			}else{
				dp ansL, ansR;
				if(Opt == 1){
					ansL = query(Rt, 1, n, queryL(Rt, 1, n, l - L + 1), n);
				}else{
					ansL = query(Rt, 1, n, 1, queryR(Rt, 1, n, l - L + 1));
					swap(ansL.f[0][1], ansL.f[1][0]);
				}
				int lpos = R + 1;
				it = st.lower_bound(make_tuple(r, 0, 0, 0));
				if(it == st.end() || get<1>(*it) > r) --it;
				tup x = *it;
				L = get<1>(x), R = get<0>(x), Rt = get<2>(x), Opt = get<3>(x);
				if(Opt == 1){
					ansR = query(Rt, 1, n, 1, queryR(Rt, 1, n, R - r + 1));
				}else{
					ansR = query(Rt, 1, n, queryL(Rt, 1, n, R - r + 1), n);
					swap(ansR.f[0][1], ansR.f[1][0]);
				}
				int rpos = L - 1;
				if(lpos <= rpos) ans = up(ansL, up(Seg::query(1, 1, n, lpos, rpos), ansR));
				else ans = up(ansL, ansR);
			}
			printf("%d\n", max({ans.f[0][0], ans.f[0][1], ans.f[1][0], ans.f[1][1]}));
		}
	}
}
/*
3 3
1 3 2
3 1 3
1 2 3
3 1 3

10 2
1 4 3 5 6 2 9 8 10 7
2 1 5
3 1 6

10 6
1 4 3 5 6 2 9 8 10 7
2 1 5
3 1 6
1 2 6
3 1 7
2 1 10
3 1 10

10 4
1 4 3 5 6 2 9 8 10 7
2 1 5
3 1 6
1 3 4
3 1 6

10 4
6 4 3 2 10 7 8 1 5 9
1 6 8
1 8 8
3 5 9
3 6 7

*/

// 6 5 4 3 1 2 9 8 10 7
// 6 1 2 3 4 5 9 8 10 7
