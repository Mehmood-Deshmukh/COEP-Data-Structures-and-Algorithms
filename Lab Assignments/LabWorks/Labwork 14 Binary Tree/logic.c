#include "header.h"
#include "queue.h"


void init(BT *bt){
    *bt = NULL;
}


void insert(BT *bt, int data){
    BT temp, newNode;
    Queue q;
    initQueue(&q);
    newNode = (Node *)malloc(sizeof(Node));
    if(!newNode) return;
    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if(*bt == NULL){
        *bt = newNode;
        return;
    }
    enqueue(&q, *bt);
    while(!isEmpty(q)){
        int size = getSize(q);
        while(size--){
            temp = dequeue(&q);
            if(temp->left){
                enqueue(&q, temp->left);
            }else{
                temp->left = newNode;
                return;
            }
            if(temp->right){
                enqueue(&q, temp->right);
            }else{
                temp->right = newNode;
                return;
            }
        }
    }
}

void inorder(BT bt){
    if(!bt) return;
    inorder(bt->left);
    printf("%d ", bt->data);
    inorder(bt->right);
}

void preorder(BT bt){
    if(!bt) return;
    printf("%d ", bt->data);
    preorder(bt->left);
    preorder(bt->right);
}

void postorder(BT bt){
    if(!bt) return;
    postorder(bt->left);
    postorder(bt->right);
    printf("%d ", bt->data);
}

int countLeaf(BT bt){
    if(!bt) return 0;
    if(bt->left == NULL && bt->right == NULL){
        return 1;
    }else{
        return countLeaf(bt->left) + countLeaf(bt->right);
    }
}

int countNonLeaf(BT bt){
    if(!bt) return 0;
    if(bt->left == NULL && bt->right == NULL){
        return 0;
    }else{
        return 1 + countNonLeaf(bt->left) + countNonLeaf(bt->right);
    }
}
