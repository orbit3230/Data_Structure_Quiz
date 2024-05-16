#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    int n, m;  // n: # of candies, m: want to get [sum of length of candies]
    for(int i = 0 ; i < t ; i++) {
        scanf("%d %d", &n, &m);
        int candy[n];
        int maxLength = 0;  // the longest candy length
        for(int j = 0 ; j < n ; j++) {
            scanf("%d", &candy[j]);
            if(candy[j] > maxLength) {
                maxLength = candy[j];
            }
        }

        int sum;  // sum of the candy length we can get by cutting
        int cuttingSize = maxLength;  // the size of cutting
        while(1) {
            sum = 0;
            for(int j = 0 ; j < n ; j++) {
                // if candy is shorter than cutter, it won't be cut
                sum += (candy[j] - cuttingSize > 0) ? candy[j] - cuttingSize : 0;
            }
            if(sum >= m) {
                break;
            }
            cuttingSize--;
        }

        printf("%d\n", cuttingSize);
    }
}