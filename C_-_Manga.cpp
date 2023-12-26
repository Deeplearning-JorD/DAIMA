/*
 * @Author: JorD
 * @LastEditTime: 2022-10-01 20:57:07
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
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    sort(a.begin(), a.end());
    int res = 0;
    int js = 0;
    int l = 1, r = 0;
    vector<int> b(n + 1);
    rep(i, 1, n){
        if(a[i] == a[i - 1]) js ++;
        else b[++ r] = a[i];
    }
    int idx = r;
    int i = 1;
    while(l <= idx){
        if(b[l] != i){
            if(js >= 2){
                js -= 2;
                res ++;
            } 
            else{
                js += 1;
                idx --;    
                continue;            
            }
        }
        else{
            l ++;
            res ++;
        }
        i ++;
    }
    cout << res + js/2;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;


    Solve();
    return 0;
}