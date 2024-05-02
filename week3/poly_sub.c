#include <stdio.h>
#define MAX(a, b) ((a > b) ? a : b)
#define MAX_DEGREE 101

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

polynomial poly_add1(polynomial yA, polynomial yB) {
    polynomial y;  // 결과 다항식
    int y1Index = 0,  y2Index = 0, yIndex = 0;
    int degree_y1 = yA.degree;
    int degree_y2 = yB.degree;
    y.degree = MAX(degree_y1, degree_y2);
    while(y1Index <= yA.degree && y2Index <= yB.degree) {
        if(degree_y1 > degree_y2) {
            y.coef[yIndex++] = yA.coef[y1Index++];
            degree_y1--;
        }
        else if(degree_y1 == degree_y2) {
            y.coef[yIndex++] = yA.coef[y1Index++] - yB.coef[y2Index++];
            degree_y1--;
            degree_y2--;
        }
        else {
            y.coef[yIndex++] = yB.coef[y2Index++];
            degree_y2--;
        }
    }
    return y;
}
void print_poly(polynomial y) {

    printf("%3.1fx^%d", y.coef[0], y.degree);
    
    for(int i = y.degree-1 ; i > 0 ; i--) {
        if(y.coef[y.degree - i] >= 0.0)
            printf(" + %3.1fx^%d", y.coef[y.degree - i], i);
        else
            printf(" - %3.1fx^%d", y.coef[y.degree - i]*-1.0, i);
    }
    
    if(y.coef[y.degree] >= 0.0)
        printf(" + %3.1f \n", y.coef[y.degree]);
    else
        printf(" - %3.1f \n", y.coef[y.degree]*-1.0);
}
 int main(void)
 {
    polynomial yA = { 5,{ 3, 6, 0, 0, 0, 10 } };
    polynomial yB = { 4,{ 7, 0, 5, 0, 1 } };
    polynomial y;
    print_poly(yA);
    print_poly(yB);
    y = poly_add1(yA, yB);
    printf("-----------------------------------------------------------------------------\n");
    print_poly(y);
    return 0;
 }
