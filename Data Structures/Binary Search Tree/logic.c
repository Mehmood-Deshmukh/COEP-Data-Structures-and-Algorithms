#include "header.h"
#include "stack.h"
#include "queue.h"

void init(BST *root){
    *root = NULL;
}
Node *recursive_search(BST root, int key){
    if(!root) return root;

    if(root->data == key) return root;

    if(key < root->data) return recursive_search(root->left, key);
    else return recursive_search(root->right, key); 
}

Node *iterative_search(BST root, int key){
    Node *temp = root;
    while(temp){
        if(temp->data == key) return temp;
        if(key < temp->data){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }

    return temp;
}

void iterative_insert(BST *root, int data){
    Node *temp = *root;

    Node *new_node = (Node *) malloc(sizeof(Node));
    if(!new_node) return;

    new_node->data = data;
    new_node->left = new_node->right = NULL;

    if(!temp){
        *root = new_node;
        return; 
    }
    
    while(temp){
        if(temp->data == data){
            free(new_node);
            return;
        }

        if(data < temp->data){
            if(!temp->left){
                temp->left = new_node;
                return;
            }
            temp = temp->left;
        }else{
            if(!temp->right){
                temp->right = new_node;
                return;
            }
            temp = temp->right;
        }
    }
}

void recursive_insert(BST *root, int data){
    Node *temp = *root;
    if(!temp){
        Node *new_node = (Node *) malloc(sizeof(Node));
        if(!new_node) return;

        new_node->data = data;
        new_node->left = new_node->right = NULL;
        *root = new_node;
        return;
    }

    if(data < temp->data) recursive_insert(&temp->left, data);
    else recursive_insert(&temp->right, data);
}

Node *get_left_most(BST root){
    Node *temp = root;
    while(temp && temp->left){
        temp = temp->left;
    }

    return temp;
}

void recursive_delete_node(BST *root, int key){
    if(!*root) return;

    if(key < (*root)->data){
        recursive_delete_node(&(*root)->left, key);
    }else if(key > (*root)->data){
        recursive_delete_node(&(*root)->right, key);
    }else{
        if(!(*root)->left && !(*root)->right){
            free(*root);
            *root = NULL;
            return;
        }else if(!(*root)->left){
            Node *temp = *root;
            *root = (*root)->right;
            free(temp);
            return;
        }else if(!(*root)->right){
            Node *temp = *root;
            *root = (*root)->left;
            free(temp);
            return;
        }else{
            Node *temp = get_left_most((*root)->right);
            (*root)->data = temp->data;
            recursive_delete_node(&(*root)->right, temp->data);
        }
    }

    return;
}

void iterative_delete_node(BST *root, int key){
    if(!*root) return;

    Node *parent = NULL;    
    Node *temp = *root;

    while(temp && temp->data != key){
        parent = temp;
        if(key < temp->data){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }

    if(!temp) return;

    if(!temp->left && !temp->right){
        if(parent){
            if(parent->left == temp) parent->left = NULL;
            else parent->right = NULL;
        }else{
            *root = NULL;
        }
        free(temp);
        return;

    }else if(!temp->left){
        if(parent){
            if(parent->left == temp) parent->left = temp->right;
            else parent->right = temp->right;
        }else{
            *root = temp->right;
        }
        free(temp);
        return;

    }else if(!temp->right){
        if(parent){
            if(parent->left == temp) parent->left = temp->left;
            else parent->right = temp->left;
        }else{
            *root = temp->left;
        }
        free(temp);
        return;
        
    }else{
        Node *successor = temp->right;
        parent = temp;
        while(successor->left){
            parent = successor;
            successor = successor->left;
        }

        temp->data = successor->data;
        if(parent->left == successor) parent->left = successor->right;
        else parent->right = successor->right;

        free(successor);
        return;
    }
}

void recursive_destroy_tree(BST *root){
    if(!*root) return;

    recursive_destroy_tree(&(*root)->left);
    recursive_destroy_tree(&(*root)->right);
    free(*root);
    *root = NULL;
}

void iterative_destroy_tree(BST *root){
    if(!*root) return;

    Stack s;
    init_stack(&s);
    push(&s, *root);

    while(!is_empty_stack(s)){
        Node *temp = pop(&s);
        if(temp->left) push(&s, temp->left);
        if(temp->right) push(&s, temp->right);
        free(temp);
    }

    *root = NULL;
}

int recursive_get_height(BST root){
    if(!root) return 0;

    int leftHeight = recursive_get_height(root->left);
    int rightHeight = recursive_get_height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int iterative_get_height(BST root){
    if(!root) return 0;

    Queue q;
    init_queue(&q);
    enqueue(&q, root);

    int height = 0;
    while(!is_empty_queue(q)){
        int node_count = get_queue_size(q);
        height++;
        for(int i = 0; i < node_count; i++){
            Node *temp = dequeue(&q);
            if(temp->left) enqueue(&q, temp->left);
            if(temp->right) enqueue(&q, temp->right);
        }
    }

    return height;

}


void recursive_inorder_traversal(BST root){
    if(!root) return;

    recursive_inorder_traversal(root->left);
    printf("%d ", root->data);
    recursive_inorder_traversal(root->right);
}

void iterative_inorder_traversal(BST root){
    Stack s;
    init_stack(&s);
    Node *temp = root;
    while(1){
        if(temp){
            push(&s, temp);
            temp = temp->left;
        }else{
            if(is_empty_stack(s)) break;
            Node *node = pop(&s);
            printf("%d ", node->data);
            temp = node->right;
        }
    }

    printf("\n");
}

void recursive_preorder_traversal(BST root){
    if(!root) return;

    printf("%d ", root->data);
    recursive_preorder_traversal(root->left);
    recursive_preorder_traversal(root->right);
}

void iterative_preorder_traversal(BST root){
    if(!root) return;

    Stack s;
    init_stack(&s);
    push(&s, root);

    while(!is_empty_stack(s)){
        Node *temp = pop(&s);
        printf("%d ", temp->data);
        if(temp->right) push(&s, temp->right);
        if(temp->left) push(&s, temp->left);
    }

    printf("\n");
}


void recursive_postorder_traversal(BST root){
    if(!root) return;

    recursive_postorder_traversal(root->left);
    recursive_postorder_traversal(root->right);
    printf("%d ", root->data);
}

void iterative_postorder_traversal(BST root){
    if(!root) return;

    Stack s1, s2;
    init_stack(&s1);
    init_stack(&s2);

    push(&s1, root);
    while(!is_empty_stack(s1)){
        Node *temp = pop(&s1);
        push(&s2, temp);

        if(temp->left) push(&s1, temp->left);
        if(temp->right) push(&s1, temp->right);
    }

    while(!is_empty_stack(s2)){
        Node *temp = pop(&s2);
        printf("%d ", temp->data);
    }

    printf("\n");
}
void level_order_traversal(BST root){
    if(!root) return;

    Queue q;
    init_queue(&q);
    enqueue(&q, root);

    while(!is_empty_queue(q)){
        int node_count = get_queue_size(q);
        for(int i = 0; i < node_count; i++){
            Node *temp = dequeue(&q);
            printf("%d ", temp->data);
            if(temp->left) enqueue(&q, temp->left);
            if(temp->right) enqueue(&q, temp->right);
        }
    }

    printf("\n");
}



int iterative_count_leaf(BST root){
    if(!root) return 0;
    
    Queue q;
    init_queue(&q);

    enqueue(&q, root);
    int count = 0;

    while(!is_empty_queue(q)){
        int node_count = get_queue_size(q);
        for(int i = 0; i < node_count; i++){
            Node *temp = dequeue(&q);
            if(!temp->left && !temp->right) count++;
            if(temp->left) enqueue(&q, temp->left);
            if(temp->right) enqueue(&q, temp->right);
        }
    }


    return count;
}

int recursive_count_leaf(BST root){
    if(!root) return 0;

    if(!root->left && !root->right) return 1;

    return recursive_count_leaf(root->left) + recursive_count_leaf(root->right);
}

int iterative_count_non_leaf(BST root){
    if(!root) return 0;

    Queue q;
    init_queue(&q);

    enqueue(&q, root);

    int count = 0;
    while(!is_empty_queue(q)){
        int node_count = get_queue_size(q);
        for(int i = 0; i < node_count; i++){
            Node *temp = dequeue(&q);
            if(temp->left || temp->right) count++;
            if(temp->left) enqueue(&q, temp->left);
            if(temp->right) enqueue(&q, temp->right);
        }
    }

    return count;
}

int recursive_count_non_leaf(BST root){
    if(!root) return 0;

    if(!root->left && !root->right) return 0;

    return 1 + recursive_count_non_leaf(root->left) + recursive_count_non_leaf(root->right);
}

