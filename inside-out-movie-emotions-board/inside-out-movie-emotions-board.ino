#define neopixel 9

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define NUMPIXELS 12
Adafruit_NeoPixel pixels(NUMPIXELS, neopixel, NEO_GRB + NEO_KHZ800);


long oldtime;
bool oldstate[]= {false};

uint8_t colormemory[]= {0x7ED0CA, 0xE36A95, 0xB48DC4, 0x337BC3, 0xDDCC3B, 0x6FAF5B, 0xD02626, 0xDA602F, 0x263791};

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
  //pinMode(LED, OUTPUT);
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() - oldtime > 200){
    oldtime= millis();

    for(int i= 1; i < 10; i++){
      if(digitalRead(i) && oldstate[i-1]== false){
        pixels.clear();
        for(int j=0; j<NUMPIXELS; j++) { // For each pixel...

          pixels.setPixelColor(j, colormemory[i-1]);
          pixels.show();   // Send the updated pixel colors to the hardware.

          delay(5); // Pause before next pass through loop
        }
        oldstate[i-1]= true;
      }else if(digitalRead(i) && oldstate[i-1]== true){
        oldstate[i-1]= true;
      }else if(!digitalRead(i) && oldstate[i-1]== true){
        oldstate[i-1]= false;
      }
    }
    
  }
  
}