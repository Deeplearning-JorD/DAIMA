/*
 * @Author: JorD
 * @LastEditTime: 2023-03-30 19:01:00
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
    map<string, vector<string>> q;
    cin >> n;
    rep(i, 1, n){
        string a, b;
        cin >> a >> b;
        q[a].push_back(b);
    }
    for(auto &[now, v]:q){
        set<string> s;
        map<string,int> st;
        for(int i = 0;i < v.size();i ++){
            s.insert(v[i]);
            st[v[i]] ++;
            if(s.size() == 5){
                cout << "PENTA KILL!\n";
                return;
            }
            if(i >= 4){
                st[v[i - 4]] --;
                if(!st[v[i - 4]])
                s.erase(v[i - 4]);
            }
        }
    }
    cout << "SAD:(\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}