/*
 * @Author: JorD
 * @LastEditTime: 2022-09-12 14:20:32
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
struct node{
    ll x, num, id;
};
void Solve(){
    int n;
    cin >> n;
    vector<string> s(n);
    vector<node> a(n);
    rep(i, 0, n - 1){
        cin >> s[i];
        ll cnt = 0, sum = 0;
        for(auto x:s[i]){
            if(x == 'X') cnt ++;
            else sum += x - '0';
        }
        a[i] = {cnt, sum, i};
    }
    sort(a.begin(), a.end(),[](node x, node y){
        return x.x * y.num > y.x * x.num;
    });
    ll res = 0;
    ll idx = 0;
    rep(i, 0, n - 1){
        for(auto x:s[a[i].id]){
            if(x == 'X') idx ++;
            else res += idx * (x - '0');
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}