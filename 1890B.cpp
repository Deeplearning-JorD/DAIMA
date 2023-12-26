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
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    auto check = [](string &s){
        for(int i = 1;i < s.size();i ++){
            if(s[i] == s[i - 1]){
                return false;
            }
        }
        return true;
    };
    if(check(s)){
        cout << "Yes\n";
        return;
    }
    if(!check(t)){
        cout << "No\n";
        return;
    }
    auto l = t[0], r = t.back();
    for(int i = 1;i < n;i ++)if(s[i] == s[i - 1]){
        if(l == s[i - 1] || r == s[i]){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}