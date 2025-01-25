#define neopixel 9

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define NUMPIXELS 12
Adafruit_NeoPixel pixels(NUMPIXELS, neopixel, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  pinMode(10, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);

  //Serial.begin(115200);
  pixels.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  pixels.setBrightness(30);
  if(digitalRead(10)){

    for(int j=0; j < NUMPIXELS; j++) { // For each one of the 12 pixel...
          
          
      pixels.setPixelColor(j, 0xeda628); // Alegria
          

      delay(5); // Pause before next pass through loop
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
  }else if(digitalRead(1)){

    for(int j=0; j < NUMPIXELS; j++) { // For each one of the 12 pixel...
          
          
      pixels.setPixelColor(j, 0xdc5e23); // Ansiedade
          

      delay(5); // Pause before next pass through loop
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
  }else if(digitalRead(2)){

    for(int j=0; j < NUMPIXELS; j++) { // For each one of the 12 pixel...
          
          
      pixels.setPixelColor(j, 0xe63123); // Raiva
          

      delay(5); // Pause before next pass through loop
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
  }else if(digitalRead(3)){

    for(int j=0; j < NUMPIXELS; j++) { // For each one of the 12 pixel...
          
          
      pixels.setPixelColor(j, 0x116bb2); // Tristeza
          

      delay(5); // Pause before next pass through loop
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
  }else if(digitalRead(4)){

    for(int j=0; j < NUMPIXELS; j++) { // For each one of the 12 pixel...
          
          
      pixels.setPixelColor(j, 0xc32c90); // Vergonha
          

      delay(5); // Pause before next pass through loop
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
  }else if(digitalRead(5)){

    for(int j=0; j < NUMPIXELS; j++) { // For each one of the 12 pixel...
          
          
      pixels.setPixelColor(j, 0x997fb9); // Medo
          

      delay(5); // Pause before next pass through loop
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
  }else if(digitalRead(6)){

    for(int j=0; j < NUMPIXELS; j++) { // For each one of the 12 pixel...
          
          
      pixels.setPixelColor(j, 0x383d98); // Tédio
          

      delay(5); // Pause before next pass through loop
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
  }else if(digitalRead(7)){

    for(int j=0; j < NUMPIXELS; j++) { // For each one of the 12 pixel...
          
          
      pixels.setPixelColor(j, 0x53b147); // Nojinho
          

      delay(5); // Pause before next pass through loop
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
  }else if(digitalRead(8)){

    for(int j=0; j < NUMPIXELS; j++) { // For each one of the 12 pixel...
          
          
      pixels.setPixelColor(j, 0x08847a); // inveja
          

      delay(5); // Pause before next pass through loop
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
  }
}
