#include <stdio.h>
#include <stdlib.h>

#include "Vec3.h"

struct strVec3{
    float x, y, z;
};

Vec3 vec3_create(float x, float y, float z){

    Vec3 v = malloc(sizeof(struct strVec3));
    if (v == NULL) {
        printf("Error: no se pudo asignar memoria para Vec3\n");
        return 0;
    }
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
};

void vec3_destroy(Vec3 v){
    free(v);
    printf("Vector destroyed\n");
};

void vec3_setX(Vec3 v, float x){
    v->x = x;
    printf("Value %f asigned to vector at x\n", x);
};

void vec3_setY(Vec3 v, float y){
    v->y = y;
    printf("Value %f asigned to vector at y\n", y);
};

void vec3_setZ(Vec3 v, float z){
    v->z = z;
    printf("Value %f asigned to vector at z\n", z);
};

float vec3_getX(Vec3 v){
    return v->x;
}

float vec3_getY(Vec3 v) {
    return v->y;
}

float vec3_getZ(Vec3 v) {
    return v->z;
}

void vec3_print(Vec3 v) {
    printf("(%.2f, %.2f, %.2f)\n", v->x, v->y, v->z);
}

