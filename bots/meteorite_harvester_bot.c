#include <mindcraft/game0/bot.h>
#include <mindcraft/game0/rng.h>

#define RRANGE 10000

static __attribute__((always_inline))
bool meteorite_in_front(struct bot_t *bot)
{
	return bot->r.object[FRONT] == VISIBLE_OBJECT_METEORITE;
}

uint64_t meteorite_harvester_bot(struct bot_t *bot) {

  /* Coding Challenge:
   * Improve the harvesting efficiency
   */

	uint32_t r = ((uint32_t) rng(&bot->rw.random)) % (RRANGE*10);

	if (meteorite_in_front(bot)) {
		bot->rw.action = BOT_ACTION_HARVEST;
		return 0;
	}

	if (r < (RRANGE*5) ) {
		bot->rw.action = BOT_WALK;
		return 0;
	}
	if (r < (RRANGE*7)) {
		bot->rw.action = BOT_TURN_LEFT;
		return 0;
	}
	if (r < (RRANGE*9)) {
		bot->rw.action = BOT_TURN_RIGHT;
		return 0;
	}
	bot->rw.action =  BOT_WAIT;
	return 0;
}
