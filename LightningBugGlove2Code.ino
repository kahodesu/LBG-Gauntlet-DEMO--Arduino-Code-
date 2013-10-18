/////////////////////////////
/////////////////////////////
// Lightning Bug Glove     // 
// Prototype 2 Code        //
// by Kaho Abe             //
// 1/16/13 at Eyebeam      //
/////////////////////////////
// based on FADE example   //
/////////////////////////////

 //an array of the pins used for leds
//int leds[8]={5,6,7,8,9,10,11,12};
int leds[8]={12,11,10,9,8,7,6,5};

int brightness = 0;    // how bright the LED is
int fadeAmount = 1;    // how many points to fade the LED by

int randLed;
int counter = 0;
int mode = 0;


void setup()  { 
  // declares all pins as outputs
   for (int i=5 ; i<13; i++) {
     pinMode(i, OUTPUT);  
   }
     Serial.begin(9600); 
} 

// the loop routine runs over and over again forever:
void loop()  { 
  
  //this one makes everything flash
  if(mode == 0 && counter < 500) {
    randLed = random(5, 13);
    analogWrite(randLed, 100);   
    delay(30);
    analogWrite(randLed, 0);  
    counter++;
  }
  else if(mode == 1 && counter < 300) {
     for (int i=5 ; i<13; i++) {
       analogWrite(i, 0);  
     }
     counter++;
  }
  //this one makes everything shimmer
  else if(mode == 2 && counter < 500) {
    randLed = random(5, 13);
    analogWrite(randLed, brightness);   
    brightness = brightness + fadeAmount;
    
  // reverse the direction of the fading at the ends of the fade: 
    if (brightness == 0 || brightness == 50) {
        fadeAmount = -fadeAmount ; 
    }     
  // wait for 30 milliseconds to see the dimming effect    
    delay(30);   
    counter++;
  }
  else if(mode == 3 && counter < 300) {
     for (int i=5 ; i<13; i++) {
       analogWrite(i, 0);  
     }
     counter++;
  }
  else if(mode == 4 && counter == 0) {
     for (int i=0 ; i<9; i++) {
         for (int j=0 ; j<256; j++) {
            analogWrite(leds[i], j); 
            j=j+3;
            delay(10);
         }    
     }
     delay(2000);
     mode++;
  }
  else if(mode == 5 && counter < 300) {
     for (int i=5 ; i<13; i++) {
       analogWrite(i, 0);  
     }
     counter++;
  }

  else if(mode == 6) {
   counter = 0;
   mode =0; 
  }
  
  else {
    counter = 0;
    mode++;
  }
 // Serial.println(counter);

}

