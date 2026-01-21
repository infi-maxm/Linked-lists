#include<stdio.h>
#include<stdlib.h>

typedef struct node{
   int data;
   struct node*next;
   struct node*prev;
}node;

node*create_list(node*head,int n){
    int data;
    node*temp;
    for(int i=0;i<n;i++){
        node*newnode=(node*)malloc(sizeof(node));
        printf("Enter data to be entered in node:");
        scanf("%d",&data);
        newnode->data=data;
        newnode->prev=NULL;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=head;
        }else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
    return head;
}

void traverse(node*head){
    node*ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

node*insert_begin(node*head){
    int data;
    node*newnode=(node*)malloc(sizeof(node));
    printf("Enter data to be entered in node:");
    scanf("%d",&data);
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=head;
    if(head!=NULL){
    head->prev=newnode;}
    head=newnode;

    return head;
}

node*insert_pos(node*head,int pos){
    int data;
    node*newnode=(node*)malloc(sizeof(node));
    printf("Enter data to be entered in node:");
    scanf("%d",&data);
    newnode->data=data;
    int p=1;
    node*ptr=head;
    while(p<(pos-1) && ptr!=NULL){
        ptr=ptr->next;
        p++;
    }
    node*temp=ptr->next;
    newnode->prev=ptr;
    newnode->next=ptr->next;
    ptr->next=newnode;
    temp->prev=newnode;

    return head;
}

node*insert_end(node*head){
    int data;
    node*newnode=(node*)malloc(sizeof(node));
    printf("Enter data to be entered in node:");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=NULL;
    node*ptr=head;
    node*temp;
    while(ptr!=NULL){
        temp=ptr;
        ptr=ptr->next;
    }
    newnode->prev=temp;
    temp->next=newnode;

    return head;
}

int main(){
    node*head=NULL;
    int n;
    printf("Enter the number of nodes you want:");
    scanf("%d",&n);

    head=create_list(head,n);

    traverse(head);

    char c;
    int pos;
    printf("\nDo you want to insert (Y/n):\n");
    scanf(" %c",&c);
    if(c=='Y'){
        
        printf("Enter position:");
        scanf("%d",&pos);
        if(pos==1){
            head=insert_begin(head);
        }else if(pos!=1 &&pos<=n){
            head=insert_pos(head,pos);
        }else if(pos==(n+1)){
            head=insert_end(head);
        }
        n++;
    }

    traverse(head);

    while(head!=NULL){
        node*temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}