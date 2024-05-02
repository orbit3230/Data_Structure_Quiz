#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;
// 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}
// 맨 앞에 노드 삽입
ListNode* insert_first(ListNode* head, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}
// 노드 삭제
ListNode* remove_e(ListNode* head, ListNode* pre) {
    ListNode* removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}
// 맨 앞의 노드 삭제
ListNode* remove_first(ListNode* head) {
    ListNode* removed;
    if(head == NULL)
        return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}
// linked list 출력
void print_list(ListNode* head) {
    for(ListNode* p = head ; p != NULL ; p = p->link)
        printf("%d->", p->data);
    printf("NULL \n");
}

ListNode* reverse(ListNode* head) {
    ListNode* reversed;
    reversed = NULL;
    while(head != NULL) {
        reversed = insert_first(reversed, head->data);
        head = head->link;
    }
    return reversed;
}

int main() {
    ListNode* head = NULL;
    for (int i = 1; i <= 3; i++)
        head = insert_first(head, i*10);
    print_list(head);
    print_list(reverse(head));
    return 0;
}