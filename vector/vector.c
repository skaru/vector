#include "vector.h"

void insert(PVECTOR vec, void* data, unsigned int i) {
    memcpy(&vec->data[i * vec->indexSize], &data, vec->indexSize);
}

void push(PVECTOR vec, void* data) {
    char* newData = malloc((vec->size + 1) * vec->indexSize);
    if (newData == NULL) {
        return;
    }
    memcpy(newData, &data, vec->indexSize);

    if (vec->size++ != 0) {
        memcpy(&newData[vec->indexSize], vec->data, vec->size * vec->indexSize);
        free(vec->data);
    }

    vec->data = newData;
}

void push_back(PVECTOR vec, void* data) {
    char* newData = malloc((vec->size + 1) * vec->indexSize);
    if (newData == NULL) {
        return;
    }
    if (vec->size != 0) {
        memcpy(newData, vec->data, vec->size * vec->indexSize);
        free(vec->data);
    }

    memcpy(&newData[vec->size++ * vec->indexSize], &data, vec->indexSize);
    vec->data = newData;
}

void pop_back(PVECTOR vec) {
    char* newData = malloc(--vec->size * vec->indexSize);
    if (newData == NULL) {
        return;
    }
    memcpy(newData, vec->data, vec->size * vec->indexSize);
    free(vec->data);
    vec->data = newData;
}

void* at(PVECTOR vec, unsigned int i) {
    int index = i * vec->indexSize;
    switch (vec->datatype)
    {
    case INT:
        return *(int*)&vec->data[index];
        break;
    case SHORT:
        return *(short int*)&vec->data[index];
        break;
    case CHAR:
        return vec->data[index];
        break;
    }

}

PVECTOR initVector(unsigned int datatype) {
    PVECTOR vec = (PVECTOR)malloc(sizeof(VECTOR));
    if (vec == NULL) {
        return vec;
    }
    vec->size = 0;
    switch (datatype) {
    case INT:
        vec->indexSize = sizeof(int);
        vec->datatype = INT;
        break;
    case SHORT:
        vec->indexSize = sizeof(short);
        vec->datatype = SHORT;
        break;
    case CHAR:
        vec->indexSize = sizeof(char);
        vec->datatype = CHAR;
        break;
    }
    return vec;
}

void freeVector(PVECTOR vec) {
    free(vec->data);
    free(vec);
}

void clear(PVECTOR vec) {
    free(vec->data);
}