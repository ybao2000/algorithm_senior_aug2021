#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int SIZE = 1e6;
const int INF = 1e9;
int n;
int dist[SIZE];

int hash_st(vi &state) {
    int pw=1, res = 0;
    for(int i=0; i<n; i++){
        res += state[i] * pw;
        pw *= n;
    }
    return res;
}

int main() {
    while(true){
        fill(dist, dist+SIZE, INF);
        cin >> n;
        if(n == 0) break;
        vi st(n), final_st(n);
        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            st[a-1] = i;
            final_st[i] = i;
        }
        dist[hash_st(st)] = 0;
        queue<vi> q;
        q.push(st);
        while(!q.empty()){
            vi curr = q.front();
            q.pop();
            int d = dist[hash_st(curr)];
            vi onTop(n, -1); // the top # at each position
            for(int i=n-1; i>=0; i--) onTop[curr[i]] = i;
            for(int i=0; i<n; i++) {
                if(onTop[i] != -1) {
                    if(i>0 && (onTop[i-1] == -1 || onTop[i] < onTop[i-1])) { 
                        // move to left
                        vi new_st = curr;
                        new_st[onTop[i]] = i-1;
                        int h = hash_st(new_st);
                        if(d+1 < dist[h]) {
                            dist[h] = d + 1;
                            q.push(new_st);
                        }
                    }
                    if(i < n-1 && (onTop[i+1] == -1 || onTop[i] < onTop[i+1])) {
                        // move to right
                        vi new_st = curr;
                        new_st[onTop[i]] = i+1;
                        int h = hash_st(new_st);
                        if(d+1 < dist[h]) {
                            dist[h] = d + 1;
                            q.push(new_st);
                        }
                    }                    
                }
            }
        }
        if(dist[hash_st(final_st)] != INF) {
            cout << dist[hash_st(final_st)] << "\n";
        }
        else {
            cout << "IMPOSSIBLE\n";
        }
    }
}