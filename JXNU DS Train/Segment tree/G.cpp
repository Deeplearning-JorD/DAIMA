/*
 * @Author: JorD
 * @LastEditTime: 2022-12-21 16:45:36
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 1e5 + 10;
int tr[30][N << 2], lazy[30][N << 2];
char s[N];
int n, m;
void pushdown(int l, int r, int p, int o){
    if(lazy[o][p] == 0) return;
    int mid = l + r >> 1;
    if(lazy[o][p] == 1){
        tr[o][p << 1] = mid - l + 1;
        tr[o][p << 1|1] = r - mid;
    }else if(lazy[o][p] == -1){
        tr[o][p << 1] = 0;
        tr[o][p << 1|1] = 0;
    }
    lazy[o][p << 1] = lazy[o][p];
    lazy[o][p << 1|1] = lazy[o][p];
    lazy[o][p] = 0;
}
void pushup(int p, int o){
    tr[o][p] = tr[o][p << 1] + tr[o][p << 1|1];
}
void build(int l, int r, int p, int o){
    if(l == r){
        tr[o][p] = (s[l] - 'a') == o;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1, o);
    build(mid + 1, r, p << 1|1, o);
    pushup(p, o);
}
void update(int cl, int cr, int l, int r, int p, int k, int o){
    if(cl <= l && r <= cr){
        if(k == 1){
            tr[o][p] = r - l + 1; 
        }else if(k == -1){
            tr[o][p] = 0;
        }
        lazy[o][p] = k;
        return;
    }
    int mid = l + r >> 1;
    pushdown(l, r, p, o);
    if(cl <= mid) update(cl, cr, l, mid, p << 1, k, o);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, k, o);
    pushup(p, o);
}
int query(int cl, int cr, int l, int r, int p, int o){
    if(cl <= l && r <= cr){
        return tr[o][p];
    }
    int mid = l + r >> 1;
    int res = 0;
    pushdown(l, r, p, o);
    if(cl <= mid) res += query(cl, cr, l, mid, p << 1, o);
    if(cr > mid) res += query(cl, cr, mid + 1, r, p << 1|1, o);
    return res;    
}
void Solve(){
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    rep(i, 0, 25) build(1, n, 1, i);
    while(m --){
        int l, r, op;
        cin >> l >> r >> op;
        if(op == 1){
            int sum = 0;
            rep(i, 0, 25){
                int now = query(l, r, 1, n, 1, i);
                if(now){
                    update(l, r, 1, n, 1, -1, i);
                    update(l + sum, l + sum + now - 1, 1, n, 1, 1, i);
                }
                sum += now;
            }
        }else{
            int sum = 0;
            per(i, 25, 0){
                int now = query(l, r, 1, n, 1, i);
                if(now){
                    update(l, r, 1, n, 1, -1, i);
                    update(l + sum, l + sum + now - 1, 1, n, 1, 1, i);
                }
                sum += now;
            }
        }
    }
    rep(i, 1, n){
        rep(j, 0, 25){
            if(query(i, i, 1, n, 1, j)){
                cout << (char)('a' + j);
                break;
            }
        }
    }
    return;
}
int main(){
    Solve();
    return 0;
}