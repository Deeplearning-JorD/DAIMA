/*
 * @Author: JorD
 * @LastEditTime: 2023-08-08 14:34:45
 * how to Get
 */
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
const int N = 50;
int tr[N];
int lowbit(int x){return x & -x;}
void add(int i, int x){
    for(;i<=26;i += lowbit(i)) tr[i] += x;
}
int sum(int i){
    int res = 0;
    for(;i;i-=lowbit(i)) res += tr[i];
    return res;
}
void Solve(){
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> son(26);
    rep(i, 1, 26) tr[i] = 0;
    set<char> st;
    for(int i = 0;i < n;i ++){
        st.insert(s[i]);
        son[s[i]-'a'].push_back(i);
    }
    for(int i = 0;i < 26;i ++)if(!son[i].empty()){
        if(son[i].back() - son[i][0] + 1 == siz(son[i]) || siz(son[i]) == 1) continue;
        for(int j = 0;j < siz(son[i]);j ++) cout << (char)('a'+i);
        cout << endl;
        return;
    }
    if(st.size() > 2){
        vector<char> ls;
        vector<pair<int,int>> res;
        for(auto x:s){
            if(ls.empty() || x != ls.back())
            ls.push_back(x);
        }
        vector<int> cnt(27);
        int m = ls.size(), k = 26;
        for(int i = m - 1;i >= 0;i --){
            for(int j = 0;j < 26;j ++){
                if(cnt[j]){
                    res.push_back({ls[i] - 'a', j});
                }
            }
            cnt[k] ++;
            k = ls[i] - 'a';
        }
        if(res.size()){
            sort(res.begin(), res.end());
            cout << (char)(res[0].first + 'a') << (char)(res[0].second + 'a') << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}