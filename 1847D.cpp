/*
 * @Author: JorD
 * @LastEditTime: 2023-07-07 02:11:28
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
const int N = 5e5 + 10;
int f[N];
int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
ll w[N], id[N], fid[N];
int tr[N];
int n, m, q;
int lowbit(int x){
    return x & -x;
}
void add(int x,int k){
    for(;x <= n;x += lowbit(x)) tr[x] += k;
}
int sum(int x){
    int res = 0;
    for(;x;x -= lowbit(x)) res += tr[x];
    return res;
}
void Solve(){
    cin >> n >> m >> q;
    string s; cin >> s;
    s = ' ' + s;
    rep(i, 0, 2 * n) f[i] = id[i] = i;
    ll idx = 0;
    rep(i, 1, m){
        int l, r;
        cin >> l >> r;
        for(int j = find(l);j <= r;j = find(j)){
            w[j] = j - l + 1 + idx;
            f[find(j)] = find(j + 1);
        }
        idx += r - l + 1;
    }
    // w[i]对应的就是真正的下标
    sort(id + 1, id + 1 + n, [&](int i, int j){
        return w[i] < w[j];
    });
    int cc = 0, cd = 0;
    rep(i, 1, n){
        fid[id[i]] = i;
        if(!w[id[i]]){
            cc ++;
            cd += s[id[i]] - '0';
        }else add(i, (s[id[i]] - '0'));
    }
    while(q --){
        int ix, x; cin >> ix;
        if(w[ix]){
            x = fid[ix];
            int now = sum(x) - sum(x - 1);
            if(now == 0) add(x, 1);
            else add(x, -1);
        }else{
            if(s[ix] == '1') cd --, s[ix] = '0';
            else cd ++, s[ix] = '1';
        }
        int all = min(n - cc, sum(n) + cd);
        cout << all - sum(min(n, all + cc)) << endl;
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