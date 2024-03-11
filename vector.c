#include "vector.h"
#include <stdlib.h>

Vector *vector_create(void) {
    Vector *vector = malloc(sizeof(Vector));
    if (vector == NULL) {
        return NULL;
    }
    vector->size = 0;
    vector->capacity = VECTOR_INITIAL_CAPACITY;
    vector->data = malloc(sizeof(double) * vector->capacity);
    if (vector->data == NULL) {
        free(vector);
        return NULL;
    }
    return vector;
}

void vector_push(Vector *vector, double element) {
    if (vector == NULL) {
        return;
    }

    if (vector->size == vector->capacity) {
        vector->capacity *= 2;
        double *new_data = realloc(vector->data, sizeof(double) * vector->capacity);
        if (new_data == NULL) {
            return;
        }
        vector->data = new_data;
    }
    vector->data[vector->size++] = element;
}

double vector_get(const Vector *vector, int index) {
    if (vector == NULL) {
        return 0.0;
    }
    if (index < 0 || index >= vector->size) {
        return 0.0;
    }
    if (vector->data[index] == 0.0) {
        return 0.0;
    }
    return vector->data[index];
}


void vector_free(Vector *vector) {
    if (vector == NULL) {
        return;
    }
    free(vector->data);
    free(vector);
}


