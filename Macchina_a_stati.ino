void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

int status = 0;
String buf;
char ch;

void loop() {
  // put your main code here, to run repeatedly

    switch(status){

    case 0:  if(Serial.available()){ 
                ch = Serial.read();  
                if(ch == '{'){ 
                  status = 1; 
                  buf = "";
                } 
             } 
    break;

    case 1:  if(Serial.available()){ 
                ch = (char) Serial.read();  
                if(ch != '}'){ 
                  buf += ch;
                }else{
                  status = 2;
                }
             } 
    break;

    case 2:  if(buf.equals("on")){
              Serial.println("{ON}");
              digitalWrite(LED_BUILTIN, HIGH);  
             }else if (buf.equals("off")){
              Serial.println("{OFF}");
              digitalWrite(LED_BUILTIN, LOW);
             }else{
              Serial.println("?");
             }
             status = 0;          
    break;   
  } 
}
