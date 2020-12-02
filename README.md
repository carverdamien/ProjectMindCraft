# ProjectMindCraft

ProjectMindCraft is a programming video game online.

## Getting started

Download a release zip file corresponding to your platform and decompress the archive.
On windows, run `MindCraft.exe`; on OSX run `MindCraft.app`; and on Linux run `MindCraft`.

Pressing Escape opens the main menu with the following choices:

1. Enter `Camera Mode` to explore the world.
2. Enter `Editor Mode` to write and upload code that will modify the behavior of the objects in the world.
3. Enter `Console Mode` to show the latest error messages from the server.
4. Enter `Stats Mode` to display statistics about events in the game.

## Quick programming guide

The [bot.h](./mindcraft/game0/bot.h) file defines how the bot's data is structured.
A bot knows its `position`, its `orientation` and the `objects` visible in front of it.
At each tick (second), the bot has to take an `action` such as `WALK` or `TURN`.
It is up to the player to write a program that will take the decision for the bot.

Programs are single functions that take a bot as an argument and return an error code.
For example, the following program will always take the decision to `WAIT`:

```
#include <mindcraft/game0/bot.h>
uint64_t idle_bot(struct bot *bot) {
	bot->rw.action = BOT_WAIT;
	return 0;
}
```

Beginners are invited to try [bot_coroutine.h](./mindcraft/game0/bot_coroutine.h):
```
#include<mindcraft/game0/bot_coroutine.h>
BEGIN_BOT
while (true) {
	TURN_RIGHT
	WALK
	WALK
}
END_BOT
```

More examples are provides in the [bots](./bots) directory.

## Download release v2.2-alpha

* [Windows](https://github.com/carverdamien/ProjectMindCraft/releases/download/v2.2-alpha/windows.zip)
* [OSX](https://github.com/carverdamien/ProjectMindCraft/releases/download/v2.2-alpha/osx.zip)
* [Linux](https://github.com/carverdamien/ProjectMindCraft/releases/download/v2.2-alpha/linux.zip)

## YouTube DevLog

[YouTube Playlist:](https://www.youtube.com/playlist?list=PL3C75lW2it0hcKLD6gWCC6gioWwPY6gHr)

0. https://youtu.be/ji8kWSmT3Ys
1. https://youtu.be/tzbaCrTJsdo
2. https://youtu.be/uAWcOc-E1UQ

## YouTube Let's Play

0. https://youtu.be/haaWyKG_bU0

## Discord Server

Daily updates/chat on discord

https://discord.gg/HzAcR8a

## Challenges

Submit your solution to a challenge with a pull request:

1. [spiral_bot.c](./bots/spiral_bot.c)
2. [meteorite_harvester_bot.c](./bots/meteorite_harvester_bot.c)

