#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);

    int n;
    int max;
    int min;
    for(int i = 0 ; i < t ; i++) {
        scanf("%d", &n);
        int* stack = (int*)malloc(sizeof(int) * n);
        int stackIndex = 0;
        int* maxList = (int*)malloc(sizeof(int) * n);
        int maxIndex = 0;
        int* minList = (int*)malloc(sizeof(int) * n);
        int minIndex = 0;
        int next;
        int max = 0;    // max가 0이면 maxList에 아무것도 없다는 뜻
        int min = 0;    // min이 0이면 minList에 아무것도 없다는 뜻
        for(int j = 0 ; j < n ; j++) {
            scanf("%d", &next);
            if(next == 1) {
                scanf("%d", &next);
                if(max == 0 && min == 0) {
                    max = next;
                    min = next;
                    maxList[maxIndex++] = next;
                    minList[minIndex++] = next;
                }
                else {
                    if(next > max) {
                        max = next;
                        maxList[maxIndex++] = next;
                    }
                    if(next < min) {
                        min = next;
                        minList[minIndex++] = next;
                    }
                }
                stack[stackIndex++] = next;
                printf("%d %d\n", min, max);
            }
            else if(next == 2) {
                if(maxIndex == 0) {
                    NULL;
                }
                else {
                    if(stack[stackIndex - 1] == maxList[maxIndex - 1]) {
                        maxIndex--;
                        if(maxIndex == 0) {
                            max = 0;
                        }
                        else {
                            max = maxList[maxIndex - 1];
                        }
                    }
                    if(stack[stackIndex - 1] == minList[minIndex - 1]) {
                        minIndex--;
                        if(minIndex == 0) {
                            min = 0;
                        }
                        else {
                            min = minList[minIndex - 1];
                        }
                    }
                    stackIndex--;
                }
            }
        }
        free(stack);
        free(maxList);
        free(minList);
    }
}