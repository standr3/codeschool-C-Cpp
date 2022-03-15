#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* link;
} Node;

void print(Node* head) {
	Node* temp = head;
	printf("Lista este: \n");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

//metoda1 :
//Node* insert(Node* head, int x) {
//	Node* temp = (Node*)malloc(sizeof(Node));
//	temp->data = x;
//	temp->link = NULL;
//
//	if (head != NULL) {
//		temp->link = head;
//	} else {
//		head = temp;
//	}
//	return head;
//
//}
void insert(Node** head, int x) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = x;
	temp->link = NULL;

	if (*head != NULL) {
		temp->link = *head;
	}
	else {
		*head = temp;
	}
}

// global
Node* _head = NULL;

void insert_nth(int data, int n)
{
	Node* temp1 = (Node*)malloc(sizeof(Node));
	temp1->data = data;
	temp1->link = NULL;

	if (n == 1)
	{
		temp1->link = _head;
		_head = temp1;
		return;
	}

	Node *temp2 = _head;
	for (int i = 0; i < n - 2; i++)
	{
		temp2 = temp2->link;
	}
	temp1->link = temp2->link;
	temp2->link = temp1;

}
void delete_nth(int n)
{
	Node* temp1 = _head;

	if (n == 1)
	{
		_head = temp1->link;
		free(temp1);
		return;
	}

	for (int i = 0; i < n - 2; i++) {
		Node* temp2 = temp1->link;
	}

	Node* temp2 = temp1->link;
	temp1->link = temp2->link;
	free(temp2);
}

Node* reverse(Node* head)
{
	Node* current, * prev, * next;
	current = head;
	prev = NULL;
	while (current != NULL)
	{
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

void print_recursive(Node* p)
{
	if (p == NULL)
	{
		printf("/n");
		return;
	}
	printf("%d ", p->data);
	print_recursive(p->link);
}
void reverse_print_recursive(Node* p)
{
	if (p == NULL)
	{
		return;
	}
	reverse_print_recursive(p->link);
	printf("%d ", p->data);
}

void reverse_recursion(Node* p)
{
	if (p->link == NULL) {
		_head = p;
		return;
	}
	reverse_recursion(p->link);
	Node* q = p->link;
	q->link = p;
	p->link = NULL;
}

////////////// 
//lista dubla inlantuita
typedef struct nodeD
{
	int data;
	nodeD* next;
	nodeD* prev;
}NodeD;

NodeD* cap;

NodeD* getNewNode(int x)
{
	NodeD* nod = (NodeD*)malloc(sizeof(NodeD));
	nod->data = x;
	nod->next = NULL;
	nod->prev = NULL;
	return nod;
}

void insert_cap(int x)
{
	/*NodeD nod;	
	nod.data = x;
	nod.next = NULL;
	nod.prev = NULL;*/ // variabila local , va fi stearsa cand se termina functia!!1
	NodeD* newNode = getNewNode(x);
	if (cap == NULL) {

		cap = newNode;
		return;

	}
	cap->prev = newNode;
	newNode->next = cap;
	cap = newNode;
}

//print () - same

void reverse_print() {
	NodeD* temp = cap;
	if (temp == NULL)return;
	while (temp->next = NULL)
		temp = temp->next;

	printf("REVERSE:");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main() {

	Node* A;
	A = NULL; // lista goala;
	// Creare nod nou
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = 3;
	(*temp).link = NULL;
	
	// primul nod in lista A = temp
	A = temp;

	//adaugam inca un nod la lista
	//pas 1: CREAM nodul
	temp = (Node*)malloc(sizeof(Node));
	temp->data = 4;
	temp->link = NULL;
	//pas 2: TRAVERSAM lista pana la locul de inserare a nodului(la final):
	Node* aux = A;
	while (aux->link != NULL)
	{
		aux = aux->link;
	}
	//pas 3: asociem noul nod la pozitia curenta
	aux->link = temp;

	/////////////////////////
	// inserare nod
	Node* head = NULL; // lista goala
	printf("Cate numere vom introduce?\n");
	int n, i, x;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("%d> ", i+1);
		scanf("%d", &x);
		//met1:
		//head = insert(head, x);
		//met2:
		insert(&head, x);
		print(head);

	}


	return 0;

}
