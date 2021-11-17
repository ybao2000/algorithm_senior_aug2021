  add_outside();
  pq = priority_queue<iPair, vector<iPair>, greater<iPair>>();
  prim();
  int total_2 = 0;
  for(int i=0; i<=N; i++){
    total_2 += weights[i];
  }