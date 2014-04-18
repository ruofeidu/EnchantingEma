
const int outputPin = 2;    
const int outputPin2 = 3;    
const int outputPin3 = 4;    
const int outputPin4 = 5;    

const int infraredPin = 8;   
const int threshold = 400; 

boolean inside; 

void setup() {
 pinMode(outputPin, OUTPUT);
 Serial.begin(9600);  
 inside = false; 
 digitalWrite(infraredPin, HIGH);
}

void check() {
  
 Serial.println(analogRead(A0));
  if (analogRead(A0) > threshold) {
    inside = true; 
    Serial.println("!"); 
  } else {
    inside = false; 
  }
}

void moveTree() {
  analogWrite(outputPin, 255); 
  analogWrite(outputPin2, 255); 
  analogWrite(outputPin3, 255); 
  analogWrite(outputPin4, 255);  
}

void stopTree() {
 analogWrite(outputPin, 0); 
 analogWrite(outputPin2, 0); 
 analogWrite(outputPin3, 0); 
 analogWrite(outputPin4, 0); 
}

void loop() {
 check();
  
 if (inside) {
   moveTree(); 
   delay(2000); 
   stopTree(); 
   delay(3000); 
 } else {
   stopTree(); 
 }
}
