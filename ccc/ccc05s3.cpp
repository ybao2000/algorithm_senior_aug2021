#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
int N;
int m, n, p, q;

int a[1024][1024], b[1024][1024], c[1024][1024];

void tensor_product() {
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<p; k++){
        for(int l=0; l<q; l++){
          c[i*p+k][j*q+l] = a[i][j] * b[k][l];
        }
      }
    }
  }
  m *= p;
  n *= q;
  memcpy(a, c, sizeof(a));
}

int main() {
  cin >> N;
  cin >> m >> n;
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      cin >> a[i][j];
    }
  }
  for(int k=1; k<N; k++){
    cin >> p >> q;
    for(int i=0; i<p; i++){
      for(int j=0; j<q; j++){
        cin >> b[i][j];
      }
    }
    tensor_product();
  }
  int max_elem, min_elem, max_row_sum, min_row_sum, max_col_sum, min_col_sum;
  max_elem = max_row_sum = max_col_sum = -INF;
  min_elem = min_row_sum = min_col_sum = INF;
  for(int i=0; i<m; i++){
    int row_sum = 0;
    for(int j=0; j<n; j++){
      max_elem = max(max_elem, a[i][j]);
      min_elem = min(min_elem, a[i][j]);
      row_sum += a[i][j];
    }
    max_row_sum = max(max_row_sum, row_sum);
    min_row_sum = min(min_row_sum, row_sum);
  }
  for(int i=0; i<n; i++){
    int col_sum =0; 
    for(int j=0; j<m; j++){
      col_sum += a[j][i];
    }
    max_col_sum = max(max_col_sum, col_sum);
    min_col_sum = min(min_col_sum, col_sum);
  }
  cout << max_elem << "\n";
  cout << min_elem << "\n";
  cout << max_row_sum << "\n";
  cout << min_row_sum << "\n";
  cout << max_col_sum << "\n";
  cout << min_col_sum << "\n";
}