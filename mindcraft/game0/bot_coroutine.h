#ifndef _BOT_COROUTINE_H_
#define _BOT_COROUTINE_H_

#include <mindcraft/types.h>

#define BOT_STORAGE_T
typedef struct {
	uint64_t magic;
	uint64_t line;
} bot_storage_t;

#include <mindcraft/game0/bot.h>

#ifndef USE_MAGIC
#define USE_MAGIC 1
#endif
#define MAGIC (*((uint64_t*)__TIME__))
#define SET_MAGIC(X) ({__BOT__->rw.storage.magic = X;})
#define GET_MAGIC()  ({__BOT__->rw.storage.magic;})

#define SET_LINE(X) ({__BOT__->rw.storage.line = X;})
#define GET_LINE()  ({__BOT__->rw.storage.line;})

#define RESET_BOT uint64_t coroutine_bot(struct bot_t *__BOT__) { SET_LINE(0); return 0; }

#define BEGIN_BOT uint64_t coroutine_bot(struct bot_t *__BOT__) { \
if (USE_MAGIC && GET_MAGIC() != MAGIC) {SET_MAGIC(MAGIC); SET_LINE(0);} \
switch( GET_LINE() ) { \
	case 0:
#define END_BOT default: __BOT__->rw.action = BOT_ACTION_WAIT;} return 0;}

#define YIELD(X) \
do { \
	SET_LINE(__LINE__); \
	__BOT__->rw.action = X; \
	return 0; \
	case __LINE__:; \
} while (0)

/* BOT_ACTION */

#define WAIT YIELD(BOT_ACTION_WAIT);
#define WALK YIELD(BOT_ACTION_WALK);
#define TURN_LEFT YIELD(BOT_ACTION_TURN_LEFT);
#define TURN_RIGHT YIELD(BOT_ACTION_TURN_RIGHT);
#define HARVEST YIELD(BOT_ACTION_HARVEST);

#endif /* _BOT_COROUTINE_H_ */
