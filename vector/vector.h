#pragma once

#include <stdlib.h>
#include <string.h>

typedef struct _VECTOR {
    char* data;
    size_t size;
    size_t indexSize;
    int datatype;
} VECTOR, * PVECTOR;

enum _VECTOR_OPTIONS {
    INT,
    CHAR,
    SHORT
};

PVECTOR initVector(unsigned int datatype);
void push(PVECTOR vec, void* data);
void push_back(PVECTOR vec, void* data);
void insert(PVECTOR vec, void* data, unsigned int i);
void pop_back(PVECTOR vec);
void clear(PVECTOR vec);
void freeVector(PVECTOR vec);
void* at(PVECTOR vec, unsigned int i);