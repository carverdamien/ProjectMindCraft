#ifndef _PHYSICS_H_
#define _PHYSICS_H_

#include <mindcraft/types.h>

enum sign_t {
	NEGATIVE = -1,
	ZERO = 0,
	POSITIVE = 1,
} __attribute__ ((__packed__));
ASSERT(sizeof(enum sign_t) == 1);

struct vec3_int64_t {
	int64_t x;
	int64_t y;
	int64_t z;
};

#define PHYSICS_VEC_INT(X,Y,Z) ({struct vec3_int64_t p = {.x=X,.y=Y,.z=Z}; p;})

struct vec3_sign_t {
	enum sign_t x; /* dx */
	enum sign_t y; /* dy */
	enum sign_t z; /* dz */
};

#define PHYSICS_SPEED(X,Y,Z) ({struct vec3_sign_t speed = {.x=X,.y=Y,.z=Z}; speed;})
#define PHYSICS_SPEED_NULL   PHYSICS_SPEED(     ZERO, ZERO,     ZERO)
#define PHYSICS_SPEED_EAST   PHYSICS_SPEED( POSITIVE, ZERO,     ZERO)
#define PHYSICS_SPEED_NORTH  PHYSICS_SPEED(     ZERO, ZERO, POSITIVE)
#define PHYSICS_SPEED_WEST   PHYSICS_SPEED( NEGATIVE, ZERO,     ZERO)
#define PHYSICS_SPEED_SOUTH  PHYSICS_SPEED(     ZERO, ZERO, NEGATIVE)

#define PHYSICS_VEC_EQUALS(A,B) ((A).x == (B).x && (A).y == (B).y && (A).z == (B).z)
#define PHYSICS_VEC_ADD(S,A,B) \
do { \
	(S).x = (A).x + (B).x; \
	(S).y = (A).y + (B).y; \
	(S).z = (A).z + (B).z; \
} while(0)

enum collision_status_t {
	COLLISION_NONE,            /* No collision */
	COLLISION_DYNAMIC,         /* Collision with another object that can move */
	COLLISION_DYNAMIC_2_CYCLE, /* Collision with another moving object that wants to move to our place */
	COLLISION_STATIC,          /* Collision with another object that cannot move */
} __attribute__ ((__packed__));
ASSERT(sizeof(enum collision_status_t) == 1);

struct collision_t {
	enum collision_status_t status;
	struct vec3_int64_t position; /* Position of the object we collide with */
};

struct physics_t {
	struct vec3_int64_t position;
	struct vec3_int64_t rotation;
	struct vec3_sign_t  speed;
	struct collision_t  collision;
	uint64_t            index;      /* Internal use only, should not leak to players */
};

#define PHYSICS_POSITION(X,Y,Z) PHYSICS_VEC_INT(X,Y,Z)
#define PHYSICS_ROTATION(X,Y,Z) PHYSICS_VEC_INT(X,Y,Z)

#endif /* _PHYSICS_H_ */
