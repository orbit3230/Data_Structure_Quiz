#include <stdio.h>

typedef struct {
    int valueA;
    int valueB;
    int valueSum;
} Resource;

int findMaxValue(Resource *resources, int n) {
    int maxValue = 0;
    int maxIndex = 0;
    for(int i = 0 ; i < n ; i++) {
        if(resources[i].valueSum > maxValue) {
            maxValue = resources[i].valueSum;
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    int t;
    scanf("%d", &t);

    for(int i = 0 ; i < t ; i++) {
        int n;
        scanf("%d", &n);
        Resource *resources = (Resource*)malloc(sizeof(Resource) * n);
        for(int j = 0 ; j < n ; j++) {
            int x, y;  // x : value of A country, y : value of B country
            scanf("%d %d", &x, &y);
            resources[j].valueA = x;
            resources[j].valueB = y;
            resources[j].valueSum = x + y;
        }
        int isA_turn = 1;  // 1이면 A턴, 0이면 B턴
        int A_valueSum = 0;
        int B_valueSum = 0;
        for(int j = 0 ; j < n ; j++) {
            int maxIndex = findMaxValue(resources, n);
            if(isA_turn) {
                A_valueSum += resources[maxIndex].valueA;
                isA_turn = 0;
            }
            else {
                B_valueSum += resources[maxIndex].valueB;
                isA_turn = 1;
            }
            // 자원을 사용했으므로 초기화
            resources[maxIndex].valueA = 0;
            resources[maxIndex].valueB = 0;
            resources[maxIndex].valueSum = 0;
        }
        printf("%d\n", A_valueSum - B_valueSum);
    }
}