#ifndef SDRAM_PORTS_PINOUT_V1_IS42S16100F_H_
#define SDRAM_PORTS_PINOUT_V1_IS42S16100F_H_
#include <xs1.h>

/*
 *  Structure containing the resources required for the SDRAM  ports interface.
 */
struct sdram_ports_PINOUT_V1_IS42S16100F
{
  //Data and Address muxed along with bank address
  buffered port:32 dq_ah;

  //Control Signals
  out buffered port:32 cas;
  out buffered port:32 ras;
  out buffered port:8 we;

  //Clock
  out port clk;

  clock cb;
};
#endif /* SDRAM_PORTS_PINOUT_V1_IS42S16100F_H_ */
