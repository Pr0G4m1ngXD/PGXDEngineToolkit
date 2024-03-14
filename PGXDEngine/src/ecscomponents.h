#include "raylib.h"
#include <stdint.h>
#include <stdbool.h>

typedef struct transform {
    uint64_t entity;
    Vector3 pos;
    Vector3 scale;
    Quaternion quat;
} transform_s;

typedef struct health {
    uint64_t entity;
    uint16_t maxhelth;
    uint16_t health;
    uint16_t restoreRate;
    bool isDamagable;
} health_s;

typedef enum ctype {
    CTransform,
    CHealth,
} ctype_e;

typedef struct componentlist {
    transform_s** trans; uint64_t transAmount;
    health_s** health;   uint64_t healthAmount;
} componentlist_s;
