/*
 * @Author: JorD
 * @LastEditTime: 2023-02-01 18:03:39
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
    ll n, k;
    cin >> n >> k;
    ll kk = k;
    string s;
    cin >> s;
    if(n - 1 <= k){
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        cout << s << endl;
        return;
    }
    auto mb = s;
    sort(mb.begin(), mb.end());
    reverse(mb.begin(), mb.end());
    int idx = 0;
    vector<char> l, r, ls;
    int last = -1, ne = 0;
    for(int i = 0;i < s.size();i ++){
        if(s[i] == mb[idx]){
            if(siz(ls) + siz(r) > k) break;
            idx ++;
            l.push_back(s[i]);
            for(auto x:ls) r.push_back(x);
            last = i;
            ls.clear();
            continue;
        }
        ls.push_back(s[i]);
    }
    ne = last;
    k -= siz(r);
    priority_queue<char> q;
    int cnt = siz(s);
    for(int i = last + 1, j = 1;(i < siz(s)) && (j <= k + 1);i ++, j ++){
        q.push(s[i]);
        cnt = i;
    }
    cnt ++;
    ls.clear();
    for(int i = last + 1;i < siz(s);i ++){
        if(siz(s) - i <= kk - siz(ls) - siz(r)){
            // cout << i << ' ' << siz(r) << endl;
            // cout << siz(s) - i << ' ' << kk - siz(ls) - siz(r) << endl;
            for(auto x:ls) r.push_back(x);
            ls.clear();
            r.push_back(s[i]);
            ne = i;
            continue;
        }
        if(s[i] == q.top()){
            if(siz(ls) + siz(r) > kk) break;
            q.pop();
            if(cnt < siz(s)){
                q.push(s[cnt]);
                cnt ++;
            }
            l.push_back(s[i]);
            for(auto x:ls) r.push_back(x);
            ls.clear();
            ne = i;
            continue;
        }
        ls.push_back(s[i]);
    }
    sort(r.begin(), r.end());
    reverse(r.begin(), r.end());
    for(auto x:l) cout << x;
    for(int i = ne + 1;i < siz(s);i ++) cout << s[i];
    for(auto x:r) cout << x;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}