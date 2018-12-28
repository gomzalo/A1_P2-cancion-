int LED = 13;
int pin7=7;
int pin6=6;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(pin7,INPUT);
  pinMode(pin6,INPUT);
  Serial.begin(9600);
}
int r1=0;
int r2=0;
bool entro=1;
void loop() {
  //¿Hay información disponible en Serial Port?
  delay(1000);
  r1=digitalRead(pin7);
  r2=digitalRead(pin6);

  if(r1==0 && r2==0){ 
    if(!entro){
      Serial.println("3");
      entro =1;
    }
  }else if(r1==0 && r2==1){
    if(entro){
      Serial.println("0");
      entro =0;
    } 
    
  }else if(r1==1 && r2==0){
    if(entro){
      Serial.println("1");
      entro =0;
    } 
    
  }else if(r1=1 && r2==1){
    if(entro){
      Serial.println("2");
      entro =0;
    } 
    
  }
  
  //delay(30000);
   
}


bool verificarDato(int dato){
  bool bandera = false;
  String output = "";
  switch(dato){
    case '0':
      digitalWrite(LED, 0);

      output = "Apagado @ ";
      output += millis();
      output += "ms";
      //Imprimiendo en consola
      Serial.println(output);
      output = "";
      bandera = true;
      break;
    case '1':
      //Si es diferente de 1
      digitalWrite(LED, 1);
      
      output = "Encendido @ ";
      output += millis();
      output += "ms";
      //Imprimiendo en consola
      Serial.println(output);
      output = "";
      bandera = false;
      break;
    default:
      //Si es diferente de 1
      digitalWrite(LED, 0);
      
      output = "Adios vaquero @";
      output += millis();
      output += "ms";
      //Imprimiendo en consola
      Serial.println(output);
      output = "";
      break;

      return bandera;
  }
//  if(input == '1'){
//      
//    } else if (input == '0'){
//      
//    } else {
//      
//    }
}

