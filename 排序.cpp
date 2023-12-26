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
    auto check = [&](char l, char r){
        return abs(l - r) == 1 || abs(l - r) == 9;
    };
    queue<char> q;
    vector<int> cnt(10);
    int sum = 1;
    q.push(s[0]);
    cnt[s[0] - '0'] ++;
    for(int i = 1;i < s.size();i ++){
        if(sum == 1){
            if(q.front() > s[i] && check(q.front(), s[i])){
                cout << s[i];
            }else{
                if(cnt[s[i] - '0'] == 0) sum ++;
                cnt[s[i] - '0'] ++;
                q.push(s[i]);
            }
        }else{
            if(cnt[s[i] - '0']){
                bool st = false;
                for(char j = '0';j <= '9';j ++)if(cnt[j - '0'] && j > s[i]){
                    st |= check(s[i], j);
                }
                if(st){
                    cout << s[i];
                    continue;
                }
                q.push(s[i]);
                cnt[s[i] - '0'] ++;
            }else{
                bool st = true;
                for(char j = '0';j <= '9';j ++)if(cnt[j - '0']){
                    st &= check(s[i], j);
                if(st){
                    while(q.size()){
                        auto t = q.front();
                        if(t > s[i]) break;
                        cout << t;
                        cnt[t - '0']  --;
                        if(cnt[t - '0'] == 0) sum --; 
                        q.pop();
                    }
                    cout << s[i];
                }else{
                    while(sum == 2){
                        auto t = q.front(); q.pop();
                        cnt[t - '0'] --;
                        cout << t;
                        if(cnt[t - '0'] == 0) sum --;
                    }
                    if(q.front() > s[i] && check(q.front(), s[i])){
                        cout << s[i];
                        continue;
                    }
                    cnt[s[i] - '0'] ++;
                    q.push(s[i]);
                    sum ++;
                }
            }
        }
    }
    while(q.size()){
        auto t = q.front(); q.pop();
        cout << t;
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