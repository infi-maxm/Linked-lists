#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

void traverse(struct Node*head){
   struct Node*ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }

}

struct Node*create(int data){
    struct Node*newn =(struct Node*)malloc(sizeof(struct Node));
    newn->data = data;
    newn->next = NULL;
    return newn;
}

struct Node*insertatBeg(struct Node*head,int data){
  struct Node*n = create(data);
  n->next=head;
  head=n;
  return head;
}

struct Node*insertatpos(struct Node*head,int pos,int data){
    struct Node*n = create(data);
    struct Node*ptr=head;
    int p=1;
    while(p<(pos-1)){
        p++;
        ptr=ptr->next;
    }
    n->next=ptr->next;
    ptr->next=n;

    return head;
}

struct Node*deleteatBeg(struct Node*head){
    if(head == NULL) return NULL;
    struct Node*ptr=head;
    head=ptr->next;
    free(ptr);
    return head;
}

struct Node*deleteatpos(struct Node*head,int pos){
    if(head == NULL) return NULL;
    struct Node*ptr1=head;
    for(int i=1;i<(pos-1);i++){
        ptr1=ptr1->next;
    }
    struct Node*ptr2=ptr1->next;
    ptr1->next=ptr2->next;
    free(ptr2);
    return head;
}

struct Node*reverse(struct Node*head){
    struct Node*prevn=NULL;
    struct Node*currn=head;
    struct Node*nextn=head;
    while(currn!=NULL){
        nextn=currn->next;
        currn->next=prevn;
        prevn=currn;
        currn=nextn;
    }
    nextn=prevn;
    return nextn;
}

int main(){
struct Node*head =NULL;
struct Node*temp =NULL;
int n;
printf("Enter the number of nodes you want:");
scanf("%d",&n);
for(int i=1;i<=n;i++){
    // struct Node*newnode =(struct Node*)malloc(sizeof(struct Node));
    int data;
    printf("Enter data to be entered in node:");
    scanf("%d",&data);
    struct Node* newnode = create(data);
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        temp=head;
    }else{
        temp->next=newnode;
        temp=temp->next;
    }
}

printf("\nCreated linked list:\n");
traverse(head);
int pos;
printf("\nIf u want to insert data at any position upto n=%d tell position: ",n);
scanf("%d",&pos);
int dat;
    printf("\nEnter data to be entered in node:");
    scanf("%d",&dat);
if(pos==1){
    head=insertatBeg(head,dat);
    n++;
}else if(pos!=1 && pos<=n){
     head=insertatpos(head,pos,dat);
    n++;
}
printf("\nCreated linked list:\n");
traverse(head);
printf("\nIf u want to delete node at any position upto n=%d tell position: ",n);
scanf("%d",&pos);
if(pos==1){
    head=deleteatBeg(head);  
}else if(pos!=1 && pos<=n){
    head=deleteatpos(head,pos);
}
printf("\nCreated linked list:\n");
traverse(head);

printf("\nReversed linked list:\n");
head=reverse(head);
traverse(head);
printf("\n");

struct Node*ptr=head;
while(ptr!=NULL){
    struct Node*next = ptr->next;
    free(ptr);
    ptr=next;
}

return 0;
}
