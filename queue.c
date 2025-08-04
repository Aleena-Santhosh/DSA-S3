#include <stdio.h>

int queue[10];
int front = -1, rear = -1;
int size = 0; 
void enqueue(int value) {
    if (rear == size - 1) {
        printf("Overflow!!\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("%d enqueued\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Underflow!!\n");
    } else {
        printf("%d dequeued\n", queue[front++]);
        if (front > rear) front = rear = -1;
    }
}

void peek() {
    if (front == -1 || front > rear) {
        printf("Empty Queue!!\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Empty Queue!!\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int op, choice, value;
    printf("Enter the size: ");
    scanf("%d", &size);
    if (size <= 0 || size > 10) {
        printf("Invalid size!!\n");
        return 1;
    }
    printf("\nQueue Operations:\n");
    printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n");
    printf("No of operations to be performed: ");
    scanf("%d", &op);
    for (int i = 0; i < op; i++) {
        printf("\nEnter your choice (1-Enqueue; 2-Dequeue; 3-Peek; 4-Display): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            default:
                printf("Invalid choice!!\n");
        }
    }
    return 0;
}