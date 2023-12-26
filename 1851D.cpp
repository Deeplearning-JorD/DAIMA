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
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    set<ll> s;
    rep(i, 1, n) s.insert(i);
    bool ff = true;
    rep(i, 1, n - 1){
        cin >> a[i];
        if(a[i] - a[i - 1] > 2 * n - 1) ff = false;
        s.erase(a[i] - a[i - 1]);
    }
    if(!ff){
        cout << "NO\n";
        return;
    }
    if(s.size() == 1){
        cout << "YES\n";
        return;
    }
    if(s.size() > 2){
        cout << "NO\n";
        return;
    }
    if(s.size() == 2){
        ll sum = 0, cnt = 0;
        for(auto x:s) sum += x;
        rep(i, 1, n){
            if(sum == a[i] - a[i - 1]){
                cnt ++;
            }
        }
        if(sum > n && cnt == 1){
            cout << "YES\n";
            return;
        }else if(sum <= n && cnt == 2){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}