#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int size, cap;
    char *arr;
}vector;

void initString(vector* vec, char* str){
    vec->size = 0;
    vec->cap = strlen(str)+1;
    vec->arr = (char*) malloc(sizeof(char) * vec->cap);

    for(int i=0; i<vec->cap; i++){
        vec->arr[i] = str[i]; 
        vec->size++;
    }
}

void resize(vector* vec){
    int newcap = 2 * vec->size;
    char* new_arr = (char*) malloc(sizeof(char) * newcap);

    for(int i=0; i < vec->size; i++)
        new_arr[i] = vec->arr[i];

    vec->cap = newcap;
    free(vec->arr);
    vec->arr = new_arr;
}

void insertItem(vector* vec, int index, int item){
    if(index >= 0 && index <= vec->size){
        if(vec->size == vec->cap)
            resize(vec);

        for(int i = vec->size; i > index; i--){
            vec->arr[i] = vec->arr[i-1];
        }
        vec->arr[index] = item;
        vec->size ++;
    }
}

void concatenate(vector* combined, vector* a, vector* b){
    int i = 0;
    combined->size = 0;
    combined->cap = (a->size + b->size);
    combined->arr = (char*) malloc(sizeof(char) * combined->cap);

    for(i=0; i < a->size-1; i++)
        insertItem(combined, i, a->arr[i]);
    

    for(int j=0; j < b->size; i++,j++)
        insertItem(combined, i , b->arr[j]);
    
}

void slice(vector* sliced, vector* source, int start, int end){
    sliced->cap = end-start;
    sliced->size = 0;
    sliced->arr = (char*) malloc(sizeof(char) * sliced->cap);

    for(int i=start, j=0; i < end; i++, j++)
        insertItem(sliced, j, source->arr[i]);
}

int main(){
    int op, start, end; 
    char temp[15], tamp[15];
    vector a, b, res;
    scanf("%d", &op);

    switch(op){
        case 1:
            scanf("%s %s", &temp, &tamp);
            initString(&a,temp); initString(&b, tamp);
            concatenate(&res,&a,&b);
            printf("%s",res.arr);
            break;

        case 2:
            scanf("%s", &temp);
            scanf("%d %d", &start, &end);
            initString(&a,temp);
            slice(&res, &a, start, end);
            printf("%s", res.arr);
            break;
    }
}