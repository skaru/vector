#include "vector.h"
#include "stdio.h"

int main(void) {
    PVECTOR intVec = initVector(INT);
    if (intVec == NULL) {
        return 0;
    }

    push(intVec, 1010);
    push_back(intVec, 13);
    insert(intVec, 14, 1);
    pop_back(intVec);

    for (int i = 0; i < intVec->size; i++) {
        printf("%d\n", at(intVec, i));
    }

    freeVector(intVec);

    return 0;
}