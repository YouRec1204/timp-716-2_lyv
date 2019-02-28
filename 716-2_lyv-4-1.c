#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} node;
typedef node* list;

int init(list *root){                       //инициализация
	*root = NULL;
    	return 1;
}

int push(list *head, int value){            //впихиваем элемент наверх
    	list tmp=malloc(sizeof(node));
    	if(tmp==NULL) exit(STACK_OVERFLOW);
    	tmp->next=*head;
    	tmp->value=value;
    	*head = tmp;
    	return 1;
}

list find(list root, int value) {           //поиск по значению
    	while (root->value != value) {
        	root = root->next;
        	if (root == NULL) return NULL;
    	}
    	return root;
}

int pop(node **head) {                      //удаление элемента
    	node *out;
    	int value;
    	if (*head == NULL) {
        	exit(STACK_UNDERFLOW);
    	}
    	out = *head;
    	*head = (*head)->next;
  	value = out->value;
    	free(out);
    	return value;
}

int isEmpty(list root) {                    //пустой ли?
    	if (root) return 1;
    	else return 0;
}

int destroy(list *root) {                   //очистка стека
    	list next;
    	while (*root != NULL) {
        	next = *root;
        	*root = (*root)->next;
        	free(next);
    	}
    	return 1;
}

int print(list *lst) {                      //вывод
    	list temp = *lst;
    	while (temp != NULL) {
        	printf("%d ", temp->value);
        	temp = temp->next;
    	}
    	printf("\n");
    	return 1;
}

int main() {
    	list head;
    	init(&head);
    	int x, n, m, d;

    	scanf("%d", &n);
    	if (n > 0) {
        	for(int i=0;i<n;i++){
            	scanf("%d", &x);
            	push(&head, x);
        	}
    	}
    	print(&head);

    	scanf("%d",&m);
    	list del = find(head, m);
    	if (del != NULL) printf("value has been found\n");
    	else printf("value has not been found\n");
    	print(&head);

    	scanf("%d",&d);
    	if(d<=n)for(int i=0;i<d;i++)pop(&head);
    	else printf("check data\n");
	print(&head);
    	destroy(&head);
    	return 0;
}

