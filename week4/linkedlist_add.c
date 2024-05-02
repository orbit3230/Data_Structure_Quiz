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

// linked list 연결
ListNode* concat_list(ListNode* head1, ListNode* head2) {
    if(head1 == NULL)
        return head2;
    else if(head2 == NULL)
        return head1;
    else {
        // newHead는 head1과 같은 주소를 가리킨다.
        ListNode* newHead = head1;
        while(newHead->link != NULL) {
            newHead = newHead->link;
        }
        newHead->link = head2;

        return head1;
    }
}

int main() {
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;
    for (int i = 1; i <= 3; i++)
        head1 = insert_first(head1, i*10);
    print_list(head1);
    for (int i = 5; i >= 4 ; i--)
        head2 = insert_first(head2, i*10);
    print_list(head2);
    print_list(concat_list(head1, head2));
    return 0;
}