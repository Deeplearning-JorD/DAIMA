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
const int N = 2e5 + 10;
int h[N], st[N];
void Solve(){
    int n, m, k;
    cin >> n >> m >> k;
    rep(i, 1, m){
        int op, x;
        cin >> op >> x;
        if(op == 1){
            if(st[x]) h[x] += min(k, i - st[x]);
            st[x] = i;
        }else if(op == 2){
            if(st[x]) h[x] += min(k, i - st[x]);
            st[x] = 0;
        }else if(op == 3){
            if(st[x] && i - st[x] >= k){h[x] += k;st[x] = 0;}
            cout << i - 1 + h[x] + (st[x]?(i - st[x] ):0) << endl; 
        }
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