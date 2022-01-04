#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
	struct node* prev;
};
struct node* head = NULL;
struct node* tail = NULL;
int sz = 0;

void traverse(){
	if(head == NULL){
		printf("Linked list is empty.");
		return;
	}

	struct node* ptr = head;
	do {
		printf(" %d " , ptr->data);
		ptr = ptr->next;
	}while(ptr != tail->next);
	printf(" [%d] H:%d T:%d" , sz , head->data , tail->data);
}

void create(int val){
	struct node* ptr = head;
	struct node* addPtr = (struct node*)malloc(sizeof(struct node));
	if(ptr == NULL){
		addPtr->data = val;
		addPtr->next = addPtr;
		addPtr->prev = addPtr;
		head = addPtr;
		tail = addPtr;
		sz++;
	}
	else{
		addPtr->data = val;
		addPtr->next = head;
		addPtr->prev = tail;
		tail->next = addPtr;
		head->prev = addPtr;
		tail = addPtr;
		sz++;
	}
}

void insert(int ind, int val){
	struct node* addPtr = (struct node*)malloc(sizeof(struct node));
	struct node* ptr = head;
	if(head == NULL){
		create(val);
		return;
	}
	else if(ind == 1){
		addPtr->data = val;
		addPtr->next = head;
		addPtr->prev = tail;
		head = addPtr;
		sz++;
		return;
	}
	else if(ind >= sz){
		create(val);
		return;
	}
	for(int i = 1; i < ind-1; i++){
		ptr = ptr->next;
	}
	addPtr->data = val;
	addPtr->next = ptr->next;
	addPtr->prev = ptr;
	ptr->next->prev = addPtr;
	ptr->next = addPtr;
	sz++;
	return;
}

void remove(){
	struct node* deletePtr = (struct node*)malloc(sizeof(struct node));
	if(head == NULL){
		printf("Nothing to delete");
		return;
	}
	else if(sz == 1){
		deletePtr = head;
		free(deletePtr);
		sz--;
		head = NULL;
		tail = NULL;
		return;
	}
	deletePtr = tail;
	tail = tail->prev;
	free(deletePtr);
	sz--;
}

void deleteAt(int ind){
	struct node* ptr = head;
	struct node* deletePtr = (struct node*)malloc(sizeof(struct node));
	if(head == NULL){
		printf("Nothing to delete");
		return;
	}
	else if(ind == 1 && sz > 1){
		deletePtr = head;
		head = ptr->next;
		free(deletePtr);
		sz--;
		return;
	}
	else if(ind == 1 && sz == 1){
		remove();
	}
	else if(ind >= sz){
		remove();
	}

	for(int i = 1; i < ind; i++){
		ptr = ptr->next;
	}

	ptr->next->prev = ptr->prev;
	ptr->prev->next = ptr->next;
	deletePtr = ptr;
	sz--;
	free(deletePtr);
	return;
}

int main(){
	int n , val , ind;
	printf("Enter choice\n1.traverse\n2.create\n3.insert\n4.remove\n5.deleteAtIndex\n6.exit");
	while(1){
		printf("\n==> ");
		scanf("%d" , &n);
		if(n == 6){
			exit(0);
		}
		else if(n == 1){
			traverse();
		}
		else if(n == 2){
			printf("Enter the value: ");
			scanf("%d" , &val);
			create(val);
		}
		else if(n == 3){
			printf("Enter index: ");
			scanf("%d" , &ind);
			printf("Enter value: ");
			scanf("%d" , &val);
			insert(ind,val);
		}
		else if(n == 4){
			remove();
		}
		else if(n == 5){
			printf("Enter index: ");
			scanf("%d" , &ind);
			deleteAt(ind);	
		}
		else {
			printf("Enter a valid number.");
		}
	}

	return 0;
}