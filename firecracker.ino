/* Arduino Interface to the CM17A Wireless X10 dongle. BroHogan 7/19/08
 * Arduino Library Conversion by DaveK AC0KG  Dec/08
 * The CM17A gets it power and data using only the RTS, CTS, & Gnd lines.
 * CONNECTION: RTS -> DB9 pin 7.  DTR -> DB9 pin 4. Gnd. -> DB9 pin 5.
 * See X10Firecracker.cpp in your libraries folder for more details
 */

#include <X10Firecracker.h>

#define RTS_PIN     2	                // RTS line for C17A - DB9 pin 7
#define DTR_PIN     3	                // DTR line for C17A - DB9 pin 4
#define BIT_DELAY   1                   // mS delay between bits (1 mS OK)

void setup()
{
  X10.init(RTS_PIN, DTR_PIN, BIT_DELAY);  //
}

void doModule(int module)
{
  X10.sendCmd( hcO, module, cmdOn );
  delay(2000);
  
  X10.sendCmd( hcO, module, cmdDim );
  X10.sendCmd( hcO, module, cmdDim );
  X10.sendCmd( hcO, module, cmdDim );
  X10.sendCmd( hcO, module, cmdDim );
  X10.sendCmd( hcO, module, cmdDim );
  delay(2000);
      
  X10.sendCmd( hcO, module, cmdBright );
  X10.sendCmd( hcO, module, cmdBright );
  X10.sendCmd( hcO, module, cmdBright );
  X10.sendCmd( hcO, module, cmdBright );
  X10.sendCmd( hcO, module, cmdBright );
  delay(2000);
  
  X10.sendCmd( hcO, module, cmdOff );
  delay(2000);
}

void Test()
{
  doModule(1);
  doModule(2);
}

void loop()
{
//  delay(2000);
  Test();
//  delay(8000);
}
