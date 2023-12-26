/*
 * @Author: JorD
 * @LastEditTime: 2023-03-28 11:30:05
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
const int N = 5e4 + 10;
const pair<int,int> z = {0,0};
map<pair<int,int>,int> mp;
map<pair<int,int>,int> num;
struct node{
    int x, y, r;
};
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, n){
        int x, y, r;
        cin >> x >> y >> r;
        mp[{x, y}] = max(mp[{x, y}], r);
        num[{x, y}] ++;
    }
    int res = 0;
        queue<node> qq;
    while(m --){
        int a, b, c;
        cin >> a >> b >> c;
        qq.push({a, b, c});
    }
    while(qq.size()){
        int x = qq.front().x, y = qq.front().y, r = qq.front().r;
        qq.pop();
        for(int i = x - r;i <= x + r;i ++){
            for(int j = y - r;j <= y + r;j ++){
                if((i - x) * (i - x) + (j - y) * (j - y) <= r * r){
                    if(num[{i, j}]){
                        res += num[{i, j}];
                        qq.push({i, j, mp[{i, j}]});
                    }
                    num.erase({i,j});
                }
            }
        }
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}