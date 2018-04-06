/* Optimized AVR305 half-duplex serial uart implementation
 * timing for 81N, 115.2kbps @8Mhz = 69.4 cycles/bit
 * and @16Mhz = 138.9 cycles/bit
 * @author: Ralph Doncaster
 * @version: $Id$
 * @updatedby: Márcio Alencar
 */

//#define BAUD_RATE 115200
#ifndef BAUD_RATE
  #define BAUD_RATE 2400  //--attiny13A @ 1.0 / 1.2MHz
#endif
#ifdef F_CPU
  #if F_CPU == 1000000L
    #define TXDELAY (((F_CPU/BAUD_RATE)+9)/3)  //cheat clock(1.0 MHz) = 1sec = delay(1000)
    #define BAUD_RATE 9600  // compatible
  #else
    #define TXDELAY (((F_CPU/BAUD_RATE)-9)/3)  //right clock(1.2 MHz) = 1.2sec = delay(1000)
  #endif
#else
  #error CPU frequency F_CPU undefined
#endif

#if TXDELAY > 255
  #error low baud rates unsupported - use higher BAUD_RATE
#endif

extern "C" {
void TxTimedByte(char, char);
}

#define TxByte(C) TxTimedByte(C , TXDELAY)

