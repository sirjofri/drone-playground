#ifndef commands_h
#define commands_h
#include <string>

/** Command integer map
 */
enum CMDS {
	CMDS_EXIT,
	CMDS_RUN,
	CMDS_INVALID,
	CMDS_EMPTY
};

const std::string CMD_EXIT = "exit";
const std::string CMD_RUN = "run";
const std::string CMD_EMPTY = "";

/** converts a command:string into a command:int. see CMDS
 *
 * @param command a string command
 *
 **/
int cmd(std::string command)
{
	if(command == CMD_EXIT) { return CMDS_EXIT; } else
	if(command == CMD_EMPTY) { return CMDS_EMPTY; } else
	if(command == CMD_RUN) { return CMDS_RUN; }
	else { return CMDS_INVALID; }
}

// vim:ts=4:sw=4:noet
#endif
