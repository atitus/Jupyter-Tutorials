#define UD A0
#define LR A1
boolean done = false;
int N; // number of measurements to make but one measurement is always returned in this program
int LRvali; // initial LR value
int UDvali; // initial UD value
int LRval; //  LR value
int UDval; //  UD value



void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  digitalWrite(13, LOW);   // turn the LED off
  LRvali = analogRead(LR);
  UDvali = analogRead(UD);
}

void loop() {
    	done = false;
    
    	// Check input on serial line.
    	while (!done) {
        //listen to Serial input
    		if (Serial.available()) {	// Something is in the buffer
    			N = Serial.read();	// so get the number byte
    			done = true;
    		}
    	}

      // get joystick values  
      LRval = analogRead(LR);
      UDval = analogRead(UD);

      // write joystick values
      Serial.print(LRval, DEC);
      Serial.print('\t');
      Serial.print(UDval, DEC);
      Serial.print('\n');
}
