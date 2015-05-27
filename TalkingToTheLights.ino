int incomingByte = 0;   // for incoming serial data
 
void setup() {
   Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(7, OUTPUT);
}
 
 
void loop() {
 
        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                byte incomingByte = Serial.read();
                byte LED1Mask = 1;
                byte LED2Mask = 2;
                byte LED3Mask = 4;
                byte LED4Mask = 8;
                byte second = 1010;
                // say what you got:
                Serial.println(incomingByte, BIN);
                //if ((second ^ incomingByte) != 0){
                Serial.println("checking bit mask ");
                Serial.println(LED1Mask & incomingByte, BIN);
                Serial.println(LED2Mask & incomingByte, BIN);
                Serial.println(LED3Mask & incomingByte, BIN);
                Serial.println(LED4Mask & incomingByte, BIN);
                
                digitalWrite(4, LED1Mask & incomingByte);
                digitalWrite(5, LED2Mask & incomingByte);
                digitalWrite(6, LED3Mask & incomingByte);
                digitalWrite(7, LED4Mask & incomingByte);
                //}
                
                delay(3000);
        }
}

