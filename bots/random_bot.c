#include<mindcraft/game0/bot.h>
#include<mindcraft/game0/rng.h>

#define RRANGE 1000

uint64_t random_bot(struct bot_t *bot) {
	uint32_t r = ((uint32_t) rng(&bot->rw.random)) % (RRANGE*100);

	if (r < (RRANGE*50) ) {
		/* 50% */
		bot->rw.action = BOT_ACTION_WALK;
		return 0;
	}
	if (r < (RRANGE*70)) {
		/* 20% */
		bot->rw.action = BOT_ACTION_TURN_LEFT;
		return 0;
	}
	if (r < (RRANGE*90)) {
		/* 20% */
		bot->rw.action = BOT_ACTION_TURN_RIGHT;
		return 0;
	}
	/* 10% */
	bot->rw.action =  BOT_ACTION_WAIT;
	return 0;
}
