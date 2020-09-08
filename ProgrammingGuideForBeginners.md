# Programming Guide For Beginners

## First program

Beginners are invited to use the [bot_coroutine.h](./mindcraft/game0/bot_coroutine.h) file
which contains [macroinstructions](https://en.wikipedia.org/wiki/Macro_(computer_science)) to ease the programming.
You do not have to read the content of this file to proceed with the guide.

The minimal requirement for a program are the three following lines:
```
#include<mindcraft/game0/bot_coroutine.h>
BEGIN_BOT
END_BOT
```
This program does nothing. If you upload it, the bot will do the `WAIT` action.
The `#include` keyword loads the content of [bot_coroutine.h](./mindcraft/game0/bot_coroutine.h).
The `BEGIN_BOT` and `END_BOT` keywords are [macroinstructions](https://en.wikipedia.org/wiki/Macro_(computer_science))
between which you should write your program.

At the end of the [bot_coroutine.h](./mindcraft/game0/bot_coroutine.h) file,
there are [macroinstructions](https://en.wikipedia.org/wiki/Macro_(computer_science)) that let you control your bot.
You can use them in your program like this:
```
#include<mindcraft/game0/bot_coroutine.h>
BEGIN_BOT
WALK
TURN_RIGHT
WAIT
TURN_LEFT
HARVEST
WALK
WALK
END_BOT
```
Keep in mind that the code is case sensitive (`walk` and `Wait` are incorrect).
The character between `TURN` and `LEFT` is not a space, it is the underscore character `_`.

## The forever loop

The forever loop repeat the instructions between the braces forever (between `{` and `}`).

```
#include<mindcraft/game0/bot_coroutine.h>
BEGIN_BOT
while(true) {
	WALK
}
END_BOT
```

## Variables

Variables are used to write and read information.

In this example, we use an integer to remember how many times we have repeated the action `WALK`.
After `10` times, we stop the loop.
```
#include<mindcraft/game0/bot_coroutine.h>
BEGIN_BOT_WITH_VAR(int i;)
var->i = 0;
while (var->i<10) {
	WALK;
	var->i = var->i + 1;
}
END_BOT_WITH_VAR
```
The `var->i = 0;` is an instruction that asks to store the value `0` in the variable `i`.
Indeed, we just started the program, and we haven't `WALK`ed yet.
The `var->i<10` tests if `i` is smaller than `10`, because we want to repeat the action `10` times.
The `var->i = var->i + 1;` increases the value of `i` by `1`.
Notice that instructions are followed by `;` except inside a test (`while`).

## Branching

Branches are used to choose instruction to execute based on a condition.

In this example, we want our bot to `WALK` if `THERE_IS_NOTHING_IN_FRONT` and we want it to turn back otherwise.
```
#include<mindcraft/game0/bot_coroutine.h>
BEGIN_BOT
while(true) {
	if (THERE_IS_NOTHING_IN_FRONT) {
		WALK
	} else {
		TURN_RIGHT
		TURN_RIGHT
	}
}
END_BOT
```

Can you use the condition `THERE_IS_A_METEORITE_IN_FRONT` to banch on the action `HARVEST` ?

