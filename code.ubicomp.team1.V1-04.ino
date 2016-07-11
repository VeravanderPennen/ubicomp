// bron basis code: http://forum.arduino.cc/index.php?topic=124707.0 en Ubicomp lessen, CMD 2016, HvA. Aanpassingen door Vera van der Pennen.

int switchPin1 = 2;        // switch is connected to pin 2
int switchPin2 = 3;
int switchPin3 = 4;
    int led1Pin = 13;
    int led2pin = 12;
    int led3pin = 11; 

    int val;                        // variable for reading the pin status
    int val2;                       // variable for reading the delayed status
    int val3;
    int val4;
    int val5;
    int val6;
    int buttonState1;                // variable to hold the button state
    int buttonState2;
    int buttonState3;
    int Mode = 0;              // What mode is the light in?
    long randNumber; 

    int knopStatus1 = 0;  
    int knopStatus2 = 0;
    int knopStatus3 = 0; 
    int aantalHits = 0; 

    void setup() {
      pinMode(switchPin1, INPUT);    // Set the switch pin as input
      pinMode(switchPin2, INPUT);
      pinMode(switchPin3, INPUT);
      pinMode(led1Pin, OUTPUT);
      pinMode(led2pin, OUTPUT);
      pinMode(led3pin, OUTPUT);
      buttonState1 = digitalRead(switchPin1);   // read the initial state
      buttonState2 = digitalRead(switchPin2);
      buttonState3 = digitalRead(switchPin3);
      Serial.begin(9600);
    }

    void loop(){        
      /*randNumber = random(1,4);
      delay(1000);
      Serial.println(randNumber);*/
      
  //check of er een knop wordt ingedrukt om te beginnen
  while(!knopStatus1 && !knopStatus2 && !knopStatus3){
    knopStatus1 = digitalRead(2);
    knopStatus2 = digitalRead(3);
    knopStatus3 = digitalRead(4);
  }
  

    val = digitalRead(switchPin1);      // read input value and store it in val
      delay(10);                         // 10 milliseconds is a good amount of time
      val2 = digitalRead(switchPin1);     // read the input again to check for bounces
      if (val == val2) {                  // make sure we got 2 consistant readings!
        if (val != buttonState1) {          // the button state has changed!
         if (val == LOW) {                // check if the button is pressed
            if (Mode == 0 /*&& (led1Pin == HIGH)*/) {     
              Mode = random(1,4);                  
            } else {
                if (Mode == 1) {        
                Mode = random(2,4);           
            } else {
                if (Mode == 2) {      
                Mode = random(1,4);           
            } else {
                if (Mode == 3) { 
                Mode = random(1,3);          
                  }
            }
           }
          } 
         }
        }
        buttonState1 = val;                 // save the new state in our variable
       if (checkHit) {
          
       }
      }
   
      val3 = digitalRead(switchPin2);      // read input value and store it in val
      delay(10);                         // 10 milliseconds is a good amount of time
      val4 = digitalRead(switchPin2);     // read the input again to check for bounces
      if (val3 == val4) {                 // make sure we got 2 consistant readings!
        if (val3 != buttonState2) {          // the button state has changed!
         if (val3 == LOW) {                // check if the button is pressed
            if (Mode == 0 /*&& (led2pin == HIGH)*/) { 
              delay(5);         
              Mode = random(1,4);               
            } else {
                if (Mode == 1) {        
                Mode = random(2,4);           
            } else {
                if (Mode == 2) {      
                Mode = random(1,4);           
            } else {
                if (Mode == 3) { 
                Mode = random(1,3);          
                  }
            }
           }
          } 
         }
        }
        buttonState2 = val3;                 // save the new state in our variable
      }
     

      val5 = digitalRead(switchPin3);      // read input value and store it in val
      delay(10);                         // 10 milliseconds is a good amount of time
      val6 = digitalRead(switchPin3);     // read the input again to check for bounces
      if (val5 == val6) {                 // make sure we got 2 consistant readings!
        if (val5 != buttonState3) {          // the button state has changed!
         if (val5 == LOW) {                // check if the button is pressed
            if (Mode == 0 /*&& (led3pin == HIGH)*/) {          
              Mode = random(1,4);               
            } else {
                if (Mode == 1) {        
                Mode = random(2,4);           
            } else {
                if (Mode == 2) {      
                Mode = random(1,4);           
            } else {
                if (Mode == 3) { 
                Mode = random(1,3);          
                  }
            }
           }
          } 
         }
        }
        buttonState3 = val5;                 // save the new state in our variable
      } 
   

      // Now do whatever the lightMode indicates
      if (Mode == 0) { // all-off
        digitalWrite(led1Pin, LOW);
        digitalWrite(led2pin, LOW);
        digitalWrite(led3pin, LOW);
      }

      if (Mode == 1) { 
        digitalWrite(led1Pin, HIGH);
        digitalWrite(led2pin, LOW);
        digitalWrite(led3pin, LOW);
      }

      if (Mode == 2) { 
        digitalWrite(led1Pin, LOW);
        digitalWrite(led2pin, HIGH);
        digitalWrite(led3pin, LOW);
      }
      
      if (Mode == 3)  { 
        digitalWrite(led1Pin, LOW);
        digitalWrite(led2pin, LOW);
        digitalWrite(led3pin, HIGH);
      }  

      if(aantalHits>10) {
    Serial.println("Yes you did it!");
    digitalWrite(10, HIGH);  
  }
      else {
    Serial.println("Not so good, but you've tried!");
    digitalWrite(9, HIGH);  
    exit(0);
  }
}

    boolean checkHit(int antwoordNummer){

    //zorg ervoor dat de variabelen voor de status van de knop netjes op 0 staan voordat het checken begint
    knopStatus1 = 0;
    knopStatus2 = 0;
    knopStatus3 = 0;

    boolean knopGedrukt = false;
    
    // start een loop die wacht tot er een knop in wordt gedrukt
    while(!knopStatus1 && !knopStatus2 && !knopStatus3){

      knopStatus1 = digitalRead(2);
      knopStatus2 = digitalRead(3);
      knopStatus3 = digitalRead(4);
      
      if(knopStatus1) {
        aantalHits++;
        knopGedrukt = true;
      } 
    
      if(knopStatus2) {
        aantalHits++;
        knopGedrukt = true;
      } 

      if(knopStatus3) {
        aantalHits++;
        knopGedrukt = true;
      } 
      
    }
    
    //stuur terug naar het basisprogramma dat de hit geregistreerd is 
    return knopGedrukt;
    
}

