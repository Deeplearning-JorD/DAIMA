/*
 * @Author: JorD
 * @LastEditTime: 2022-08-30 23:32:12
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
void Solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    ll need = 0;
    vector<ll> res;
    ll sum = 0;
    rep(i, 1, n){
        int w = 1;
        int l = i - 1, r = n - i;
        if(l == r) w = 0;
        if(l > r && s[i] == 'L') w = 0;
        if(l < r && s[i] == 'R') w = 0;
        if(w == 1){
            sum += min(l, r);
            res.push_back(max(l, r) - min(l, r));
        }else sum +=max(l, r);
        need += w; 
    
    }
    sort(res.begin(),res.end(),[](ll a, ll b){
        return a > b;
    });
    int idx = 0;
    // cout << need << endl;
    // cout << need << ' ' << sum << endl;
    // for(auto x:res) cout << x << " ";
    // cout << endl;
    rep(k, 1, n){
        if(idx < res.size())
        sum += res[idx ++]; 
        cout << sum << ' ';   
    } cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}