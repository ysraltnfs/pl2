#include<stdio.h>
#include<stdlib.h>

struct n{
    int number;
    struct n *next;
};
typedef struct n node;

node * changeFirstAndLast(node *head){
    node *p, *t;
    p = head;


    while(1){
        if(p->next->next == NULL) break;
        p = p->next;

    }
    t = p->next;
    p->next->next = head->next;
    p->next = head;
    p->next->next = NULL;
    head = t;
    return head;



}