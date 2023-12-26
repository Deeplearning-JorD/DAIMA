/*
 * @Author: JorD
 * @LastEditTime: 2022-09-13 18:36:04
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
    string s;
    cin >> n;
    cin >> s;
    string res = "";
    vector<bool> st(n);
    vector<char> c;
    int m = 'a' - 1;
    vector<int> id(n);
    per(i, n - 1, 0){
        if(st[i]) continue;
        if(s[i] == '0'){
            if(i - 2 >= 0&&!st[i - 1]&&!st[i - 2]){
                int w = s[i - 2] - '0';
                w = w * 10 + s[i - 1] - '0';
                // cout << w <<endl;
                c.push_back((char)(m + w));
                // cout << c.back() << endl 
                id[i] = 1;
                st[i - 1] = st[i - 2] = st[i] = true;
            }
        }
    }
    reverse(c.begin(), c.end());
    int idx = 0;
    rep(i, 0, n - 1){
        if(st[i] && id[i])res += c[idx++];
        else{
            if(st[i]) continue;
            res += (char)(m + s[i] - '0');
        } 
        // cout << res << endl;
    }
    cout << res << endl;
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