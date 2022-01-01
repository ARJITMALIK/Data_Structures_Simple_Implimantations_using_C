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

void create(int val){
	if(head == NULL){
		struct node* ptr = (struct node*)malloc(sizeof(struct node));
		ptr->data = val;
		ptr->next = NULL;
		ptr->prev = NULL;
		head = ptr;
		tail = ptr;
		sz++;
	}
	else{
		struct node* addPtr = (struct node*)malloc(sizeof(struct node));
		tail->next = addPtr;
		addPtr->data = val;
		addPtr->next = NULL;
		addPtr->prev = tail;
		tail = addPtr;
		sz++;
	}
}

void traverse(){
	if(head == NULL){
		printf("List is empty\n");
		return;
	}

	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	ptr = head;
	while(ptr != NULL){
		printf(" %d " , ptr->data);
		ptr = ptr->next;
	}
	printf(" [%d] ",sz);
	printf(" head: %d", head->data);
	printf(" tail: %d", tail->data);
}

void insert(int val , int ind){
	struct node* addPtr = (struct node*)malloc(sizeof(struct node));
	if(head == NULL){
		create(val);
		sz++;
		return;
	}
	else if(ind == 1){
		addPtr->data = val;
		addPtr->next = head;
		addPtr->prev = NULL;
		head = addPtr;
		sz++;
		return;
	}
	else if(ind >= sz){
		create(val);
		return;
	}
	struct node* ptr = head;
	for (int i = 1; i < ind-1; i++)
	{
		ptr = ptr->next;
	}
	addPtr->data = val;
	ptr->next->prev = addPtr;
	addPtr->next = ptr->next;
	ptr->next = addPtr;
	addPtr->prev = ptr;
	sz++;
	return;
}

void remove(){
	if(sz == 0){
		printf("No elements to delete!!\n");
		return;
	}
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	ptr = tail;
	tail = tail->prev;
	tail->next = NULL;
	sz--;
	free(ptr);
}

void deleteAt(int ind){
	if(sz == 0){
		printf("No elements to delete!!\n");
	}
	else if(ind >= sz){
		remove();
	}
	else {
		struct node* ptr = head;
		if(ind == 1){
			struct node* temp = head;
			head = head->next;
			free(temp);
			sz--;
			return;
		}
		for (int i = 1; i < ind; i++)
		{
			ptr = ptr->next;
		}
		ptr->next->prev = ptr->prev;
		ptr->prev->next = ptr->next;
		free(ptr);
		sz--;
	}
}

int main(){
	int n , val , ind;
	printf("Enter choice : \n1.traverse\n2.create\n3.insert\n4.delete\n5.remove\n6.exit\n");
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
			printf("Enter value ==> ");
			scanf("%d" , &val);
			create(val);
		}
		else if(n == 3){
			printf("\nEnter the index : ");
			scanf("%d", &ind);
			printf("\nEnter the value : ");
			scanf("%d", &val);
			insert(val,ind);
		}
		else if(n == 5){
			remove();
		}
		else if(n == 4){
			printf("Enter the index ==> ");
			scanf("%d" , &ind);
			deleteAt(ind);
		}
		else{
			printf("Enter valid choice :(\n");
		}
	}

	return 0;
}