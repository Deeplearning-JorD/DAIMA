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
    vector<int> a(n + 1);
    priority_queue<int,vector<int>,greater<int>> q1, q2;
    rep(i, 1, n){
        cin >> a[i];
        if(a[i] & 1) q1.push(a[i]);
        else q2.push(a[i]);
    }
    int last = 0;
    for(int i = 1;i <= n;i ++){
        int now= -1;
        if(a[i] & 1){
            if(q1.size()){
                now = q1.top(); q1.pop();
            }
        }else{
            if(q2.size()){
                now = q2.top(); q2.pop();
            }
        }
        if(now < last){
            cout << "NO\n";
            return;
        }
        last = now;
    }
    cout << "YES\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}