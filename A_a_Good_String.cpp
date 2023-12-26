/*
 * @Author: JorD
 * @LastEditTime: 2023-05-05 21:01:53
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    int l = 1, r = n;
    auto dfs = [&](auto self, int l, int r, char c) -> int{
        int cost1 = 0, cost2 = 0;
        int mid = l + r >> 1;
        for(int i = l;i <= r;i ++){
            if(s[i] != c){
                if(i <= mid) cost1 ++;
                else cost2 ++;
            }
        }
        if(l == r) return cost1;
        return min(cost1 + self(self, mid + 1, r, (char)((int)c + 1)),cost2 + self(self, l, mid, (char)((int)c + 1)));
    };
    cout << dfs(dfs, 1, n, 'a') << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}