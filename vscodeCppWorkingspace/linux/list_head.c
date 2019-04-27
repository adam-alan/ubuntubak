#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct list_head{
    struct list_head * prior;
    struct list_head * next;
};

#define LIST_HEAD_INIT(name)\ 
                { &(name), &(name)}
#define LIST_HEAD(name)\
    struct list_head name = LIST_HEAD_INIT(name)
void inline add(struct list_head *new,struct list_head *head){
    if (head == NULL || new == NULL){
        exit(0);
    }

    new->next = head->next;
    new->prior = head;
    head->next->prior = new;
    head->next = new;   
}    
int main(){
    bool is_true = false;
    struct list_head list = LIST_HEAD_INIT(list);
    printf("%p %p %p\n",(&list),list.prior,list.next);
    return 0;
}