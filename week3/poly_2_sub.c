#include <stdio.h>
#define MAX_TERMS 101

typedef struct {
    float coef;
    int expo;
} polynomial;

polynomial yA[MAX_TERMS] = {{8, 3}, {7, 1}, {1, 0}};
polynomial yB[MAX_TERMS] = {{10, 3}, {3, 2}, {1, 0}};
polynomial y_[MAX_TERMS];  // 결과 다항식
int y1Index = 0;
int y2Index = 0;
int y_Index = 0;

void attach(float coef, int expo) {
    y_[y_Index].coef = coef;
    y_[y_Index].expo = expo;
    y_Index++;
}
void poly_add2() {
    
    int expo_y1;
    int expo_y2;
    while(y1Index <= 2 && y2Index <= 2) {
        expo_y1 = yA[y1Index].expo;
        expo_y2 = yB[y2Index].expo;
        if(expo_y1 > expo_y2) {
            attach(yA[y1Index].coef, expo_y1);
            y1Index++;
        }
        else if(expo_y1 == expo_y2) {
            float temp = yA[y1Index].coef - yB[y2Index].coef;
            if(temp != 0.0)
                attach(temp, expo_y1);
            y1Index++;
            y2Index++;
        }
        else {
            attach(yB[y2Index].coef * -1.0, expo_y2);
            y2Index++;
        }
    }
}
void print_poly(polynomial y[], int index) {
    int i;
    for(i = 0 ; i < index ; i++) {
        if(i == 0) {
            printf("%3.1fx^%d", y[i].coef, y[i].expo);
        }
        else {
            if(y[i].coef >= 0.0)
                printf(" + %3.1fx^%d", y[i].coef, y[i].expo);
            else
                printf(" - %3.1fx^%d", y[i].coef*-1.0, y[i].expo);
        }
    }
    printf("\n");
}
int main(void) 
{
    poly_add2();
    print_poly(yA, y1Index);
    print_poly(yB, y2Index);
    printf("-----------------------------------------------------------------------------\n");
    print_poly(y_, y_Index);
    return 0;
}
