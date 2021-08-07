#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 1; tc <= t; ++tc) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        long long result = 0;
        for(int i = 1; i <= a; ++i) {
            for(int j = 1; j <= b; ++j) {
                for(int k = 1; k <= c; ++k) {
                    result += j * k;
                }
            }
        }
        printf("Case %d: %lld\n", tc, result);
    }
    return 0;
}