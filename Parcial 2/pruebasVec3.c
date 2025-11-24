#include <stdio.h>
#include <stdlib.h>
#include "Vec3.h"

int main() {
    Vec3 v1 = vec3_create(1.0, 2.0, 3.0);
    vec3_print(v1);

    vec3_setX(v1, 5.0);
    vec3_setY(v1, 10.0);
    vec3_setZ(v1, 15.0);

    printf("Valores modificados: ");
    vec3_print(v1);

    printf("Componente X actual: %.2f\n", vec3_getX(v1));

    //vec3_destroy(v1);
    return 0;
}