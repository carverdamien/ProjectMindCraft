#ifndef _BOT_H_
#define _BOT_H_

#include <mindcraft/types.h>
#include <mindcraft/game0/physics.h>

enum bot_action_t {
	BOT_WAIT,
	BOT_WALK,
	BOT_TURN_RIGHT,
	BOT_TURN_LEFT,
	BOT_NR_ACTION,
} __attribute__ ((__packed__));
ASSERT(sizeof(enum bot_action_t) == 1);

enum bot_error_t {
	BOT_SUCCESS,
	BOT_PHYSICS_ERROR,
} __attribute__ ((__packed__));
ASSERT(sizeof(enum bot_error_t) == 1);

enum bot_reaction_t {
	BOT_IDLE,
	BOT_MOVE_FORWARD_SUCCEEDED,
	BOT_MOVE_FORWARD_FAILED_COLLISION_AT_EDGE,
	BOT_MOVE_FORWARD_FAILED_COLLISION_AT_CENTER,
	BOT_ROTATE_LEFT,
	BOT_ROTATE_RIGHT,
	BOT_NR_REACTION,
} __attribute__ ((__packed__));
ASSERT(sizeof(enum bot_reaction_t) == 1);

enum bot_orientation_t {
	EAST,
	NORTH,
	WEST,
	SOUTH,
} __attribute__ ((__packed__));
ASSERT(sizeof(enum bot_orientation_t) == 1);

enum visible_object_t {
	VISIBLE_OBJECT_UNKNOWN,
	VISIBLE_OBJECT_NONE,
	VISIBLE_OBJECT_BOT, // Orientation unknown
	VISIBLE_OBJECT_BOT_FACING_EAST,
	VISIBLE_OBJECT_BOT_FACING_NORTH,
	VISIBLE_OBJECT_BOT_FACING_WEST,
	VISIBLE_OBJECT_BOT_FACING_SOUTH,
	VISIBLE_OBJECT_METEORITE,
} __attribute__ ((__packed__));
ASSERT(sizeof(enum visible_object_t) == 1);

/*

+------------+-------+-------------+
| LEFT_AHEAD | AHEAD | RIGHT_AHEAD |
+------------+-------+-------------+
| FRONT_LEFT | FRONT | FRONT_RIGHT |
+------------+-------+-------------+
| LEFT       |  BOT  |       RIGHT |
+------------+-------+-------------+

        Bot's field of view
        -------------------
*/

enum field_of_view_t {
	LEFT,
	FRONT_LEFT,
	FRONT,
	FRONT_RIGHT,
	RIGHT,
	LEFT_AHEAD,
	AHEAD,
	RIGHT_AHEAD,
	NR_FIELD_OF_VIEW,
} __attribute__ ((__packed__));
ASSERT(sizeof(enum field_of_view_t) == 1);

struct bot_read_only_t {
	struct physics_t physics;
	enum bot_orientation_t orientation;
	enum bot_reaction_t    reaction;
	enum bot_error_t       error;
	// Objects visible by the bot
	enum visible_object_t  object[NR_FIELD_OF_VIEW];
};

struct bot_read_write_t {
	enum bot_action_t action;
	int32_t           random;
	char              storage[1024];
};

struct bot_t {
	struct bot_read_only_t  r;
	struct bot_read_write_t rw;
};

#endif /* _BOT_H_ */
