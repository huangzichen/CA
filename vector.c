#include "vector.h"
#include <stdlib.h>

Vector *vector_create(void) {
    Vector *vector = malloc(sizeof(Vector));
    if (vector == NULL) {
        printf("Failed to allocate memory for vector structure\n");
        return NULL;
    }
    vector->size = 0;
    vector->capacity = VECTOR_INITIAL_CAPACITY;
    vector->data = malloc(sizeof(double) * vector->capacity);
    if (vector->data == NULL) {
        printf("Failed to allocate memory for data\n");
        free(vector);
        return NULL;
    }
    return vector;
}

void vector_push(Vector *vector, double element) {
    if (vector == NULL) {
        printf("Invalid vector pointer\n");
        return;
    }

    if (vector->size == vector->capacity) {
        vector->capacity *= 2;
        double *new_data = realloc(vector->data, sizeof(double) * vector->capacity);
        if (new_data == NULL) {
            printf("Failed to reallocate memory for data\n");
            return;
        }
        vector->data = new_data;
    }
    vector->data[vector->size++] = element;
}

double vector_get(const Vector *vector, int index) {
    if (vector == NULL) {
        printf("Invalid vector pointer\n");
        return 0.0;
    }
    if (index < 0 || index >= vector->size) {
        printf("Invalid index\n");
        return 0.0;
    }
    if (vector->data[index] == 0.0) {
        printf("Uninitialized element at index %d\n", index);
        return 0.0; //
    }
    return vector->data[index];
}


void vector_free(Vector *vector) {
    if (vector == NULL) {
        printf("Invalid vector pointer\n");
        return;
    }
    free(vector->data);
    free(vector);
}

