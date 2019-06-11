/**
 * Authors: Naveen Lalwani, Karan Rawlani
 * The following simple piece of code helps one get the Hex value 
 * associated with the button pressed on the IR Remote.
 */
#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{ 
  irrecv.enableIRIn(); // Start the receiver
  Serial.begin(9600);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    delay(900);
    irrecv.resume(); // Receive the next value
  }
}
