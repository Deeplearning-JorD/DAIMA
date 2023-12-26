/*
 * @Author: JorD
 * @LastEditTime: 2022-10-17 23:06:07
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
    ll res = 0;
    vector<int> a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
    }
    int idx = n + 1;
    rep(i, 1, n){
        if(s[i] == '0'){
            idx = i;
            break;
        }else res += a[i];
    }
    s += '0';
    int last = idx;
    int r = idx;
    while(last < n){
        priq<int> q;
        q.push(a[last]);
        rep(j, last + 1, n + 1){
            if(s[j] == '0'){
                r = j;
                break;
            }else{
                q.push(a[j]);
            }
        }
        if(r == last){
            break;
        }
        rep(j, 1, r - last - 1){
            res += q.top(); q.pop();
        }
        // cout << last << ' ' << r << endl; 
        // cout << res << endl;
        last = r;
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