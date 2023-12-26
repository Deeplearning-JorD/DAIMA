/*
 * @Author: JorD
 * @LastEditTime: 2022-11-30 02:03:34
 */
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
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    s = ' ' + s + '0';
    int pre = 0;
    int id = 0;
    string res = "";
    int last;
    vector<vector<int>> cnt(10, vector<int> (n + 2));
    per(i, n, 1){
        int c = s[i] - '0';
        rep(j, 0, 9) 
        cnt[j][i] = cnt[j][i + 1] + (j == c);
    }
    while(k&&last != n){
        last = 0;
        int zero = pre == 0;
        rep(mi, zero, 9){
            last = 0;
            if(!cnt[mi][pre + 1]) continue;
            rep(i, pre + 1, min(pre + 1 + k, n)){
                if(s[i] - '0' != mi) continue;
                if(k >= i - pre - 1){
                    last = i;
                    break;
                }
            }
            if(last){
                k -= last - pre - 1;
                pre = last;
                res += s[last];
                id = last;
                break;
            }
        }
    }
    rep(i, 0, siz(res) - k - 1)
    cout << res[i];
    rep(i, id + 1, n) cout << s[i];
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