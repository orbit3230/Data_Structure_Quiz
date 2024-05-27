#include <stdio.h>

typedef struct {
    int time;
    int cost;
} Customer;

int fastCashier(Customer *cashiers, int n) {
    int min = 0;
    for(int i = 0 ; i < n ; i++) {
        if(cashiers[i].time < cashiers[min].time) {
            min = i;
        }
    }
    return min;
}

int main() {
    int n, m;  // n : # of cashiers, m : # of customers
    scanf("%d %d", &n, &m);
    Customer *cashiers = (Customer*)malloc(sizeof(Customer) * n);
    for(int i = 0 ; i < n ; i++) {
        cashiers[i].time = 0;
        cashiers[i].cost = 0;
    }
    for(int i = 0 ; i < m ; i++) {
        Customer *customer = (Customer*)malloc(sizeof(Customer));
        scanf("%d %d", &customer->time, &customer->cost);
        int index = fastCashier(cashiers, n);
        cashiers[index].time += customer->time;
        cashiers[index].cost += customer->cost;
    }

    int totalTime = 0;
    for(int i = 0 ; i < n ; i++) {
        if(totalTime < cashiers[i].time) {
            totalTime = cashiers[i].time;
        }
    }
    printf("%d\n", totalTime);
    for(int i = 0 ; i < n ; i++) {
        printf("%d\n", cashiers[i].cost);
    }
}