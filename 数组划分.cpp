/*
 * @Author: JorD
 * @LastEditTime: 2022-11-25 20:17:03
 */
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
    int n;
    cin >> n;
    map<int,int> q;
    auto prime = [&](int x){
        for(int i = 2;i <= x / i;i ++){
            if(x % i == 0){
                q[i] ++;
                while(x % i == 0) x /= i;
            }
        }
        if(x > 1) q[x] ++;
    };
    rep(i, 1, n){
        int x; cin >> x;
        prime(x);
    }
    rep(i, 1, n){
        int x; cin >> x;
        for(int j = 2;j <= x / j;j ++){
            if(x % j == 0){
                if(q[j]){
                    cout << "No";
                    return;
                }
                while(x % j == 0) x /= j;
            }
        }
        if(x > 1&&q[x]){
            cout << "No";
            return;
        }
    }
    cout << "Yes\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    
    Solve();
    return 0;
}