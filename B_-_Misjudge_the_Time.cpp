/*
 * @Author: JorD
 * @LastEditTime: 2022-11-19 20:14:14
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
vector<pair<int,int>> q;
void Solve(){
    int n, m;
    cin >> n >> m;
    for(auto [H, M]:q){
        if(H * 60 + M >= n * 60 + m){
            cout << H << ' ' << M << endl;
            return;
        }
    }
    for(auto [H, M]:q){
        cout << H << ' ' << M << endl;
        return;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    rep(h, 0, 23){
        rep(M, 0, 59){
            int A = h / 10;
            int B = h % 10;
            int C = M / 10;
            int D = M % 10;
            if(A * 10 + C <= 23 && A * 10 + C >= 0)
            if(B * 10 + D <= 59 && B * 10 + D >= 0)
            q.push_back({h, M});
        }
    }
    // sort(q.begin(), q.end(), [](pair<int,int>a,pair<int,int>b){
    //     return a.first * 60 + a.second < b.first * 60 + b.second;
    // });
    Solve();
    return 0;
}