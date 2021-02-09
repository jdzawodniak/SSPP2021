
////  Works with the Bluetooth.apk from https://github.com/binaryupdates/arudino-hc05-bluetooth to light light no pin 11


char Incoming_value = 0;
                
void setup() 
{
  Serial.begin(9600);         
  pinMode(11, OUTPUT);       
}

void loop()
{
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      
    Serial.print(Incoming_value);        
    Serial.print("\n");        
    if(Incoming_value == '1')             
      digitalWrite(11, HIGH);  
    else if(Incoming_value == '0')       
      digitalWrite(11, LOW);   
  }                            
} 
