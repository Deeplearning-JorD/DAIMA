#pragma GCC optimize(2)
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
void Solve(){
    ll a, b; cin >> a >> b;
    ll l = 2, r = 1e7;
    while(l < r){
        ll mid = l + r >> 1;
        if(2 * mid >= a) r = mid;
        else l = mid + 1; 
    }
    if(2 * r <= b) cout << 2 << ' ' << 2 * (r - 1) << endl;
    else{
        if(a == b){
            for(int i = 2;i <= b / i;i ++){
                if(b % i == 0){
                    cout << i << ' ' << i * (b / i - 1) << endl;
                    return;
                }
            }
        }
        cout << -1 << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}