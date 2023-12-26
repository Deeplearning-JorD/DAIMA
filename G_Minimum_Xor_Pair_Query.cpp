/*
 * @Author: JorD
 * @LastEditTime: 2023-07-06 15:30:59
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
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
#define ls tr[p].l
#define rs tr[p].r
const int N = 3e5 + 10, inf = 3e9;
struct node{
    int l, r, res, sum, val;
}tr[N * 33];
int idx = 1;
void update(int p, int x, int i){
    tr[p].res = inf;
    tr[p].val = 0;
    if(tr[ls].sum == 1 && tr[rs].sum == 1){
        tr[p].res = min(tr[p].res, tr[ls].val ^ tr[rs].val);
    }
    if(tr[ls].sum >= 2){
        tr[p].res = min(tr[ls].res, tr[p].res);
    }
    if(tr[rs].sum >= 2){
        tr[p].res = min(tr[rs].res, tr[p].res);
    }
    if(tr[p].sum == 1){
        if(tr[ls].sum == 1) tr[p].val = tr[ls].val;
        else tr[p].val = tr[rs].val;
        tr[p].val |= x & (1 << (i+1));
    }
}
void add(int x, int p, int i){ 
    int c = x >> i & 1;
    if(i < 0){
        if(!tr[p].sum){
            tr[p].sum = 1;
            tr[p].val = x >> (i + 1) & 1;
            tr[p].res = inf;
        }else{
            tr[p].sum ++;
            tr[p].res = 0;
        }
        return;
    }
    if(c){
        if(!tr[p].l) tr[p].l = ++ idx;
        add(x, tr[p].l, i - 1);
    }else{
        if(!tr[p].r) tr[p].r = ++ idx;
        add(x, tr[p].r, i - 1);
    }
    tr[p].sum ++;
    update(p, x, i);
    return;
}
void del(int x, int p, int i){
    int c = x >> i & 1;
    if(i < 0){
        if(tr[p].sum <= 2){
            tr[p].sum --;
            tr[p].val = x >> (i + 1) & 1;
            tr[p].res = inf;
        }else{
            tr[p].sum --;
            tr[p].res = 0;
        }
        return;
    }
    if(c){
        if(!tr[p].l) tr[p].l = ++ idx;
        del(x, tr[p].l, i - 1);
    }else{
        if(!tr[p].r) tr[p].r = ++ idx;
        del(x, tr[p].r, i - 1);
    }
    tr[p].sum --;
    update(p, x, i);
    return;
}
void Solve(){
    int m;
    cin >> m; 
    while(m --){
        int op; cin >> op;
        if(op == 3){
            cout << tr[1].res << endl;
            continue;
        }
        int x; cin >> x;
        if(op == 1) add(x, 1, 30);
        else del(x, 1, 30);
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}