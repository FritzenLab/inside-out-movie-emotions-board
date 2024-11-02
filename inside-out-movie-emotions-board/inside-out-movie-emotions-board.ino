#define LED D7
#define TOUCH D8

long oldtime;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(TOUCH, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() - oldtime > 200){
    oldtime= millis();
    
    if(digitalRead(TOUCH)){
      digitalWrite(LED, !digitalRead(LED));
    }
    
    
  }
  
}