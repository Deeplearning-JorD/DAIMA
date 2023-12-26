#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
void Solve(){
    int n; cin >> n;
    vector<int> d1, d2, res;
    int sum = 0;
    rep(i, 1, n){
        int x; cin >> x;
        if(x % 3 == 0) res.push_back(x);
        else if(x % 3 == 1) d1.push_back(x);
        else d2.push_back(x);
        sum += x;
        sum %= 3;
    }
    sort(d1.rbegin(), d1.rend());
    sort(d2.rbegin(), d2.rend());
    if(sum % 3 == 1){
        if(d1.size()){
            d1.pop_back();
        }else if(d2.size() >= 2){
            d2.pop_back();
            d2.pop_back();
        }
        for(auto x:d1) res.push_back(x);
        for(auto x:d2) res.push_back(x);
    }else if(sum % 3 == 2){
        if(d2.size()){
            d2.pop_back();
        }else if(d1.size() >= 2){
            d1.pop_back();
            d1.pop_back();
        }
        for(auto x:d1) res.push_back(x);
        for(auto x:d2) res.push_back(x);
    }else{
        for(auto x:d1) res.push_back(x);
        for(auto x:d2) res.push_back(x);
    }
    sort(res.rbegin(), res.rend());
    if(res.empty()) cout << -1;
    else{
        if(res[0] == 0) cout << 0;
        else for(auto x:res) cout << x;
    }
    cout << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}