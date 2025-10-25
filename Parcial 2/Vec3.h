#ifndef VEC3_H
#define VEC3_H

typedef struct strVec3* Vec3;

Vec3 vec3_create(float x, float y, float z);

void vec3_destroy(Vec3 v);

void vec3_setX(Vec3 v, float x);

void vec3_setY(Vec3 v, float y);

void vec3_setZ(Vec3 v, float z);

void vec3_print(Vec3 v);

float vec3_getX(Vec3 v);

float vec3_getY(Vec3 v);

float vec3_getZ(Vec3 v);

#endif



