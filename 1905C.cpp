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
    string s; cin >> s;
    int j = n - 1;
    vector<int> v;
    for(int i = n - 1;i >= 0;i --){
        if(s[i] >= s[j]){
            v.push_back(i);
            j = i;
        }
    }
    int len = v.size(), m = 0;
    if(v.size()){
        int idx = 0;
        reverse(v.begin(), v.end());
        while(idx < v.size() && s[v[idx]] == s[v[0]]){
            m ++; idx ++;
        }
        len -= m;
        auto c = s;
        for(int j = len - 1;idx < v.size();idx ++, j --){
            c[v[j]] = s[v[idx]];
        }
        for(int i = len, j = 0;i < v.size();j ++, i ++){
            c[v[i]] = s[v[j]];
        }
        sort(s.begin(), s.end());
        if(s != c){
            cout << -1 << endl;
            return;
        }
    } 
    cout << len << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}