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

struct bot_read_only_t {
	int64_t  positionx;
	int64_t  positiony;
	int64_t  positionz;
	enum bot_orientation_t orientation;
	enum bot_reaction_t    reaction;
	enum bot_error_t       error;
	// TODO: objects around bot
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
