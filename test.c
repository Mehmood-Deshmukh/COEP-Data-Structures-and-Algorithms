#include <stdio.h>
#include <stdlib.h>

int main() {
    int op1, op2, ans;
    char opr1, opr2;
    
    while (1) {
        if (scanf("%d", &op1) == EOF) {
            break;  
        }
\
        if (scanf(" %c", &opr1) == EOF) {
            break; 
        }

        if (opr1 == '<' || opr1 == '>') {
            if (scanf(" %c", &opr2) == EOF || opr2 != opr1) {
                printf("bad opr2\n");
                continue; 
            }
            opr1 = (opr1 == '<') ? 'L' : 'R'; 
        }

        if (scanf("%d", &op2) == EOF) {
            break; 
        }

        if ((opr1 == '%' || opr1 == '/') && op2 == 0) {
            printf("bad op2\n");
            continue; 
        }

        switch (opr1) {
            case '+':
                ans = op1 + op2;
                break;
            case '-':
                ans = op1 - op2;
                break;
            case '*':
                ans = op1 * op2;
                break;
            case '/':
                ans = op1 / op2;
                break;
            case '%':
                ans = op1 % op2;
                break;
            case 'L':  
                ans = op1 << op2;
                break;
            case 'R': 
                ans = op1 >> op2;
                break;
            default:
                printf("bad opr1\n");
                continue; 
        }

        printf("%d\n", ans);
    }

    return 0;
}
