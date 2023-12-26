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
    ll n, k;
    cin >> n >> k;
    string s; cin >> s;
    if(n == 1){
        if(k & 1) cout << 0 << endl;
        else cout << 1 << endl;
        return;
    }
    if(k == 1 && s == string(n, '1')){
        s[n - 1] = '0';
        cout << s << endl;
        return;
    }
    s = " " + s + "1";
    int cnt = 0;
    int len = 0, id = 0;
    for(int i = 1;i <= n + 1;i ++){
        if(s[i] == s[i - 1]){
            if(s[i] == '1') continue;
            len ++;
        }else{
            if(s[i] == '1'){
                if(len > 0){
                    cnt ++;
                    if(cnt <= k) id = i;
                }
                len = 0;
            }else{
                len = 1;
            }
        }
    }
    if(cnt <= k){
        rep(i, 1, n) cout << 1;
        cout << endl;
    }else{
        rep(i, 1, n){
            if(i < id) cout << 1;
            else cout << s[i];
        }
        cout << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}