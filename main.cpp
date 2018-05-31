#include "tree_linkedlist.h"

int main()
{
    init();
    mkdir("abc\0");
    mkdir("bbb\0");
    mkdir("bbc\0");
    
    cd("b\t");
    mkdir("a\0");
    mkdir("c\0");
    mkdir("b\0");
    
    cd("..\0");
    cd("\t");
    mkdir("cc\0");
    mkdir("aa\0");
    mkdir("aa\0");
//    CURRENT = CURRENT->next->next;
    cd("..\0");
    cd("bbc\t");
    mkdir("last\0");
    printAll();

    return 0;
}
