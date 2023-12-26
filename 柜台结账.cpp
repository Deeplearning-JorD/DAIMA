#pragma GCC optimize(2)
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
    string s; cin >> s;
    int a = s.back() & 1;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    bool st = false;
    for(int i = 2;i <= n;i ++) if(s[i] != '0') st = true;
    if(s[1] == '5' && st || (s[1] > '5')){
        cout << "Happy birthday to MFGG";
    }else if(s[1] == '5' && !st){
        if(a) cout << "Happy birthday to MFGG";
        else cout << "Happy birthday to YXGG";
    }else{
        if(s[1] != '0') st = true;
        if(st){
            cout << "Happy birthday to YXGG";
        }else cout << "PLMM";
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --
    Solve();
    return 0;
}