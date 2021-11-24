#include<stdio.h>
#include<stdlib.h>

int top = -1;

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(int *a , int size){
    if(top == size-1){
        return 1;
    }
    else {
        return 0;
    }
}

void push(int value , int *a , int size){
    if(isFull(a , size)){
        printf("Stack is full can't push\n");
    }
    else {
        ++top;
        a[top] = value;
    }
}

void pop(){
    if(isEmpty()){
        printf("Stack is empty can't pop\n");
    }
    else {
        top--;
    }
}

void curStack(int *a){
    if(isEmpty()){
        printf("Stack is empty\n");
    }
    else {
        for(int i=0; i< top ; i++){
            printf("%d " , a[i]);
        }
    }
}

void main(){
    int n , x , size;
    printf("Enter the size of stack : ");
    scanf("%d" , &size);
    int a[size];
    printf("Which operation u want to perform : \n");
    printf("1. push\n2. pop\n3. show current stack\n4. exit\n\n ");
    while(1){
        printf("top = %d " , top);
        printf("\n--> ");
        scanf("%d",&n);
        if(n == 4){
            exit(0);
        }
        else if(n == 1){
            printf("Enter the value : ");
            scanf("%d",&x);
            push(x , a , size);
        }
        else if(n == 2){
            pop();
        }
        else if(n == 3) {
            curStack(a);
        }
        else {
            printf("Wrong input\n");
        }
    }

}