#include "ir.h"
#include "remote.h"
#include "program.h"

struct ir_command_t cmd;

void remote_handle_commands() {
	ir_get_last_command(&cmd);

	if(cmd.valid && cmd.address == REMOTE_ADDRESS) {
		switch(cmd.command) {
			#ifdef KEY_ON
			case KEY_ON:
				program_on();
				break;
			#endif
			#ifdef KEY_OFF
			case KEY_OFF:
				program_off();
				break;
			#endif
			#ifdef BRIGHTNESS_UP
			case BRIGHTNESS_UP:
				program_brightness_increase(10);
				break;
			#endif
			#ifdef BRIGHTNESS_DOWN
			case BRIGHTNESS_DOWN:
				program_brightness_decrease(10);
				break;
			#endif
			#ifdef KEY_RED_0
			case KEY_RED_0:
				program_static(0, 255);
				break;
			#endif
			#ifdef KEY_RED_1
			case KEY_RED_1:
				program_static(64, 255);
				break;
			#endif
			#ifdef KEY_RED_2
			case KEY_RED_2:
				program_static(128, 255);
				break;
			#endif
			#ifdef KEY_RED_3
			case KEY_RED_3:
				program_static(192, 255);
				break;
			#endif
			#ifdef KEY_RED_4
			case KEY_RED_4:
				program_static(256, 255);
				break;
			#endif
			#ifdef KEY_GREEN_0
			case KEY_GREEN_0:
				program_static(512, 255);
				break;
			#endif
			#ifdef KEY_GREEN_1
			case KEY_GREEN_1:
				program_static(576, 255);
				break;
			#endif
			#ifdef KEY_GREEN_2
			case KEY_GREEN_2:
				program_static(640, 255);
				break;
			#endif
			#ifdef KEY_GREEN_3
			case KEY_GREEN_3:
				program_static(704, 255);
				break;
			#endif
			#ifdef KEY_GREEN_4
			case KEY_GREEN_4:
				program_static(768, 255);
				break;
			#endif
			#ifdef KEY_BLUE_0
			case KEY_BLUE_0:
				program_static(1024, 255);
				break;
			#endif
			#ifdef KEY_BLUE_1
			case KEY_BLUE_1:
				program_static(1088, 255);
				break;
			#endif
			#ifdef KEY_BLUE_2
			case KEY_BLUE_2:
				program_static(1152, 255);
				break;
			#endif
			#ifdef KEY_BLUE_3
			case KEY_BLUE_3:
				program_static(1216, 255);
				break;
			#endif
			#ifdef KEY_BLUE_4
			case KEY_BLUE_4:
				program_static(1280, 255);
				break;
			#endif
			#ifdef KEY_WHITE_0
			case KEY_WHITE_0:
				program_static(0, 0);
				break;
			#endif
			#ifdef KEY_WHITE_1
			case KEY_WHITE_1:
				program_static(132, 115);
				break;
			#endif
			#ifdef KEY_WHITE_2
			case KEY_WHITE_2:
				program_static(128, 66);
				break;
			#endif
			#ifdef KEY_WHITE_3
			case KEY_WHITE_3:
				program_static(930, 23);
				break;
			#endif
			#ifdef KEY_WHITE_4
			case KEY_WHITE_4:
				program_static(991, 38);
				break;
			#endif
			#ifdef KEY_RED_UP
			case KEY_RED_UP:
				break;
			#endif

			#ifdef KEY_RED_DOWN
			case KEY_RED_DOWN:
				break;
			#endif

			#ifdef KEY_GREEN_UP
			case KEY_GREEN_UP:
				break;
			#endif

			#ifdef KEY_GREEN_DOWN
			case KEY_GREEN_DOWN:
				break;
			#endif

			#ifdef KEY_BLUE_UP
			case KEY_BLUE_UP:
				break;
			#endif

			#ifdef KEY_BLUE_DOWN
			case KEY_BLUE_DOWN:
				break;
			#endif

			#ifdef KEY_MACRO_1
			case KEY_MACRO_1:
				break;
			#endif

			#ifdef KEY_MACRO_2
			case KEY_MACRO_2:
				break;
			#endif

			#ifdef KEY_MACRO_3
			case KEY_MACRO_3:
				break;
			#endif

			#ifdef KEY_MACRO_4
			case KEY_MACRO_4:
				break;
			#endif

			#ifdef KEY_MACRO_5
			case KEY_MACRO_5:
				break;
			#endif

			#ifdef KEY_MACRO_6
			case KEY_MACRO_6:
				break;
			#endif

			#ifdef KEY_SPEED_UP
			case KEY_SPEED_UP:
				break;
			#endif

			#ifdef KEY_SPEED_DOWN
			case KEY_SPEED_DOWN:
				break;
			#endif

			#ifdef KEY_PROGRAM_1
			case KEY_PROGRAM_1:
				break;
			#endif

			#ifdef KEY_PROGRAM_2
			case KEY_PROGRAM_2:
				break;
			#endif

			#ifdef KEY_PROGRAM_3
			case KEY_PROGRAM_3:
				break;
			#endif

			#ifdef KEY_PROGRAM_4
			case KEY_PROGRAM_4:
				break;
			#endif

			#ifdef KEY_PROGRAM_5
			case KEY_PROGRAM_5:
				break;
			#endif

			#ifdef KEY_PROGRAM_6
			case KEY_PROGRAM_6:
				break;
			#endif

			default:;
		}
	}
}