
#include<LiquidCrystal.h>
LiquidCrystal lcd (A0,A1,A2,A3,A4,A5);

String card  = "";
String card1 = "4D00864B8505";  //product 1 Coke
String card2 = "4D00864B6FEF";  //product 2 Shampoo
String card3 = "4D00864BA424";  //product 3 Book
String card4 = "4D00864B62E2";  //product 4 Snack

int p1=50,p2=100,p3=200,p4=500,total=0,gtotal=0;
int pc1=0,pc2=0,pc3=0,pc4=0,q1,q2,q3,q4;
boolean  st_cmp = false;
unsigned char Count=0;
#define sw1 4
#define sw2 5
int flag1=0;

void setup()
{
Serial.begin(9600);
lcd.begin (16,2);
Serial.println("WELCOME");
pinMode(sw1, INPUT);
pinMode(sw2, INPUT);
lcd.clear ();
lcd.setCursor (4,0);
lcd.print (F("WELCOME "));
lcd.setCursor (0,1);
lcd.print (F(" ................. "));
delay(1000);

lcd.clear();
lcd.setCursor (0,0);
lcd.print (F("SMART TROLLEY"));
lcd.setCursor (0,1);
lcd.print (F("USING RFID"));

delay (1000);

lcd.clear();
card.reserve(12);
lcd.setCursor (0,0);
lcd.print (F("PLS SHOW CARD"));
}

void loop() {
  if (st_cmp)
  {
    if (card == card1)
    {
      q1=q1+1;
      pc1=p1;
      gtotal=total+pc1+pc2+pc3+pc4; 
      Serial.println(F("PRODUCT 1:50"));
      lcd.setCursor (0,1);
      lcd.print (F("P1:"));lcd.print(pc1);
      Serial.print(F("P1 Qty:"));Serial.println(q1);
      delay(1000);
      while(1){
      if(digitalRead(sw1)==0){
        q1=q1+1;
        pc1=pc1+p1;
        Serial.print(F("P1 Qty:"));Serial.println(q1);
        lcd.setCursor (0,1);
        lcd.print (F("P1:"));lcd.print(pc1);        
      }
      if(digitalRead(sw2)==0){      
      gtotal=total+pc1+pc2+pc3+pc4; 
      Serial.print(F("Total: "));
      Serial.print(F("\t"));
      Serial.println(gtotal);
      lcd.setCursor (10,1);
      lcd.print (F("T:"));lcd.print(gtotal);        
      break;
      card = "";
      st_cmp = false;
      }      
    } 
 }
  else if (card == card2)
    {
      q2=q2+1;
      pc2=p2;
      gtotal=total+pc1+pc2+pc3+pc4; 
      Serial.println(F("PRODUCT 2:100"));
      lcd.setCursor (0,1);
      lcd.print (F("P2:"));lcd.print(pc2);
      Serial.print(F("P2 Qty:"));Serial.println(q2);
      delay(1000);
      while(1){
      if(digitalRead(sw1)==0){
        q2=q2+1;
        pc2=pc2+p2;
        Serial.print(F("P2 Qty:"));Serial.println(q2);
        lcd.setCursor (0,1);
        lcd.print (F("P2:"));lcd.print(pc2);        
      }
      if(digitalRead(sw2)==0){      
      gtotal=total+pc1+pc2+pc3+pc4; 
      Serial.print(F("Total: "));
      Serial.print(F("\t"));
      Serial.println(gtotal);
      lcd.setCursor (10,1);
      lcd.print (F("T:"));lcd.print(gtotal);        
      break;
      card = "";
      st_cmp = false;
      }      
    }
  }
      else if (card == card3)
    {
      q3=q3+1;
      pc3=p3;
      gtotal=total+pc1+pc2+pc3+pc4; 
      Serial.println(F("PRODUCT 3:200"));
      lcd.setCursor (0,1);
      lcd.print (F("P3:"));lcd.print(pc3);
      Serial.print(F("P3 Qty:"));Serial.println(q3);
      delay(1000);
      while(1){
      if(digitalRead(sw1)==0){
        q3=q3+1;
        pc3=pc3+p3;
        Serial.print(F("P3 Qty:"));Serial.println(q3);
        lcd.setCursor (0,1);
        lcd.print (F("P3:"));lcd.print(pc3);        
      }
      if(digitalRead(sw2)==0){      
      gtotal=total+pc1+pc2+pc3+pc4; 
      Serial.print(F("Total: "));
      Serial.print(F("\t"));
      Serial.println(gtotal);
      lcd.setCursor (10,1);
      lcd.print (F("T:"));lcd.print(gtotal);        
      break;
      card = "";
      st_cmp = false;
      }      
    } 
 }
 else if (card == card4)
    {
      q4=q4+1;
      pc4=p4;
      gtotal=total+pc1+pc2+pc3+pc4; 
      Serial.println(F("PRODUCT 4:500"));
      lcd.setCursor (0,1);
      lcd.print (F("P4:"));lcd.print(pc4);
      Serial.print(F("P4 Qty:"));Serial.println(q4);
      delay(1000);
      while(1){
      if(digitalRead(sw1)==0){
        q4=q4+1;
        pc4=pc4+p4;
        Serial.print(F("P4 Qty:"));Serial.println(q4);
        lcd.setCursor (0,1);
        lcd.print (F("P4:"));lcd.print(pc4);        
      }
      if(digitalRead(sw2)==0){      
      gtotal=total+pc1+pc2+pc3+pc4; 
      Serial.print(F("Total: "));
      Serial.print(F("\t"));
      Serial.println(gtotal);
      lcd.setCursor (10,1);
      lcd.print (F("T:"));lcd.print(gtotal);        
      break;
      card = "";
      st_cmp = false;
      }      
    } 
 }

 }
}

void serialEvent()
{
  int i = 0;
  while (i < 12 )
  {
    while (Serial.available())
    {
      char inchar = Serial.read();
      card += inchar;
      i++;
    Serial.print(inchar);
 //   Serial.print("\r\n");
    }   
  } 
  st_cmp = true;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
