#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
int n;
void Solve(){
    // int n; cin >> n;
    int x = n - 2;
    cout << x << ' ';
    for(int i = 1;i < n;i ++){
        if(i & 1) x += 2;
        else x -= 3;
        cout << x << ' ';
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    for(int i = 5;i <= 10;i ++){n=i;
    Solve();cout<<endl;}
    return 0;
}