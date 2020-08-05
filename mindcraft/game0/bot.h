enum bot_action_t {
	BOT_WAIT,
	BOT_WALK,
	BOT_TURN_RIGHT,
	BOT_TURN_LEFT,
	BOT_NR_ACTION,
};

enum bot_error_t {
	BOT_SUCCESS,
	BOT_VS_BOT_COLLISION,
	BOT_VS_BOT_COLLISION_2_CYLE,
	BOT_COLLISION,
};

enum bot_reaction_t {
	BOT_IDLE,
	BOT_MOVE_FORWARD_SUCCEEDED,
	BOT_MOVE_FORWARD_FAILED_COLLISION_AT_EDGE,
	BOT_MOVE_FORWARD_FAILED_COLLISION_AT_CENTER,
	BOT_ROTATE_LEFT,
	BOT_ROTATE_RIGHT,
	BOT_NR_REACTION,
};

enum bot_orientation_t {
	EAST,
	NORTH,
	WEST,
	SOUTH,
};

enum object_visible_t {
	OBJECT_UNKNOWN,
	OBJECT_NONE,
	OBJECT_BOT, // Orientation unknown
	OBJECT_BOT_FACING_EAST,
	OBJECT_BOT_FACING_NORTH,
	OBJECT_BOT_FACING_WEST,
	OBJECT_BOT_FACING_SOUTH,
};

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
};

struct bot_read_only_t {
	int64_t  positionx;
	int64_t  positiony;
	int64_t  positionz;
	enum bot_orientation_t orientation;
	enum bot_reaction_t    reaction;
	enum bot_error_t       error;
	// Objects visible by the bot
	enum object_visible_t  object[NR_FIELD_OF_VIEW];
};

struct bot_read_only_t {
	int64_t  positionx;
	int64_t  positiony;
	int64_t  positionz;
	enum bot_orientation_t orientation;
	enum bot_reaction_t    reaction;
	enum bot_error_t       error;
	// Objects visible by the bot
	enum object_visible_t  object[NR_FIELD_OF_VIEW];
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
