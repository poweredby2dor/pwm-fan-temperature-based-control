
#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
#define pwm 9
int analogPin = 0; // Senzor temperatura in A0  
int voltaj1 = 0;
float temp1 = 0;
float average = 0;
float proc1 = 0;
int pwm1 = 0;
int timer = 20; // Durata secventei / loop-ului

void setup()
{
 lcd.begin(16, 2);
 lcd.clear();
 lcd.print(" Proiect - A.C. ");
 lcd.setCursor(0,1);
 lcd.print(" Chivu & Cernat ");

 timer = timer * 200;
 delay(10000);
 analogWrite(pwm, 255);
 lcd.clear();
 lcd.print("Control turatie");
 lcd.setCursor(0,1);
 lcd.print("ventilator ");
 delay(5000);
 analogWrite(pwm, 0);
 lcd.clear();
}
void loop()
{
  voltaj1 = analogRead(analogPin);
  temp1 = voltaj1 * 0.3 - 26 ; // y=Ax + B
  lcd.setCursor(0,0);
  lcd.print("T1: ");
  lcd.print(temp1, 1);   // Afiseaza temperatura de la Senzorul 1, reduce zecimalele la 0
  lcd.print(" Celsius   ");
  average = temp1; // Average e calculat doar cu temp1 intrucat ar fi luat si valoarea de la final de loop
  delay(timer);

  voltaj1 = analogRead(analogPin);
  temp1 = voltaj1 * 0.3 - 26 ; // y=Ax + B
  lcd.setCursor(0,0);
  lcd.print("T1: ");
  lcd.print(temp1, 1);   // Afiseaza temperatura de la Senzorul 1, reduce zecimalele la 0
  lcd.print(" Celsius   ");
  average = average + temp1;
  delay(timer);

  voltaj1 = analogRead(analogPin);
  temp1 = voltaj1 * 0.3 - 26 ; // y=Ax + B
  lcd.setCursor(0,0);
  lcd.print("T1: ");
  lcd.print(temp1, 1);   // Afiseaza temperatura de la Senzorul 1, reduce zecimalele la 0
  lcd.print(" Celsius   ");
  average = average + temp1;
  delay(timer);

  voltaj1 = analogRead(analogPin);
  temp1 = voltaj1 * 0.3 - 26 ; // y=Ax + B
  lcd.setCursor(0,0);
  lcd.print("T1: ");
  lcd.print(temp1, 1);   // Afiseaza temperatura de la Senzorul 1, reduce zecimalele la 0
  lcd.print(" Celsius   ");
  average = average + temp1;
  delay(timer);

  voltaj1 = analogRead(analogPin);
  temp1 = voltaj1 * 0.3 - 26 ; // y=Ax + B
  lcd.setCursor(0,0);
  lcd.print("T1: ");
  lcd.print(temp1, 1);   // Afiseaza temperatura de la Senzorul 1, reduce zecimalele la 0
  lcd.print(" Celsius   ");
  average = average + temp1;
  delay(timer);
  
  lcd.setCursor(0,1);

  // Calcul procent / turatie
  average = average / 5; // Media temperaturii pe 5 citiri, cele de mai sus

  if ( average < 23 )
    { 
      analogWrite(pwm,0);
      lcd.print("Ventilator oprit ");
    }
  else if ( average > 39 )
    {
      analogWrite(pwm, 255);
      lcd.print("Turatie: 100%   ");
    }
  else
      {
        proc1 = average * 5.88 - 135.24;
        pwm1 = average * 15 - 345;
        if ( pwm1 < 25 )
          pwm1 = 0; // Protectie ventilator
        analogWrite(pwm, pwm1);       // Setarea PWM
        lcd.print("RPM%:"); 
        lcd.print(proc1, 0);
        lcd.print(" PWM:");
        lcd.print(pwm1);
        lcd.print("     ");
      }   
}
