#define neopixel D9

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define NUMPIXELS 12
Adafruit_NeoPixel pixels(NUMPIXELS, neopixel, NEO_GRB + NEO_KHZ800);

long oldtime;
bool oldstate[]= {false, false, false, false, false, false, false, false, false};

//static const uint32_t colormemory[]= {0x007ED0CA, 0x00E36A95, 0x00B48DC4, 0x00337BC3, 0x00DDCC3B, 0x006FAF5B, 0x00D02626, 0x00DA602F, 0x00263791};
unsigned long colormemory[]= {0x007ED0CA, 0x00E36A95, 0x00B48DC4, 0x00337BC3, 0x00DDCC3B, 0x006FAF5B, 0x00D02626, 0x00DA602F, 0x00263791};

/*Inveja/envy:
Vergonha/embarassment:
Medo/fear: 
Tristeza/sadness:
Alegria/Joy:
Nojinho/disgust:
Raiva/anger:
Ansiedade/anxienty:
Tédio/ennui/boredom:*/

void setup() {
  // put your setup code here, to run once:
  //pinMode(D9, OUTPUT);
  pinMode(D0, INPUT);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);
  pinMode(D5, INPUT);
  pinMode(D6, INPUT);
  pinMode(D7, INPUT);
  pinMode(D8, INPUT);

  Serial.begin(115200);

  #define D0 0
  #define D1 1 
  #define D2 2 
  #define D3 3
  #define D4 4
  #define D5 5
  #define D6 6
  #define D7 7
  #define D8 8

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() - oldtime > 200){
    oldtime= millis();
    //pixels.clear();
    for(int i= 0; i < 9; i++){ // there are 9 buttons, go through all of them
      if(digitalRead(i) && oldstate[i]== false){ //if oldstate (previous) is false (0) and digitalRead (current) is true (1)
        
        for(int j=0; j < NUMPIXELS; j++) { // For each one of the 12 pixel...
          
          
          pixels.setPixelColor(j, colormemory[i]); // set a color, since button one has color one and etc
          

          delay(5); // Pause before next pass through loop
        }
        pixels.show();   // Send the updated pixel colors to the hardware.
        oldstate[i]= true; // if a color was set the oldstate is now true (1)
        Serial.print("botao ");
        Serial.print(i);
        Serial.println(" Pressionado");
      }else if(digitalRead(i) && oldstate[i]== true){ // if oldstate is true (1) does not do anything
        //oldstate[i]= true;
      }else if(!digitalRead(i) && oldstate[i]== true){ // if digital input went to false (0) and oldstate was true (1) reset oldstate
        //oldstate[i]= false;
        for(int k= 0; k < NUMPIXELS; k++){
          oldstate[k]= false;
        }
      }else{

      }
    }

        
  }
  
}