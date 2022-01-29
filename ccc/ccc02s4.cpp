#include <bits/stdc++.h>
using namespace std;
// dp[i] is the shortest time it takes for all i peope to cross the bridge
typedef vector<string> group;
int M, Q;
pair<int, string> people[101];
int dp[101];
// you need a big array to store the group info
group path[101];

int main() {
  cin >> M;
  cin >> Q;
  for(int i=1; i<=Q; i++){
    string name;    
    int time;
    cin >> name;
    cin >> time;
    people[i] = {time, name};
  }
  // dp[i] = min(dp[i-1]+people[i].first, dp[i-2]+max(people[i].first, people[i-1].first), ...., dp[i-M]+max(....))
  // initialize dp first
  dp[0] = 0;
  path[0] = group{}; // empty group
  dp[1] = people[1].first;
  path[1] = group { people[1].second};
  for(int i=2; i<=Q; i++){
    dp[i] = dp[i-1] + people[i].first;  // initialize dp[i]
    int opt_j = i-1;
    for(int j=i-2; j>=max(i-M, 0); j--){
      int longest_time = 0;
      for(int k=j+1; k<=i; k++){
        longest_time = max(longest_time, people[k].first);
      }
      if(dp[j] + longest_time < dp[i]){
        dp[i] = dp[j] + longest_time;
        opt_j = j;
      }
    }
    // here you can update the path[i]
    string names = "";
    for(int k=opt_j+1; k<=i; k++){
      if(names.length() == 0) names = people[k].second;
      else names += " " + people[k].second;
    }
    path[i] = path[opt_j];    //groups for opt_j
    path[i].push_back(names); // add a new group
  }
  printf("Total Time: %d\n", dp[Q]);
  for(string names : path[Q]){
    cout << names << "\n";
  }
}
