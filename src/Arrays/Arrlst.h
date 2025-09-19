#ifndef MArray_H
#define MArray_H


 typedef struct {

     int capacity;
    int nameSize;
     char ** arrList;
    int quantity;
    int index;

} MArray;


// Starting and managing the list
MArray *ManArray_initList(void);

MArray *ManArray_customInit(int listSize, int nameSize);

// Managing objects in the list
void ManArray_addItem(MArray ** list, const char * item);
void ManArray_removeItem(MArray ** list, char * Item, int index);
void ManArray_removeLastItem(MArray ** list);

// Showing itens in the list
void ManArray_printIndex(MArray ** list,int index);
void ManArray_printItem(MArray ** list, const char * item);
void ManArray_printAll(MArray ** list);

// Getters for using in other functions

char *ManArray_getItem(MArray ** list, int index);

#endif
