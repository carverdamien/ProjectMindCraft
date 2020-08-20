#ifndef _BOT_H_
#define _BOT_H_

#include <mindcraft/types.h>
#include <mindcraft/game0/physics.h>

/*
enum bot_action_t:
The value is written by the bot's program.
The value is read by compute_interactions and compute_physics.

Dev Notes:
The value is also written by unittests.
The value is also read by apply_reaction.
*/

enum bot_action_t {

	/* Interactions */
	BOT_ACTION_HARVEST,
	/* Future Interactions */
	// BOT_ACTION_BUILD
	// BOT_ACTION_REPAIR
	// BOT_ACTION_ATTACK
	// BOT_ACTION_DEFEND
	// BOT_ACTION_DODGE
	// BOT_ACTION_HELP

	/* Physics */
	BOT_ACTION_WAIT,
	BOT_ACTION_WALK,
	BOT_ACTION_TURN_RIGHT,
	BOT_ACTION_TURN_LEFT,
	/* Future Physics */
	// BOT_ACTION_HOVER
	// BOT_ACTION_LAND
	// BOT_ACTION_SUBMERGE
	// BOT_ACTION_SURFACE

	/* Total */
	NR_BOT_ACTION,

	/* Deprecated Symbols */
	BOT_WAIT = BOT_ACTION_WAIT,
	BOT_WALK = BOT_ACTION_WALK,
	BOT_TURN_RIGHT = BOT_ACTION_TURN_RIGHT,
	BOT_TURN_LEFT = BOT_ACTION_TURN_LEFT,
	BOT_NR_ACTION = NR_BOT_ACTION,

} __attribute__ ((__packed__));
ASSERT(sizeof(enum bot_action_t) == 1);

/*
enum bot_error_t:
The value is reset to SUCESS by prepare_bots.
The value is written by compute_interactions and compute_physics.
The value can be read by the bot's program.
*/

enum bot_error_t {
	BOT_SUCCESS,
	BOT_INTERACTIONS_ERROR,
	BOT_PHYSICS_ERROR,
} __attribute__ ((__packed__));
ASSERT(sizeof(enum bot_error_t) == 1);

/*
enum bot_reaction_t:
These values correspond to the animations displayed in the unity client.
*/

enum bot_reaction_t {

	BOT_REACTION_IDLE,
	BOT_REACTION_MOVE_FORWARD_SUCCEEDED,
	BOT_REACTION_MOVE_FORWARD_FAILED_COLLISION_AT_EDGE,
	BOT_REACTION_MOVE_FORWARD_FAILED_COLLISION_AT_CENTER,
	BOT_REACTION_ROTATE_LEFT,
	BOT_REACTION_ROTATE_RIGHT,
	BOT_REACTION_HARVEST_SUCCEEDED,
	BOT_REACTION_HARVEST_FAILED,
	NR_BOT_REACTION,

	/* Deprecated Symbols */
	BOT_IDLE = BOT_REACTION_IDLE,
	BOT_MOVE_FORWARD_SUCCEEDED = BOT_REACTION_MOVE_FORWARD_SUCCEEDED,
	BOT_MOVE_FORWARD_FAILED_COLLISION_AT_EDGE = BOT_REACTION_MOVE_FORWARD_FAILED_COLLISION_AT_EDGE,
	BOT_MOVE_FORWARD_FAILED_COLLISION_AT_CENTER = BOT_REACTION_MOVE_FORWARD_FAILED_COLLISION_AT_CENTER,
	BOT_ROTATE_LEFT = BOT_REACTION_ROTATE_LEFT,
	BOT_ROTATE_RIGHT = BOT_REACTION_ROTATE_RIGHT,
	BOT_NR_REACTION = NR_BOT_REACTION,

} __attribute__ ((__packed__));
ASSERT(sizeof(enum bot_reaction_t) == 1);

enum bot_orientation_t {
	BOT_ORIENTATION_EAST,
	BOT_ORIENTATION_NORTH,
	BOT_ORIENTATION_WEST,
	BOT_ORIENTATION_SOUTH,

	/* Deprecated Symbols */
	EAST = BOT_ORIENTATION_EAST,
	NORTH = BOT_ORIENTATION_NORTH,
	WEST = BOT_ORIENTATION_WEST,
	SOUTH = BOT_ORIENTATION_SOUTH,

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

	FIELD_OF_VIEW_LEFT,
	FIELD_OF_VIEW_FRONT_LEFT,
	FIELD_OF_VIEW_FRONT,
	FIELD_OF_VIEW_FRONT_RIGHT,
	FIELD_OF_VIEW_RIGHT,
	FIELD_OF_VIEW_LEFT_AHEAD,
	FIELD_OF_VIEW_AHEAD,
	FIELD_OF_VIEW_RIGHT_AHEAD,
	NR_FIELD_OF_VIEW,

	/* Deprecated Symbols */
	LEFT = FIELD_OF_VIEW_LEFT,
	FRONT_LEFT = FIELD_OF_VIEW_FRONT_LEFT,
	FRONT = FIELD_OF_VIEW_FRONT,
	FRONT_RIGHT = FIELD_OF_VIEW_FRONT_RIGHT,
	RIGHT = FIELD_OF_VIEW_RIGHT,
	LEFT_AHEAD = FIELD_OF_VIEW_LEFT_AHEAD,
	AHEAD = FIELD_OF_VIEW_AHEAD,
	RIGHT_AHEAD = FIELD_OF_VIEW_RIGHT_AHEAD,

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
