#include "keyboard.h"
#include "video.h"

#include "otwp.h"

void Debug(char *title, char *message)
{
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, title, message, NULL);
}

void DebugInt(int value, char *title, char *format)
{
	char *temp = malloc((sizeof(int) * sizeof(value)) + sizeof(format));
	sprintf(temp, "%s %d", format, value);
	Debug(title, temp);
	free(temp);
}

void DebugFloat(float value, char *title, char *format)
{
	char *temp = malloc((sizeof(float) * sizeof(value)) + sizeof(format));
	sprintf(temp, "%s %f", format, value);
	Debug(title, temp);
	free(temp);
}

void DebugBool(bool value, char *title, char *format)
{
	char *temp = malloc((sizeof(char) * 10) + sizeof(format));
	sprintf(temp, "%s %s", format, (value ? "true" : "false"));
	Debug(title, temp);
	free(temp);
}

void DebugCoordinates(float x, float y, char *title, char *format)
{
	char *temp = malloc((sizeof(char) * 20) + (sizeof(char) * sizeof(format)));
	sprintf(temp, "%s: %f, %f", format, x, y);
	Debug(title, temp);
	free(temp);
}

void normalizeCoordinates(float *x, float *y)
{
	int win_w, win_h;
	SDL_GetWindowSize(main_window, &win_w, &win_h);
	*x = ((*x * win_w) - last_output_rect.x) / last_output_rect.w;
	*y = ((*y * win_h) - last_output_rect.y) / last_output_rect.h;
}

int getMainTouchMenu(int menu)
{
	int menuItem = TYRIAN_MENU_SELECT_NONE;
	switch (menu)
	{
	case TYRIAN_MENU_MAIN:
		if (touch_x < 0.1f && touch_y < 0.15f)
		{
			menuItem = TYRIAN_MENU_KEYBOARD;
		}
		if (touch_x > 0.31f && touch_x < 0.69f && touch_y > 0.50f && touch_y < 0.99f)
		{
			if (touch_y < 0.57f)
				menuItem = 0;
			else if (touch_y < 0.64f)
				menuItem = 1;
			else if (touch_y < 0.71f)
				menuItem = 2;
			else if (touch_y < 0.78f)
				menuItem = 3;
			else if (touch_y < 0.85f)
				menuItem = 4;
			else if (touch_y < 0.92f)
				menuItem = 5;
			else if (touch_y < 0.99f)
				menuItem = 6;
		}
		break;
	case TYRIAN_MENU_LOAD_GAME:
		break;
	case TYRIAN_MENU_INSTRUCTIONS:
		if (touch_x > 0.23f && touch_x < 0.77f && touch_y > 0.27f && touch_y < 0.67f)
		{
			if (touch_y < 0.37f)
				menuItem = 2;
			else if (touch_y < 0.47f)
				menuItem = 3;
			else if (touch_y < 0.57f)
				menuItem = 4;
			else
				menuItem = 5;
		}
		break;
	case TYRIAN_MENU_OPENTYRIAN:
		if (touch_x > 0.30f && touch_x < 0.70f && touch_y > 0.16f && touch_y < 0.44f)
		{
			if (touch_y < 0.23f)
				menuItem = 0;
			else if (touch_y < 0.3f)
				menuItem = 1;
			else if (touch_y < 0.37f)
				menuItem = 2;
			else if (touch_y < 0.44f)
				menuItem = 3;
		}
		break;
	}
	return menuItem;
}

int getGameTouchMenu(int menu)
{
	int menuItem = TYRIAN_MENU_SELECT_NONE;
	switch (menu)
	{
	case GAME_MENU_MAIN:
		break;
	case GAME_MENU_DATA:
		break;
	case GAME_MENU_UPGRADE:
		break;
	case GAME_MENU_OPTIONS:
		break;
	case GAME_MENU_NEXT_LEVEL:
		break;
	case GAME_MENU_UPGRADE_SHIP:
	case GAME_MENU_UPGRADE_FRONT_GUN:
	case GAME_MENU_UPGRADE_REAR_GUN:
	case GAME_MENU_UPGRADE_SHIELD:
	case GAME_MENU_UPGRADE_GENERATOR:
	case GAME_MENU_UPGRADE_LEFT_KICK:
	case GAME_MENU_UPGRADE_RIGHT_KICK:
		break;
	case GAME_MENU_OPTIONS_SAVE:
	case GAME_MENU_OPTIONS_LOAD:
		break;
	}
}
