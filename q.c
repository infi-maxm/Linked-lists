#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*next;
}node;

node*create_list(node*head,int n){
    if(n<=0) return head;
    node*temp=NULL;

    for(int i=0;i<n;i++){

    node*newnode=(node*)malloc(sizeof(node));
    printf("Enter data to be entered in node:");
    scanf("%d",&(newnode->data));
    newnode->next=NULL;
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

node*concatenate(node*head1,node*head2){
    node*p1=head1;
    node*headc=NULL;
    while((p1->next)!=NULL){
        p1=p1->next;
    }
    if(head2!=NULL)
        p1->next=head2;
    headc=head1;
    return headc;
}

node*reverse(node*head){
    node*prev=NULL;
    node*curr=head;
    node*nxt=head;
    while(curr!=NULL){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
        
    }
    nxt=prev;
    return nxt;
    

}

void traverse(node*head){
    if(head==NULL){
        printf("List is empty");
        return;
    }
    node*ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
         ptr=ptr->next;
    }
}

void middle(node*head,int n1,int n2){
    int n=n1+n2;
    node*ptr=head;
    int p=(n/2);

    if(n==1){
        printf("%d",ptr->data);
    }else
            {if(n%2!=0){
                    for(int i=1;i<=p;i++){
                        ptr=ptr->next;
                    }
                    printf("%d",ptr->data);
            }else{
                    for(int i=1;i<p;i++){
                        ptr=ptr->next;
                    }
                    printf("%d ",ptr->data);
                    printf("%d ", ptr->next->data);
        
            }
     }
}

int main(){
    node*head1=NULL;
    node*head2=NULL;
    int n1,n2;
    printf("Enter the number of elements in list 1:");
    scanf("%d",&n1);
    printf("Enter the number of elements in list 2:");
    scanf("%d",&n2);
    printf("LIST-1:\n");
    head1=create_list(head1,n1);
    printf("LIST-2:\n");
    head2=create_list(head2,n2);

    printf("\nList 1:");
    traverse(head1);
    printf("\n");
    printf("List 2:");
    traverse(head2);
    printf("\n");
    printf("\nList concatenated:");
    node*headc=concatenate(head1,head2);
    traverse(headc);
    printf("\nMiddle element(s):");
    middle(headc,n1,n2);
    printf("\n");
    node*headr=reverse(headc);
    printf("\nReversed List:");
    traverse(headr);
    printf("\n");

    node*ptr1=head1;
    node*ptr2=head2;
    node*ptr3=headc;
    // while(ptr1!=NULL){
    //     node*next=ptr1->next;
    //     free(ptr1);
    //     ptr1=next;
    // }
    // while(ptr2!=NULL){
    //     node*next=ptr2->next;
    //     free(ptr2);
    //     ptr2=next;
    // }
    while(ptr3!=NULL){
        node*next=ptr3->next;
        free(ptr3);
        ptr3=next;
    }

    return 0;
    
}