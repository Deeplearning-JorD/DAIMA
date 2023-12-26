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
    if(n < 5){
        cout << -1 << endl;
        return;
    }
    vector<int> a(n + 1);
    if(n < 10){
        for(int i = 1;i <= n;i += 2) cout << i << ' ';
        for(int i = 2;i <= n;i += 2) cout << i << ' ';
        return;
    }
    int id;
    for(int i = 1, j = n;j >= 1;j -= 2, i ++){
        a[i] = j;
        id = i;
    }
    for(int i = n, j = n - 1;j >= 1;j -= 2, i --){
        a[i] = j;
    }
    
    auto b = a;
    b[1] = a[n - 1];
    b[2] = a[n];
    b[n] = a[1];
    b[n - 1] = a[2];
    a = b;
    if(n & 1){
        b = a;
        b[id - 1] = a[id + 1]; 
        b[id] = a[id + 2];
        b[id + 1] = a[id];
        b[id + 2] = a[id - 1];
    }else{
        b = a;
        b[id - 1] = a[id + 2]; 
        b[id] = a[id + 1];
        b[id + 1] = a[id - 1];
        b[id + 2] = a[id];
    }
    rep(i, 1, n) cout << b[i] << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}