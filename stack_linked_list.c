#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

int isEmpty(){
    if(top == NULL){
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        return 1;
    }
    else {
        return 0;
    }
}

void push(int value){
    if (!isFull())
    {
        struct node* ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data = value;
        ptr->next = top;
        top = ptr;
    }
    else {
        printf("Stack smashed! No push operations possible\n");
    }
}

void pop(){
    if(isEmpty()){
        printf("Stack is already empty\n");
    }
    else if(top->next == top){
        top == NULL;
    }
    else {
        top = top->next;
    }
}
void cur_stack(){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if(!isEmpty()){
        ptr = top;
        while(ptr != NULL){
            printf("%d " , ptr->data);
            ptr = ptr->next;
        }
    }
    else {
        printf("Stack is empty\n");
    }
}

int main(){
    int n, val;
    printf("Choose the operation : \n1.Display stack\n2.push\n3.pop\n4.exit\n");
    while(1){
        printf("\n==> ");
        scanf("%d" , &n);
        if(n == 4){
            exit(0);
        }
        else if(n == 1){
            cur_stack();
        }
        else if(n == 2){
            printf("Enter value to push\n==> ");
            scanf("%d" , &val);
            push(val);
            cur_stack();
        }
        else if(n == 3){
            pop();
            cur_stack();
        }
        else {
            printf("Enter correct choice :(\n");
        }
    }    
    return 0;
}