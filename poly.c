#include<stdio.h>
#include<stdlib.h>

typedef struct node{
   int coeff;
   int pow;
   struct node*next;
}node;


node*create_list(node*head,int n){
    if(n<=0){return head;}
    node*temp;
    for(int i=0;i<n;i++){
         node*newnode=(node*)malloc(sizeof(node));
         printf("Enter coeff to be entered in node:");
         scanf("%d",&newnode->coeff);
         printf("Enter power to be entered in node:");
         scanf("%d",&newnode->pow);
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

void traverse(node*head){
    if(head==NULL){printf("Empty list");}
    node*ptr=head;
    while(ptr!=NULL){
        printf("c:%d ",ptr->coeff);
        printf("p:%d  ",ptr->pow);
        printf("%dx%d  ",ptr->coeff,ptr->pow);
        ptr=ptr->next;
    }
}

node*add(node*head1,node*head2,node*head3){
    node*p1=head1;
    node*p2=head2;
    node*newn=(node*)malloc(sizeof(node));
    head3=newn;
    node*ptr;
    if(head1->pow>head2->pow){
        newn->pow=p1->pow;
        newn->coeff=p1->coeff;
        ptr=newn;
        p1=p1->next;
    }else if(head2->pow>head1->pow){
        newn->pow=head2->pow;
        newn->coeff=head2->coeff;
        ptr=newn;
        p2=p2->next;
    }else{
        newn->pow=head1->pow;
        newn->coeff=head1->coeff+head2->coeff;
        ptr=newn;
        p1=p1->next;
        p2=p2->next;
    }
    while(p1!=NULL && p2!=NULL){
        node*newn=(node*)malloc(sizeof(node));
        ptr->next=newn;
            if(p1->pow>p2->pow){
            newn->pow=p1->pow;
            newn->coeff=p1->coeff;
            ptr=newn;
            p1=p1->next;
            }else if(p2->pow>p1->pow){
                newn->pow=p2->pow;
                newn->coeff=p2->coeff;
                ptr=newn;
                p2=p2->next;
            }else{
                newn->pow=p1->pow;
                newn->coeff=p1->coeff+p2->coeff;
                ptr=newn;
                p1=p1->next;
                p2=p2->next;
            }
    }

    if(p1==NULL){
        while(p2!=NULL){
                node*newn=(node*)malloc(sizeof(node));
                ptr->next=newn;
                newn->coeff=p2->coeff;
                newn->pow=p2->pow;
                p2=p2->next;
        }
    }else if(p2==NULL){
        while(p1!=NULL){
                node*newn=(node*)malloc(sizeof(node));
                ptr->next=newn;
                newn->coeff=p1->coeff;
                newn->pow=p1->pow;
                p1=p1->next;
        }
    }
    ptr->next=NULL;

    return head3;

}

int main(){
    node*head1=NULL;
    node*head2=NULL;
    node*head3=NULL;
    int n1,n2;
    printf("Enter the number of elements in list 1:");
    scanf("%d",&n1);
    printf("Enter the number of elements in list 2:");
    scanf("%d",&n2);

    printf("\nList 1:\n");
    head1=create_list(head1,n1);
    printf("POLY LIST-1:\n");
    traverse(head1);

     printf("\nList 2:\n");
    head2=create_list(head2,n2);
    printf("\nPOLY LIST-2:\n");
    traverse(head2);    

    printf("\nList on adding:\n");
    head3=add(head1,head2,head3);
    traverse(head3);

    node*ptr=head3;
    while(ptr!=NULL){
        node*nextn=ptr->next;
        free(ptr);
        ptr=nextn;
    }

    
}