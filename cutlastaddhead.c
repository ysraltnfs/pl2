

struct n{
    int number;
    struct n *next;
};
typedef struct n node;

node * cutlastaddhead(node *head){
    node *p;
    p = head;

    while(1){
        if((p->next->next)==NULL){
            p->next->next = head;
            head =  p->next;
            p->next = NULL;
            return head;
        }
    }
}