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
    string s;
    cin >> s;
    map<char,int> q;
    for(auto x:s) q[x] ++;
    vector<int> a(4);
    for(auto [x, y]:q){
        a[0] ++;
        if(y == 2) a[1] ++;
        if(y == 3) a[2] ++;
        if(y == 4) a[3] ++;
    }
    if(a[3]) cout << -1 << endl;
    else if(a[2]) cout << 6 << endl;
    else if(a[1]||a[0] == 4) cout << 4 << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}
