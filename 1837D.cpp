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
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0, st = 0;
    for(auto x:s){
        if(x == '(') cnt ++; else cnt --;
    }
    if(cnt){
        cout << -1 << endl;
        return;
    }
    vector<int> v;
    vector<int> res(n);
    int siz = 0;
    for(int i = 0;i < n;i ++){
        if(v.empty() || s[v[0]] == s[i]){
            v.push_back(i);
        }else{
            int w = s[v[0]] == s[0]?1:2;
            res[v.back()] = w;
            res[i] = w;
            v.pop_back();
            siz = max(siz, w);
        }
    }
    cout << siz << endl;
    for(auto x:res) cout << x << ' ';
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