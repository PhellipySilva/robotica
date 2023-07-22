#define led 2
#define micro 3

bool valor = false;

bool estagio1 = false;
bool estagio2 = false;
bool estagio3 = false;

int a = 0;
int b = 0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(micro, INPUT);

  digitalWrite(led, LOW);
}

void loop()
{
  valor = digitalRead(micro);

  if (valor == true && estagio1 == false)
  {
    estagio1 = true;
    a = 0;
  }
  else if (valor == false && estagio1 == true && estagio2 == false)
  {
    estagio2 = true;
    a = 0;
  }

  if (estagio1 == true && estagio2 == false)
  {
    a++;
    if (a > 200)
    {
      estagio1 = false;
    }
  }

  if (estagio2 == true)
  {
    a++;
    if (a > 70)
    {
      if (valor == true && estagio2 == true && estagio3 == false)
      {
        estagio3 = true;
        b = 0;
      }

      if (valor == false && estagio3 == true)
      {
        digitalWrite(led, !digitalRead(led));
        estagio1 = false;
        estagio2 = false;
        estagio3 = false;
        delay(1000);
      }

      if (estagio3 == true)
      {
        b++;
        if (b > 200)
        {
          estagio1 = false;
          estagio2 = false;
          estagio3 = false;
        }
      }
    }
  }

  delayMicroseconds(1); // Pequeno atraso de 1 microssegundo (aproximado)
}
