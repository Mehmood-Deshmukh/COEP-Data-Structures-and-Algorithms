#include "header.h"

void init(Polynomial *p){
    p->head = NULL;
    p->maxDegree = -1;
}

void append(Polynomial *p, int coefficient, int degree){
    if(coefficient == 0) return;
    
    Node *temp = p->head;
    Node *prev = NULL;

    while(temp && temp->degree >= degree){
        prev = temp;
        temp = temp->next;
    }

    if(prev && prev->degree == degree){
        prev->coefficient += coefficient;
        return;
    }else{
        Node *newNode = (Node *) malloc(sizeof(Node));
        if(!newNode) return;

        newNode->coefficient = coefficient;
        newNode->degree = degree;
        newNode->next = NULL;
        if(!prev){
            newNode->next = p->head;
            p->head = newNode;
        }else{
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }

    if (degree > p->maxDegree) {
        p->maxDegree = degree;
    }
}

void display(Polynomial p){
    Node *temp = p.head;
    
    while(temp){
        if(temp->degree == 0){
            printf("(%d)\n", temp->coefficient);
            return;
        }else if(temp->coefficient == 1){
            if (temp->degree == 1){
                printf("x + ");
            }else{
                printf("x^(%d) + ", temp->degree);
            }

        }else if (temp->degree == 1){
            printf("(%d)x + ", temp->coefficient);
        }else{
            printf("(%d)x^(%d) + ", temp->coefficient, temp->degree);
        }
        temp = temp->next;
    }

    printf("\b\b \n");
}
void getPolynomial(Polynomial *p, int maxDegree){
    int coefficient;
    for(int i = maxDegree; i >= 0; i--){
        printf("Enter Coefficeient of x^(%d)\n", i);
        scanf("%d", &coefficient);
        append(p, coefficient, i);
    }

    return;
}
void randomPolynomial(Polynomial *p, int maxDegree){
    int coefficient;
    for(int i = maxDegree; i >= 0; i--){
        coefficient = rand() % 201 - 100;
        append(p, coefficient, i);
    }

    return;
}

Polynomial add(Polynomial a, Polynomial b){
    Node *temp1 = a.head;
    Node *temp2 = b.head;
    Polynomial *result = (Polynomial *)malloc(sizeof(Polynomial));
    init(result);

    while (temp1 && temp2){
        if (temp1->degree == temp2->degree){
            append(result, temp1->coefficient +temp2->coefficient, temp1->degree);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }else if (temp1->degree > temp2->degree){
            append(result, temp1->coefficient, temp1->degree);
            temp1 = temp1->next;
        }else{
            append(result, temp2->coefficient, temp2->degree);
            temp2 = temp2->next;
        }
    }

    while (temp1){
        append(result, temp1->coefficient, temp1->degree);
        temp1 = temp1->next;
    }
    
    while (temp2){
        append(result, temp2->coefficient, temp2->degree);
        temp2 = temp2->next;
    }

    

    return *result;
}
Polynomial substract(Polynomial a, Polynomial b){
    Node *temp1 = a.head;
    Node *temp2 = b.head;
    Polynomial *result = (Polynomial *)malloc(sizeof(Polynomial));
    init(result);

    while (temp1 && temp2){
        if (temp1->degree == temp2->degree){
            append(result, temp1->coefficient - temp2->coefficient, temp1->degree);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }else if (temp1->degree > temp2->degree){
            append(result, temp1->coefficient, temp1->degree);
            temp1 = temp1->next;
        }else{
            append(result, -temp2->coefficient, temp2->degree);
            temp2 = temp2->next;
        }
    }

    while (temp1){
        append(result, temp1->coefficient, temp1->degree);
        temp1 = temp1->next;
    }
    
    while (temp2){
        append(result, -temp2->coefficient, temp2->degree);
        temp2 = temp2->next;
    }

    return *result;
}
Polynomial multiply(Polynomial a, Polynomial b){
    Node *temp1 = a.head;
    Node *temp2 = b.head;
    Polynomial *result = (Polynomial *)malloc(sizeof(Polynomial));
    init(result);    

    while (temp1){
        temp2 = b.head;
        while (temp2){
            append(result, temp1->coefficient * temp2->coefficient, temp1->degree + temp2->degree);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;   
    }

    return *result;
}
