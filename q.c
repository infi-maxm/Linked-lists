#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*next;
}node;

node*create_list(node*head,int n){
    node*newnode=(node*)malloc(sizeof(node));
    for(int i=0;i<n;i++){
    printf("Enter data to be entered in node");
    scanf("%d",&(newnode->data));
    newnode->next=NULL;
    node*temp;
    if(head==NULL){
        head=newnode;
        temp=head;
    }else{
        temp->next=newnode;
        temp=newnode;
    }
    }
    return head;

}

int main(){
    node*head1=NULL;
    node*head2=NULL;
    int n1,n2;
    printf("Enter the number of elements in list 1:");
    scanf("%d",&n1);
    printf("Enter the number of elements in list 2:");
    scanf("%d",&n2);
    create_list(head1,n1);
    create_list(head2,n2);
    
}