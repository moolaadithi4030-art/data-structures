#include<stdio.h>
#define max 3
int queue[max];
int front=-1;
int rear=-1;
void insert(int value){
if(rear==max-1){
   printf("queue overflow\n");
   return;}
if(front==-1){
    front=0;
}
else{
    rear++;
    queue[rear]=value;}
    printf("Element %d successfully inserted inside queue\n",value);
}
int delete(){
if(front==-1||front>rear){
    printf("queue underflow\n");
    return -1;
}
int value;
value=queue[front];
front++;
if(front>rear){
    front=-1;
    rear=-1;
}
return value;}
void display(){
if(front==-1||front>rear){
    printf("queue underflow\n");
}
printf("queue elements\n");
for(int i=front;i<=rear;i++){
    printf("%d\n",queue[i]);
}
printf("\n");}
int main(){
    int choice,value;
    while(1){
        printf("---Linear Queue operation Menu---\n ");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("Enter Choice(1-3)\n");
        scanf("%d",&choice);
        switch(choice){
        case 1: printf("enter the element to be inserted\n");
        scanf("%d",&value);
        insert(value);
        break;
        case 2: value=delete();
        if (value!=-1){
            printf("element %d removed successfully\n",value);}
        break;
        case 3:display();
        break;
        default:
            printf("enter valid choice\n");
        }
    }return 0;
}
