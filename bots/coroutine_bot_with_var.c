#define __FUNC_NAME__ coroutine_bot_with_var

#include<mindcraft/game0/bot_coroutine.h>

BEGIN_BOT_WITH_VAR(int i;)

	for (var->i=0; var->i<10; var->i++) {
		WALK
	}

END_BOT_WITH_VAR

/*
 * TODO: Save and restore stack and registers.
 *
 * The template could look like this:
 *
 * BEGIN_BOT(int i;)
 *
 *	for (i=0; i<10; i++) {
 *		WALK
 *	}
 *
 * END_BOT
 *
 */
