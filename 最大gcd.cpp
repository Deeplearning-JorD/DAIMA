/*
 * @Author: JorD
 * @LastEditTime: 2022-09-16 21:29:02
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
const int N = 1e6 + 10;
void Solve(){
    int n;
    cin >> n;
    ll res = 0;
    int maxn = 0;
    vector<int> st(1e6 + 10);
    rep(i, 1, n){int x;cin >> x;st[x] ++;maxn = max(maxn, x);}
    per(i, maxn, 1){
        int js = 0;
        for(int j = i;j <= maxn;j += i){
            js += st[j];
            if(js > 1){
                cout << i << endl;
                return;
            }
        }
    }
    // cout<<(1<<22) * 22;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}