#include "logic.c"

int main(){
    Ascii l1;
    initAscii(&l1);
    asciiOf(&l1, 'A');
    traverse(l1);
    destroy(&l1);
    traverse(l1); // should not print anything
    Ascii l2;
    initAscii(&l2);
    asciiOf(&l2, 'a');
    traverse(l2);
    destroy(&l2);
    traverse(l2); //should not print anything

    return 0;
}