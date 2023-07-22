#define led 2
#define micro 3

bool valor=false; 

bool estagio1=false;
bool estagio2=false;
bool estagio3=false;

int a;
int b;


void setup()
{
	pinMode(led, OUTPUT);
  	pinMode(micro, INPUT);
  
  digitalWrite(led, LOW);
}

void loop()
{
	valor = digitalRead(micro);
  
  if(valor==true && estagio1 == false){
    estagio1=true;
    a=0;
  }
    if(valor==false && estagio1 == true && estagio2==false){
    estagio2=true;
    a=0;
  }
    if(estagio1==true && estagio2 == false){
    delay(1);
    a++;
      if(a>200){
        estagio1=false;
  }
      if(estagio2==true){
        
        if(estagio3 == false) {
          delay(1);
          a++;
          if(a>700){
            estagio1=false;
            estagio2=false;
          }
        }
        if(a>70){
          if(valor==true && estagio2==true && estagio3==false){
            estagio3=true;
            b=0;
          }
          
          
          if(valor==false && estagio3 == true){
            digitalWrite(led, !digitalRead(led));
            estagio1=false;
            estagio2=false;
            estagio3=false;
            delay(1000);
          }
          
          if(estagio3==true){
            delay(1);
            b++;
            if(b>200){
              estagio1=false;
              estagio2=false;
              estagio3=false;
            }
          }
        }
      }
  delayMicroseconds(1/44100*1000000);

}