/*
 * @Author: JorD
 * @LastEditTime: 2022-09-30 23:18:40
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
    int n, k;
    cin >> n >> k;
    vector<ll> s(k + 1);
    rep(i, 1, k) cin >> s[i];
    if(n == 1||k == 1){
        cout << "YES" << endl;
        return;
    }
    vector<ll> a(n + 1);
    vector<bool> st(n + 1);
    for(int j = 1,i = n,jj = k;j < k;j ++, i --,jj --){
        a[i] = s[jj] - s[jj - 1];
        st[i] = true;
        if(i < n && a[i] > a[i + 1]){
            cout << "NO\n";
            return;
        }
    }
    if(n != k){
        if(a[n - k + 2] * (n - k + 1) < s[1]) cout << "NO\n";
        else cout << "YES\n";
    }else{
        if(s[1] > a[2]) cout << "NO\n";
        else cout << "YES\n";
    } 
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