#ifndef commands_h
#define commands_h
#include <string>

/** Command integer map
 */
enum CMDS {
	CMDS_EXIT,
	CMDS_HELP,
	CMDS_SOCK,
	CMDS_RUN,
	CMDS_EMPTY,
	CMDS_INVALID
};

const std::string CMD_EXIT = "exit";
const std::string CMD_HELP = "help";
const std::string CMD_SOCK = "sock";
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
	if(command == CMD_HELP) { return CMDS_HELP; } else
	if(command == CMD_SOCK) { return CMDS_SOCK; } else
	if(command == CMD_RUN) { return CMDS_RUN; } else
	if(command == CMD_EMPTY) { return CMDS_EMPTY; }
	else { return CMDS_INVALID; }
}

// vim:ts=4:sw=4:noet
#endif
