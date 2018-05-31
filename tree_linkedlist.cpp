#include <iostream>
#include <malloc.h>
#include "tree_linkedlist.h"

using namespace std;

DIR* ROOT;
DIR* CURRENT;

int mystrcmp(const char* first, const char* second)
{
    int i = 0;
    while(first[i] != '\0'){
        if(first[i] != second[i]) return first[i]-second[i];
        i++;
    }
    return first[i]-second[i];
}

int mystrncmp(const char* first, const char* second, const int n)
{
    int i;
    for(i=0;i<n;i++){
        if(first[i] != second[i]) return first[i]-second[i];
    }
    return 0;
}

void mystrcpy(char* dest, const char* src)
{
    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
}

void mystrncpy(char* dest, const char* src, const int n)
{
    for(int i=0;i<n;i++){
        dest[i] = src[i];
    }
}


void init()
{
    if(ROOT != (DIR*)0) free(ROOT);

    ROOT = (DIR*)calloc(1, sizeof(DIR));
    mystrcpy(ROOT->name, "/\0");
    ROOT->numOfDescendants = 0;
    ROOT->parent = (DIR*)0;
    ROOT->HEAD = (DIR*)calloc(1, sizeof(DIR));
    ROOT->TAIL = (DIR*)calloc(1, sizeof(DIR));
    ROOT->HEAD->next = ROOT->TAIL;
    ROOT->TAIL->prev = ROOT->HEAD;
    ROOT->prev = (DIR*)0;
    ROOT->next = (DIR*)0;

    CURRENT = ROOT;
}

void mkdir(char keyword[13])
{
    DIR* temp = CURRENT->HEAD->next;
    int n = 0;
    while(temp != CURRENT->TAIL){
        if(!mystrcmp(temp->name, keyword)) return;
        if(mystrcmp(temp->name, keyword) > 0) break;
        temp = temp->next;
    }
    DIR* newDIR = (DIR*)calloc(1, sizeof(DIR));
    mystrcpy(newDIR->name, keyword);
    newDIR->numOfDescendants = 0;
    newDIR->parent = CURRENT;
    newDIR->HEAD = (DIR*)calloc(1, sizeof(DIR));
    newDIR->TAIL = (DIR*)calloc(1, sizeof(DIR));
    newDIR->HEAD->next = newDIR->TAIL;
    newDIR->TAIL->prev = newDIR->HEAD;
    
    newDIR->prev = temp->prev;
    newDIR->next = temp;

    temp->prev->next = newDIR;
    temp->prev = newDIR;
    
    temp = newDIR;
    while(temp != ROOT){
        temp = temp->parent;
        temp->numOfDescendants++;
    }
    return;
}

int rmdir(char keyword[13])
{
    int ret = 0;

    return ret;
}

void cd(char keyword[13])
{
    DIR* temp;
    int num = 0;
    if(!mystrncmp(keyword, "/\0", 1)){
        CURRENT = ROOT;
        return;
    } 
    if(!mystrncmp(keyword, "..\0", 2)){
        CURRENT = CURRENT->parent;
        return;
    }
    if(CURRENT->numOfDescendants == 0) return;
    while(keyword[num] != '\t') num++;
    if(num == 0){
        CURRENT = CURRENT->HEAD->next;
        return;
    }
    temp = CURRENT->HEAD->next;
    while(mystrncmp(temp->name, keyword, num)){
        temp = temp->next;  
        if(temp == temp->parent->TAIL) return;
    }
    CURRENT = temp;
}

int find(char keyword[13])
{
    int ret = 0;

    return ret;
}

void printAll()
{
    DIR* temp = ROOT;
    int level = 0;
    while(true){
        for(int i=0;i<level;i++) cout << " ";
        cout << "- " << temp->name << endl;
        if(temp->numOfDescendants > 0){
            temp = temp->HEAD->next;
            level++;        
            continue;
        }else if(temp->next != temp->parent->TAIL){
            temp = temp->next;
            continue;
        }else{
cleanup:
            temp = temp->parent;
            level--;
            if(temp == ROOT) break;
            if(temp->next != temp->parent->TAIL) temp = temp->next;
            else goto cleanup;
        }
    }
}
