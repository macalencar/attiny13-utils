 /* @author: Ralph Doncaster
  * @updatedby: Márcio Alencar 
  * 
  * Attiny13A @ 1MHz -> Baudrate 9600 : Delay(1000) = 1 s
  * Attiny13A @ 1.2 MHz -> Baudrate 2400 ~ 34800 : Delay(1000) = 1.2s
  * Default Baudrate @ 1.0Mhz: 9600
  * Default Baudrate @ 1.2Mhz: 2400
  * 
  */

#include <BasicSerial.h>

//#define BAUD_RATE 34800 //set clock @ 1.2 Mhz  
#define LEDPIN 2 //PINB2
void setup(){
  pinMode(LEDPIN,OUTPUT);   //DDRB |= (1<<LEDPIN);
}
void serOut(const char* str) {   while (*str) TxByte (*str++); }

void loop(){
  serOut("Turning on LED\n");
  //PORTB |= (1<<LEDPIN);  // turn on LED
  digitalWrite(LEDPIN,HIGH);
  delay(1000);
  //PORTB &= ~(1<<LEDPIN); // turn off LED
  digitalWrite(LEDPIN,LOW);
  delay(1000);
}