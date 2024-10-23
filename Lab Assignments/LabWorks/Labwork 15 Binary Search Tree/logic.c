#include "header.h"


void init(BST *b){
    b->array = (int *)malloc(sizeof(int) * SIZE);
    b->size = SIZE;

    for(int i = 0; i < SIZE; i++){
        b->array[i] = INT_MIN;
    }
}

void insert(BST *b, int data){
    int i = 0;
    while(1){
        if(b->array[i] == INT_MIN){
            b->array[i] = data;
            return;
        }

        if(b->array[i] == data){
            return;
        }

        if(b->array[i] > data){
            i = 2 * i + 1;
        }else{
            i = 2 * i + 2;
        }
    }
    
}

void recursiveInsertHelper(int arr[], int index, int size, int data){
    if(index >= size){
        return;
    }

    if(arr[index] == INT_MIN){
        arr[index] = data;
        return;
    }

    if(arr[index] == data){
        return;
    }

    if(arr[index] > data){
        recursiveInsertHelper(arr, 2 * index + 1, size, data);
    }else{
        recursiveInsertHelper(arr, 2 * index + 2, size, data);
    }
}

void recursiveInsert(BST *b, int data){
    recursiveInsertHelper(b->array, 0, b->size, data);
}

void inorderTraversalHelper(int arr[], int index, int size){
    if(index >= size || arr[index] == INT_MIN) return;
    inorderTraversalHelper(arr, 2 * index + 1, size);
    printf("%d, ", arr[index]);
    inorderTraversalHelper(arr, 2 * index + 2, size);
}

void inorderTraversal(BST b){
    printf("Inorder Traversal: [ ");
    inorderTraversalHelper(b.array, 0, b.size);
    printf("\b\b ]\n");
}

void preorderTraversalHelper(int arr[], int index, int size){
    if(index >= size || arr[index] == INT_MIN) return;
    printf("%d, ", arr[index]);
    preorderTraversalHelper(arr, 2 * index + 1, size);
    preorderTraversalHelper(arr, 2 * index + 2, size);
}

void preorderTraversal(BST b){
    printf("Preorder Traversal: [ ");
    preorderTraversalHelper(b.array, 0, b.size);
    printf("\b\b ]\n");
}


void postorderTraversalHelper(int arr[], int index, int size){
    if(index >= size || arr[index] == INT_MIN) return;
    postorderTraversalHelper(arr, 2 * index + 1, size);
    postorderTraversalHelper(arr, 2 * index + 2, size);
    printf("%d, ", arr[index]);
}

void postorderTraversal(BST b){
    printf("Postorder Traversal: [ ");
    postorderTraversalHelper(b.array, 0, b.size);
    printf("\b\b ]\n");
}

int countLeafNodes(BST b){
    if(b.array[0] == INT_MIN) return 0;

    int count = 0;
    Queue q;
    qinit(&q);
    enQueue(&q, 0);

    while(!isEmpty(q)){
        int size = getSize(q);
        while(size--){
            int index = deQueue(&q);
            if((2*index + 1 >= b.size || b.array[2 * index + 1] == INT_MIN ) && (2*index + 2 >= b.size || b.array[2 * index + 2] == INT_MIN)){
                count++;
            }else{
                if(2*index + 1 < b.size && b.array[2 * index + 1] != INT_MIN) enQueue(&q, 2 * index + 1);
                if(2*index + 2 < b.size && b.array[2 * index + 2] != INT_MIN) enQueue(&q, 2 * index + 2);
            }
        }
    }

    return count;
}

int countNonLeafNodes(BST b){
    if(b.array[0] == INT_MIN) return 0;

    int count = 0;
    Queue q;
    qinit(&q);
    enQueue(&q, 0);

    while(!isEmpty(q)){
        int size = getSize(q);
        while(size--){
            int index = deQueue(&q);
            if((2*index + 1 >= b.size || b.array[2 * index + 1] == INT_MIN ) && (2*index + 2 >= b.size || b.array[2 * index + 2] == INT_MIN)){
                continue;
            }else{
                count++;
                if(2*index + 1 < b.size && b.array[2 * index + 1] != INT_MIN) enQueue(&q, 2 * index + 1);
                if(2*index + 2 < b.size && b.array[2 * index + 2] != INT_MIN) enQueue(&q, 2 * index + 2);
            }
        }
    }

    return count;
}

int recursiveHeightHelper(int arr[], int index, int size){
    if(index >= size || arr[index] == INT_MIN) return 0;
    int left = recursiveHeightHelper(arr, 2 * index + 1, size);
    int right = recursiveHeightHelper(arr, 2 * index + 2, size);
    return 1 + (left > right ? left : right);
}

int recursiveHeight(BST b){
    return recursiveHeightHelper(b.array, 0, b.size);
}

int iterativeHeight(BST b){
    int height = 0;

    if(b.array[0] == INT_MIN) return height;

    Queue q;
    qinit(&q);
    enQueue(&q, 0);

    while(!isEmpty(q)){
        height++;
        int size = getSize(q);

        while(size--){
            int index = deQueue(&q);
            if(2*index + 1 < b.size && b.array[2 * index + 1] != INT_MIN) enQueue(&q, 2 * index + 1);
            if(2*index + 2 < b.size && b.array[2 * index + 2] != INT_MIN) enQueue(&q, 2 * index + 2);
        }

    }

    return height;
}