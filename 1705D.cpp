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
void Solve(){
    int n;
    cin >> n;
    string s, ss;
    cin >> s >> ss;
    s = ' ' + s + '0';
    ss = ' ' + ss + '0';
    int idx = 0;
    int l = 0, r = 0;
    vector<pair<int,int>> a, b;
    rep(i, 1, n + 1){
        if(s[i] == s[i - 1]) continue;
        if(s[i] == '1'){
            l = i;
        }else if(s[i - 1] == '1'){
            r = i - 1;
            a.push_back({l, r});
        }
    }
    rep(i, 1, n + 1){
        if(ss[i] == ss[i - 1]) continue;
        if(ss[i] == '1'){
            l = i;
        }else if(ss[i - 1] == '1'){
            r = i - 1;
            b.push_back({l, r});
        }   
    }
    if(a.size() != b.size()){
        cout << -1 << endl;
        return;
    }
    if(a.empty()&&b.empty()){
        cout << 0 << endl;
        return;
    }
    bool st = false;
    if(a[0].first != b[0].first)
        if(b[0].first == 1||a[0].first == 1) st = true;
    if(a.back().second != b.back().second)
        if(b.back().second == n||a.back().second == n) st = true;
    if(st){
        cout << -1 << endl;
        return;
    }
    ll res = 0;
    while(idx < a.size()){
        auto L = a[idx], R = b[idx];
        res += abs(L.first - R.first) + abs(L.second - R.second);
        idx ++;
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}