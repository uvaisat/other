#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int queue[SIZE];
int front = 0;
int rear = 0;
void enqueue(int item);
int dequeue(void);
void display(void);
int main(void)
{
int option;
int item;
do{
printf("\n1. Insert\n");
printf("2. Delete\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Your choice: ");
if(scanf("%d", &option) != 1)
{
printf("Invalid input.\n");
return 1;
}
switch (option) {
case 1:
printf("Enter item: ");
scanf("%d", &item);
enqueue(item);
break;
case 2:
item = dequeue();
if(item != -1){
printf("Deleted value = %d\n", item);
}
break;
case 3:
display();
break;
case 4:
printf("Exiting...\n");
break;
default:
printf("Invalid choice.\n");
}
} 
while (option != 4);
return 0;
}
// Insert an item into the queue
void enqueue(int item)
{
int next_rear = (rear + 1) % SIZE;
if(next_rear == front) {
printf("Queue is full.\n");
return;
}
rear = next_rear;
queue[rear] = item;
printf("%d inserted successfully.\n", item);
}
/* Delete an item from the queue */
int dequeue(void)
{
if (front == rear) {
printf("Queue is empty.\n");
return -1;
}
front = (front + 1) % SIZE;
return queue[front];
}
/* Display all queue elements */
void display(void)
{
int i;
if(front == rear) {
printf("Queue is empty.\n");
return;
}
printf("Queue elements: ");
i = (front + 1) % SIZE;
while (1) {
printf("%d ", queue[i]);
if (i == rear) {
break;
}
i = (i + 1) % SIZE;
}
printf("\n");
}
