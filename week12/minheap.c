#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct Element {
    int key;
} Element;

typedef struct HeapType {
    Element *heap;
    int heap_size;
} HeapType;

void init(HeapType *h) {
    h->heap = (Element *)malloc(sizeof(Element) * MAX_ELEMENT);
    h->heap_size = 0;
}

void push_min_heap(HeapType *h, Element item) {
    int i = ++(h->heap_size);

    while((i != 1) && (item.key < h->heap[i/2].key)) {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

Element pop_min_heap(HeapType *h) {
    int parent, child;
    Element item, temp;

    item = h->heap[1]; // return할 key
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        // 왼쪽 자식과 비교
        if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
            child++; // 오른쪽 자식으로 이동
        if (temp.key <= h->heap[child].key)
            break;
        // break가 걸리지 않았다 -> 더 내려가야 한다
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int main() {
    Element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
    Element e4, e5, e6;
    HeapType* heap;
    init(heap);    // 초기화
    // 삽입
    push_min_heap(heap, e1);
    push_min_heap(heap, e2);
    push_min_heap(heap, e3);
    // 삭제
    e4 = pop_min_heap(heap);
    printf("< %d > ", e4.key);
    e5 = pop_min_heap(heap);
    printf("< %d > ", e5.key);
    e6 = pop_min_heap(heap);
    printf("< %d > \n", e6.key);

    free(heap);
}