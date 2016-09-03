#ifndef LINKED_H_
#define LINKED_H_


typedef struct node {
	int data;
	struct node *next;
} node;

typedef struct BigInt {
	node *head;
} BigInt;

void init (BigInt *p);
void print (BigInt p);
int is_empty(BigInt b);
void append_digit (BigInt *d, int x);
void prepend_digit (BigInt *p, int x);
void add (BigInt d, BigInt p, BigInt *x);

#endif /* LINKED_H_ */
