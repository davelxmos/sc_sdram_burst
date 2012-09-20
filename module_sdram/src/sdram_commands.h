#ifndef SDRAM_COMMANDS_H_
#define SDRAM_COMMANDS_H_

#ifdef __sdram_conf_h_exists__
#include "sdram_conf.h" // This is from the application
#endif

enum {
  SDRAM_CMD_WAIT_UNTIL_IDLE,
  SDRAM_CMD_BUFFER_READ,
  SDRAM_CMD_BUFFER_WRITE,
  SDRAM_CMD_FULL_ROW_READ,
  SDRAM_CMD_FULL_ROW_WRITE
};

/*
 * This list is application specific. Remove any of the commands
 * that are unused and the code will be eliminated from the
 * command handler and the SDRAM client.
 */
#ifndef SDRAM_ENABLE_CMD_WAIT_UNTIL_IDLE
#define SDRAM_ENABLE_CMD_WAIT_UNTIL_IDLE 1
#endif

#ifndef SDRAM_ENABLE_CMD_BUFFER_READ
#define SDRAM_ENABLE_CMD_BUFFER_READ 1
#endif

#ifndef SDRAM_ENABLE_CMD_BUFFER_WRITE
#define SDRAM_ENABLE_CMD_BUFFER_WRITE 1
#endif

#ifndef SDRAM_ENABLE_CMD_FULL_ROW_READ
#define SDRAM_ENABLE_CMD_FULL_ROW_READ 1
#endif

#ifndef SDRAM_ENABLE_CMD_FULL_ROW_WRITE
#define SDRAM_ENABLE_CMD_FULL_ROW_WRITE 1
#endif

#endif /* SDRAM_COMMANDS_H_ */