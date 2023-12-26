/*
 * @Author: JorD
 * @LastEditTime: 2022-12-05 21:57:39
 */
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
char res[N];
int main(){
    cout << "? abcdefghijklmnopqrstuvwxyz" << endl;
    int all; cin >> all;
    for(int i = 1, j;i <= all;i ++) cin >> j; 
    vector<vector<int>> st(27, vector<int> (5));
    for(int i = 1;i <= 26;i ++){
        int x = i, idx = 0;
        while(x){
            st[i][idx] = x & 1;
            x >>= 1;
            idx ++;
        }
    }
    vector<vector<char>> query(5);
    for(int j = 0;j < 5;j ++){
        for(int i = 1;i <= 26;i ++){
            if(st[i][j]) query[j].push_back('a' + i - 1);
        }
    }
    vector<set<int>> pos(5);
    for(int j = 0;j < 5;j ++){
        cout << "? ";
        for(auto c:query[j]) cout << c;
        cout << endl;
        int n;
        cin >> n;
        set<int> s;
        for(int i = 1;i <= n;i ++){
            int x; cin >> x;
            s.insert(x);
        }
        pos[j] = s;
    }
    for(int i = 1;i <= 26;i ++){
        vector<int> v;
        for(int j = 0;j < 5;j ++){
            if(st[i][j]) v.push_back(j);
        }
        int cnt = v.size();
        map<int,int> q;
        for(auto x:v){
            for(auto s:pos[x]){
                q[s] ++;
            }
        }
        for(auto [x, y]:q){
            if(y == cnt){
                res[x] = (char)('a' + i - 1);
            }
        }
    }
    cout << "! ";
    for(int i = 1;i <= all;i ++) cout << res[i];
    return 0;
}