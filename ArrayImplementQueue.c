#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define MAX 10
struct Queue
{
    int arr[MAX];
    int rear,front;
};
void main()
{
    struct Queue q;
    int ch,n,x;
    int isfull(struct Queue);
    void enqueue(struct Queue *, int);
    int isempty(struct Queue);
    int dequeue(struct Queue *);
    int queuetop(struct Queue);
    void list(struct Queue);

    q.rear=q.front=-1;
    while(1){
        printf("\n MAin Menu : ");
        printf("\n 1. Insert an element into the Queue");
        printf("\n 2. Delete an element from the Queue");
        printf("\n 3. Show the top element from the Queue");
        printf("\n 4. show the List of the Queue Elements");
        printf("\n  5.EXIT");
        printf("\n Enter your Choice");
        scanf("\n%d",&ch);
        switch(ch){
            case 1:
            if(isfull(q)==TRUE){
                printf("\n Queue is OverFlow");
                getch();
            }
            else
            {
                printf("\n Enter a new element for insert into the Queue ");
                scanf("%d",&x);
                enqueue(&q,x);
            }
            break;
            case 2:
            if(isempty(q)==TRUE)
            {
                printf("\n Queue is underflow");
                getch();
            }
            else{
                n=dequeue(&q);
                printf("\n Deleted element is=%d",n);
                getch();
            }
            break;
            case 3:
            if(isempty(q)==TRUE)
            {
                printf("\n Queue is Allready Empty");
                getch();
            }
            else{
                     n=queuetop(q);
                     printf("\n Topped Element of the Queue is =%d",n);
                     getch();
            }
            break;
            case 4:
            if(isempty(q)==TRUE)
            {
                printf("\n Queue is Allready Empty");
                getch();
            }
            else{
               
                printf("\nList of the Queue Elements are",q);
                 list(q);
                getch();
            }
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("\n Wrong Choice ");
            break;

            
        }
    }
}
int isfull(struct Queue q){
    if(q.front==0 && q.rear==(MAX-1))
    return(TRUE);
    else
    return(FALSE);
}
 void enqueue(struct Queue *q, int x){

int i;
if(q->rear==-1){
q->rear=q->front=0;

}
else if(q->rear==MAX-1){
    for(i=q->front; i<=MAX-1;i++)
    q->arr[i-q->front]=q->arr[i];
    q->rear=q->rear-q->front+1;
    q->front=0;
}
else 
q->rear=q->rear+1;
q->arr[q->rear]=x;
}
int isempty(struct Queue q)
{
    if(q.front==-1)
    return(TRUE);
else
return(FALSE);
}
 int dequeue(struct Queue *q){
    int  x;
    x=q->arr[q->front];
    if(q->rear==q->front)
    q->rear=q->front=-1;
    else
    q->front=q->front+1;
    return(x);

 }
 int queuetop(struct Queue q)
 {
    int x;
    x=q.arr[q.front];
    return(x);
 }
 void list(struct Queue q){
    int i;
    for(i=q.front; i<=q.rear;i++)
    printf("\n %d\t",q.arr[i]);
 }