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
string judge(string s, string s1){
    if(s > s1) return s;
    return s1;
}
string check(string s, string s1){
    string ss = s;
    reverse(ss.begin(), ss.end());
    s = judge(s, ss);
    ss = s1;
    reverse(ss.begin(), ss.end());
    s1 = judge(s1, ss);
    if(s < s1) return s;
    return s1;
}
void Solve(){
    string s;
    cin >> s;
    int n = s.size();
    string L = s, R = s;
    int l = 0, r = n - 1;
    sort(s.begin(), s.end());
    int flag = 0;
    s += '0';
    char c;
    int idx = 0;
    for(int i = 0;i < n;i += 2){
        if(s[idx] == s[idx + 1] && !flag){
            L[l ++] = s[idx];
            L[r --] = s[idx];
            idx += 2;
        }else if(!flag){
            R = L;
            R[l] = s[idx + 1];
            R[r] = s[idx];
            for(int j = l + 1, k = idx + 2;j < r;j ++, k ++){
                R[j] = s[k];
            }
            flag = 1;
            if(i + 2 >= n){
                L[l] = s[idx + 1];
                L[r] = s[idx];
                flag = 2;
                break;
            }else{
                c = s[i];
                L[l ++] = s[idx + 2];
                L[r --] = s[idx + 1];
                idx += 3;
            }
        }else{
            if(s[idx] == s[idx + 1]){
                L[l ++] = s[idx + 1];
                L[r --] = s[idx]; 
                idx += 2;
            }else{
                L[l] = s[idx];
                L[r] = c;
                for(int j = l + 1, k = idx + 1;j < r;j ++, k ++){
                    L[j] = s[k];
                }
                flag = 2;
                break;
            }
        }
    }
    if(n & 1){
        if(flag == 1){
            L[n / 2] = c;
        }else if(flag == 0) L[n / 2] = s[n - 1];
    }
    cout << check(L, R) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}