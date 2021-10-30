#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* head = NULL;
struct node* last = NULL;
int count;

void traverse(){
    printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n");
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    count = 0;
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    else {
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
            count++;
        }
        last = ptr;
    }
    printf("  [ %d ]" , count);
    printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n");
    
}


void addFirst(int value){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->next = head;
    head = ptr;
}

void create(int value){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* addedNode = (struct node*)malloc(sizeof(struct node));
        addedNode->data = value;
        addedNode->next = NULL;
    if(head == NULL){
        addFirst(value);
    }
    else{
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = addedNode;
    }
}

void insert(int value , int index){
    if(index <= count){
        if(index == 0){
            printf("\nEnter a valid position\n\n");
        }
        else if(index == 1){
            addFirst(value);
        }
        else {
                struct node* ptr = (struct node*)malloc(sizeof(struct node));
                struct node* addedNode = (struct node*)malloc(sizeof(struct node));
                struct node* listPtr = (struct node*)malloc(sizeof(struct node));
                addedNode->data = value;
                ptr = head;
            for(int i = 2 ; i < index ; i++){
                ptr = ptr->next;
            }
            listPtr = ptr->next;
            ptr->next = addedNode;
            addedNode->next = listPtr;
        }
    }
    else {
        printf("\nPosition does not exist! Try Again!!\n\n");
    }
}

void search(int value){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    count = 1;
    printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n");

    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    else {
        ptr = head;
        while (ptr != NULL)
        {
            if(ptr->data == value){
                printf("\nElement found at %d position\n\n", count);
                break;
            }
            ptr = ptr->next;
            count++;
        }
        if(ptr == NULL){
            printf("\nElement not found!!\n\n");
        }
    }
    printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n");
}

void delete(int index){
    if(index <= count){
        struct node* ptr = (struct node*)malloc(sizeof(struct node));
        struct node* deletedNode = (struct node*)malloc(sizeof(struct node));
        struct node* listPtr = (struct node*)malloc(sizeof(struct node));
        if(index == 0){
            printf("\nEnter a valid index (search the element if you doubt)\n\n");
        }
        else if (index == 1)
        {
            ptr = head;
            listPtr = ptr->next;       
            deletedNode = ptr;
            head = listPtr;
            free(deletedNode);
        }
        else {
            ptr = head;
            for(int i = 2; i < index ; i++){
                ptr = ptr->next;
            }
            listPtr = ptr->next->next;
            deletedNode = ptr->next;
            ptr->next = listPtr;
        }
    }
    else {
        printf("\nSpecified index does not exist in the linked list.\n");
    }
}

void main() {
    int n = 10,i,index;
    while(n != 0){
        printf("Enter the choice \n1.To display the linked list\n2.To create an element\n3.To insert an element in the list\n4.To delete an element form the list\n5.To search an elelment\nEnter here -> ");
        scanf("%d", &n);

        if(n == 0){
            exit(0);
        }

        else if(n == 1){
            printf("\n");
            traverse();
        }

        else if(n == 2){
            printf("\nEnter the value : ");
            scanf("%d", &i);
            create(i);
            traverse();
        }

        else if(n == 3){
            printf("\nEnter the value : ");
            scanf("%d", &i);
            printf("\nEnter the position where you want to insert the element : ");
            scanf("%d", &index);
            insert(i , index);
            traverse();
        }

        else if(n == 4){
            printf("\nEnter the index of element : ");
            scanf("%d", &index);
            delete(index);
            traverse();
        }

        else if(n == 5){
            printf("\nEnter the value to search : ");
            scanf("%d", &i);
            search(i);
        }

        else {
            printf("\nEnter a valid choice\n\n");
            printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n");
        }
    }
}