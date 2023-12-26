/*
 * @Author: JorD
 * @LastEditTime: 2022-09-02 19:53:33
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
struct node{
    int l, r, num, js;
};
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<node> a(m + 1,{-1, -1, 0, 0});
    vector<bool> st(n + 1);
    vector<int> num(n + 1, 1);
    rep(i, 1, m){
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        a[i] = {l, r, x, y};
    }
    sort(a.begin(),a.end(),[](node a, node b){
        if(a.r == b.r) return a.l > b.l;
        return a.r < b.r;
    });
    rep(i, 1, m){
        int sum = 0, mb = a[i].js, x = a[i].num;
        rep(j, a[i].l, a[i].r){
            if(st[j]||sum == mb) continue;
            num[j] = x;
            st[j] = true;
            sum ++;
            if(sum == mb) break;
        }
        if(sum != mb){
            cout << "qcjjddw" << endl;
            return;
        }
    }
    rep(i, 1, n){
        cout << num[i] << ' ';
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}