#ifndef __sdram_geometry_h__
#define __sdram_geometry_h__

#include "sdram_geometry_PINOUT_V1_IS42S16400F.h"
#include "sdram_geometry_PINOUT_V1_IS42S16160D.h"
#include "sdram_geometry_PINOUT_V0.h"

#define SDRAM_COL_BITS ADD_SUFFIX(SDRAM_COL_BITS, SDRAM_DEFAULT_IMPLEMENTATION)

#define SDRAM_ROW_ADDRESS_BITS \
     ADD_SUFFIX(SDRAM_ROW_ADDRESS_BITS, SDRAM_DEFAULT_IMPLEMENTATION)

#define SDRAM_COL_ADDRESS_BITS \
     ADD_SUFFIX(SDRAM_COL_ADDRESS_BITS, SDRAM_DEFAULT_IMPLEMENTATION)

#define SDRAM_BANK_ADDRESS_BITS \
     ADD_SUFFIX(SDRAM_BANK_ADDRESS_BITS, SDRAM_DEFAULT_IMPLEMENTATION)

#define SDRAM_COL_COUNT (1<<SDRAM_COL_ADDRESS_BITS)
#define SDRAM_ROW_COUNT (1<<SDRAM_ROW_ADDRESS_BITS)
#define SDRAM_BANK_COUNT (1<<SDRAM_BANK_ADDRESS_BITS)

#define SDRAM_ROW_WORDS (SDRAM_COL_COUNT/(32/SDRAM_COL_BITS))

#endif
