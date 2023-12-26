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
    int n = s.size();
    s = '0' + s;
    int last = n + 1;
    for(int i = 1;i <= n;i ++){
        if(s[i] < '5') continue;
        for(int j = i;j >= 1;j --){
            if(s[j] > '9') s[i] = '0';
            if(s[j] >= '5'){
                last = j;
                s[j - 1] ++;
            }else break;
        }
        break;
    }
    if(s[0] == '0'){
        for(int i = 1;i <= n;i ++){
            if(i >= last) cout << 0;
            else cout << s[i];
        }
    }else{
        for(int i = 0;i <= n;i ++){
            if(i >= last) cout << 0;
            else cout << s[i];
        }
    }
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}