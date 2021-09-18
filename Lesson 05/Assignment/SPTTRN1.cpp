#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int it=0; it<t; it++){
        int n;
        cin >> n;
        char patterns[n][n];
        // initialize the patterns
        for(int ir=0; ir<n; ir++){
            for(int ic=0; ic<n; ic++){
                patterns[ir][ic] = '.';
            }
        }
        int top = 0;
        int bottom = n-1;
        int left = -2;
        int right = n-1;
        int row = top;
        int col = left;
        while (true){
            // right
            for(int ic=col; ic<=right; ic++){
                patterns[row][ic] = '*';
            }
            col = right;
            left += 2;
            if (col < left) break;

            // down
            for(int ir=row; ir<=bottom; ir++){
                patterns[ir][col] = '*';                
            }
            row = bottom;
            top += 2;
            if(row < top) break;

            // left
            for(int ic=col; ic>=left; ic--){
                patterns[row][ic] = '*';
            }
            col = left;
            right -= 2;
            if(col > right) break;

            // up
            for(int ir=row; ir>=top; ir--){
                patterns[ir][col] = '*';
            }
            row = top;
            bottom -= 2;
            if(row > bottom) break;
        }
        for(int ir=0; ir<n; ir++){
            for(int ic=0; ic<n; ic++){
                cout << patterns[ir][ic];
            }
            cout << endl;
        }
    }
}