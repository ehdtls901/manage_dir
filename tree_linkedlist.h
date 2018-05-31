#ifndef __TREE_LINKEDLIST_H__
#define __TREE_LINKEDLIST_H__

typedef struct _dir{
    char name[13];
    int numOfDescendants;
    struct _dir* parent;
    struct _dir* HEAD;
    struct _dir* TAIL;
    struct _dir* prev;
    struct _dir* next;
}DIR;

int mystrcmp(const char* first, const char* second);
int mystrncmp(const char* first, const char* second, const int n);
void mystrcpy(char* dest, const char* src);
void mystrncpy(char* dest, const char* src, const int n);


void init();
void mkdir(char keyword[13]);
int rmdir(char keyword[13]);
void cd(char keyword[13]);
int find(char keyword[13]);
void printAll();

#endif
