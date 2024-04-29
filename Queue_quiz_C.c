// 202110155 Kim Seong Hyeon

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

#define WORD_SIZE 101
typedef char* element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int  front, rear;
} QueueType;


void error(const char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front % MAX_QUEUE_SIZE);
}


void queue_print(QueueType* q) {
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType* q, element item) {
    if (is_full(q))
        error("Queue is full");
    q->data[(q->rear + 1) % MAX_QUEUE_SIZE] = (char*)malloc(WORD_SIZE * sizeof(char));  // �߰���
    strcpy(q->data[(q->rear + 1) % MAX_QUEUE_SIZE], item);  
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

element dequeue(QueueType* q) {
    if (is_empty(q))
        error("Queue is empty");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    element item = q->data[q->front];
    return item;
}

element get_front(QueueType* q) {
    if (is_empty(q))
        error("Queue is empty");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

element get_rear(QueueType* q) {
    if (is_empty(q))
        error("Queue is empty");
    return q->data[q->rear];
}


int main() {
    int problem_num, student_num, word_num = 0;
    scanf("%d", &problem_num);

    for (int problem = 0; problem < problem_num; problem++) {
        scanf("%d %d", &student_num, &word_num);

        char** sentence = (char**)malloc(word_num * sizeof(char*));
        for (int word = 0; word < word_num; word++) {
            sentence[word] = (char*)malloc(WORD_SIZE * sizeof(char));
            scanf("%s", sentence[word]);
        }

        QueueType* queue_array = (QueueType*)malloc(student_num * sizeof(QueueType));
        for (int student = 0; student < student_num; student++) {
            init_queue(&queue_array[student]);  // Initialize each queue
            int input_num;
            scanf("%d", &input_num);
            for (int input = 0; input < input_num; input++) {
                char word[WORD_SIZE];
                scanf("%s", word);
                enqueue(&queue_array[student], word);
            }
        }

        int is_existed = 0;
        for (int word = 0; word < word_num; word++) {
            is_existed = 0;
            for (int student = 0; student < student_num; student++) {
                if (!strcmp(sentence[word], get_front(&queue_array[student]))) {
                    char* temp = dequeue(&queue_array[student]);
                    free(temp);  // Free the dequeued element
                    is_existed = 1;
                }
            }
            if (!is_existed) {
                break;
            }
        }
        printf("%d\n", is_existed);

        // Cleanup
        for (int word = 0; word < word_num; word++) {
            free(sentence[word]); // Free each word
        }
        free(sentence); // Free the array of words

        for (int student = 0; student < student_num; student++) {
            while (!is_empty(&queue_array[student])) {
                char* temp = dequeue(&queue_array[student]);
                free(temp); // Free remaining words in the queue
            }
        }
        free(queue_array); // Free the array of queues
    }
    return 0;
}