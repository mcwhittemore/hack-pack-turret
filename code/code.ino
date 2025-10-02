//////////////////////////////////////////////////
                //  LIBRARIES  //
//////////////////////////////////////////////////
#include <Arduino.h>
#include <Servo.h>
#include <IRremote.hpp>
#include "./ir-codes.h"
#include "./movement.h"
#include "./mode-defs.h"
#include "./commands.h"
#include "./password-mode.h"
#include "./direct-mode.h"

//////////////////////////////////////////////////
                //  S E T U P  //
//////////////////////////////////////////////////

// this is our setup function - it runs once on start up, 
// and is basically where we get everything "set up"
void setup() { 
  // initializes the Serial communication between the 
  // computer and the microcontroller
  Serial.begin(9600); 

  yawServo.attach(10); //attach YAW servo to pin 10
  pitchServo.attach(11); //attach PITCH servo to pin 11
  rollServo.attach(12); //attach ROLL servo to pin 12

  // Just to know which program is running on my microcontroller
  Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

  // Start the receiver and if not 3. parameter specified,
  // take LED_BUILTIN pin from the internal boards
  // definition as default feedback LED
  IrReceiver.begin(9, ENABLE_LED_FEEDBACK);

  Serial.print(F("Ready to receive IR signals of protocols: "));
  printActiveIRProtocols(&Serial);
  Serial.println(F("at pin 9"));

  homeServos(); //set servo motors to home position
}

//////////////////////////////////////////////////
                //  L O O P  //
//////////////////////////////////////////////////
void loop() {
    if (IrReceiver.decode()) { //if we have recieved a comman this loop...
        int command = IrReceiver.decodedIRData.command; //store it in a variable
        IrReceiver.resume(); // Enable receiving of the next value
        handleCommand(command); // Handle the received command through switch statements
    }
    delay(5); //delay for smoothness
}
