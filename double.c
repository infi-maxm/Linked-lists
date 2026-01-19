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
    node*ptr=newnode;
    newnode->prev=NULL;
    newnode->next=head;
    head=newnode;
    ptr=ptr->next;
    ptr->prev=newnode;

    return head;
}

node*insert_pos(node*head,int pos){
    int data;
    node*newnode=(node*)malloc(sizeof(node));
    printf("Enter data to be entered in node:");
    scanf("%d",&data);
    newnode->data=data;
    
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
    printf("Do you want to insert (Y/n):");
    scanf(" %c",&c);
    if(c=='Y'){
        
        printf("Enter position:");
        scanf("%d",&pos);
        if(pos==1){
            head=insert_begin(head);
        }else if(pos!=1 &&pos<n){

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