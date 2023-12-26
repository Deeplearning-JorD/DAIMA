/*
 * @Author: JorD
 * @LastEditTime: 2022-08-13 22:50:31
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
    cin>>n;
    vector<int> res;
    for(int i=n;i>=1;i-=2){
        if(i<2) break;
        res.push_back(i-1);
        res.push_back(i);
    }
    if(n&1) res.push_back(1);
    reverse(res.begin(),res.end());
    for(auto x:res) cout<<x<<' ';
    cout<<endl;
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