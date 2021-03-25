# ScrollEmulate

You want to simulate the same "scroll" that your mouse does, but you broke the scrolling wheel? (please dont ask me how I did broke my scrolling wheel)
You prefer to scroll with ``X`` and ``Y`` keys for some reason or no reason?

What this program does is that it binds two keys to simulate/emulate a mouse scroll, it will work in any program as long as the program is open, it doesn't matters if it's unfocused.

### Why i did this program?
Well, we all need to start somewhere and I thought: What if my first open source program is a simple utility one used to scroll?
It is simple and very useful, not something that doesn't has any reason to be used plus it can actually help much people I guess.

### Notes:
- Behold my spaghetti code! Good luck trying to read it.
- This project will of course be improved by me as much as i can, don't worry about my inefficient code, it is temporary and it will be replaced.
- I know that emulation and simulation aren't the same thing lol.

### Usage:

To open the program's console, hold the key shift + M.

To see all the commands, insert help (don't forget to erase that stinky M when you hold both keys and the console activates).

To bind a letter to scroll UP:
1. Open the program's console if you dont have it open (SHIFT + M), note that, when it is open it will display a input prefix (``>>``).
2. Insert config_up __WHILE THE CONSOLE IS OPEN__.
3. Insert the key you want to bind (INPUT MUST BE 1 CHARACTER, NOT LESS OR MORE, also don't worry this will change in the future) and hit enter.
4. If the key was binded correctly, it will display: ``Binded ``THE_KEY_YOU_BINDED`` to scroll UP!``, where THE_KEY_YOU_BINDED is the key you binded *(thanks, captain obvious)*.

To bind a letter to scroll DOWN:
1. Open the program's console if you dont have it open (SHIFT + M), note that, when it is open it will display a input prefix (``>>``).
2. Insert config_down __WHILE THE CONSOLE IS OPEN__.
3. Insert the key you want to bind (INPUT MUST BE 1 CHARACTER, NOT LESS OR MORE) and hit enter.
4. If the key was binded correctly, it will display: ``Binded ``THE_KEY_YOU_BINDED`` to scroll DOWN!``, where THE_KEY_YOU_BINDED is the key you binded.

To change the cooldown that activates when a key is pressed **(IT IS RECOMMENDED TO BE MORE THAN 100MS)**:
1. Open the program's console if you dont have it open (SHIFT + M), note that, when it is open it will display a input prefix (``>>``).
2. Insert config_cooldown __WHILE THE CONSOLE IS OPEN__.
3. Insert how much milliseconds you want the cooldown to be, **(IT IS RECOMMENDED TO BE MORE THAN 100MS)**  and hit enter.
4. If the cooldown was set correctly, it will display: ``Setted cooldown to ``MILLISECONDS, where MILLISECONDS is the milliseconds you chose in the step 3.

