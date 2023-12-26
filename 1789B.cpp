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
    string s;
    cin >> s;
    s = ' ' + s;
    int l = 1, r = n;
    vector<int> st(n / 2 + 1);
    for(int i = 1;i <= n / 2;i ++, l ++, r --){
        st[i] = s[l] != s[r];
    }
    int flag = 0;
    for(int i = 1;i <= n / 2;i ++){
        if(st[i] && !flag){
            flag = 1;
        }else if(st[i] && flag == 1) continue;
        else if(!st[i] && flag){
            flag = 2;
        }else if(st[i] && flag == 2){
            cout << "NO\n";
            return;
        }
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