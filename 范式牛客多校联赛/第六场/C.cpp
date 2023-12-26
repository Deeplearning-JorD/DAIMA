
#include <bits/stdc++.h>
using namespace std;
using ll = __int128;
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
    long long n;
    cin >> n;
    ll k = 5;
    ll res = 0;
    if(n & 1){
        ll m = n;
        n --;
        while(k <= m){
            res += m / k - (m / (2 * k));
            k *= 5;
        }
        k = 5;
    }
    while(k <= n){
        res += ((k / 2 + k / 2 + (n / (2 * k) - 1) * 2 * k) * (n / (2 * k))) / 2;
        if((n % (2 * k)) / 2 + 1 < k / 2 + 1){
            res += ((n % (2 * k)) / 2 + 1) * ((n / (2 * k)) * 2);
        }else res += (k / 2 + 1) * ((n / (2 * k)) * 2);
        if((n % (2 * k)) / 2 + 1 - (k / 2 + 1) > 0)
        res += ((n % (2 * k)) / 2 + 1 - (k / 2 + 1)) * ((n / (2 * k)) * 2 + 1);
        k *= 5;
    }
    vector<int> ls;
    while(res){
        ls.push_back((int)(res%10));
        res /= 10;
    }
    reverse(ls.begin(), ls.end());
    for(auto x:ls) cout << x;
    if(ls.size() == 0) cout << 0;
    return; 
}
signed main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}