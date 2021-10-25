#define RST 12
#define CE  11
#define DC  10
#define DIN  9
#define CLK  8
#define Bup 7
#define Bok 4
#define Bdwn 2
#define Dlit 5
#define Flit 6

static const byte ASCII[][5] =
{
 {0x00, 0x00, 0x00, 0x00, 0x00} // 20  
,{0x00, 0x00, 0x5f, 0x00, 0x00} // 21 !
,{0x00, 0x07, 0x00, 0x07, 0x00} // 22 "
,{0x14, 0x7f, 0x14, 0x7f, 0x14} // 23 #
,{0x24, 0x2a, 0x7f, 0x2a, 0x12} // 24 $
,{0x23, 0x13, 0x08, 0x64, 0x62} // 25 %
,{0x36, 0x49, 0x55, 0x22, 0x50} // 26 &
,{0x00, 0x05, 0x03, 0x00, 0x00} // 27 '
,{0x00, 0x1c, 0x22, 0x41, 0x00} // 28 (
,{0x00, 0x41, 0x22, 0x1c, 0x00} // 29 )
,{0x14, 0x08, 0x3e, 0x08, 0x14} // 2a *
,{0x08, 0x08, 0x3e, 0x08, 0x08} // 2b +
,{0x00, 0x50, 0x30, 0x00, 0x00} // 2c ,
,{0x08, 0x08, 0x08, 0x08, 0x08} // 2d -
,{0x00, 0x60, 0x60, 0x00, 0x00} // 2e .
,{0x20, 0x10, 0x08, 0x04, 0x02} // 2f /
,{0x3e, 0x51, 0x49, 0x45, 0x3e} // 30 0
,{0x00, 0x42, 0x7f, 0x40, 0x00} // 31 1
,{0x42, 0x61, 0x51, 0x49, 0x46} // 32 2
,{0x21, 0x41, 0x45, 0x4b, 0x31} // 33 3
,{0x18, 0x14, 0x12, 0x7f, 0x10} // 34 4
,{0x27, 0x45, 0x45, 0x45, 0x39} // 35 5
,{0x3c, 0x4a, 0x49, 0x49, 0x30} // 36 6
,{0x01, 0x71, 0x09, 0x05, 0x03} // 37 7
,{0x36, 0x49, 0x49, 0x49, 0x36} // 38 8
,{0x06, 0x49, 0x49, 0x29, 0x1e} // 39 9
,{0x00, 0x36, 0x36, 0x00, 0x00} // 3a :
,{0x00, 0x56, 0x36, 0x00, 0x00} // 3b ;
,{0x08, 0x14, 0x22, 0x41, 0x00} // 3c <
,{0x14, 0x14, 0x14, 0x14, 0x14} // 3d =
,{0x00, 0x41, 0x22, 0x14, 0x08} // 3e >
,{0x02, 0x01, 0x51, 0x09, 0x06} // 3f ?
,{0x32, 0x49, 0x79, 0x41, 0x3e} // 40 @
,{0x7e, 0x11, 0x11, 0x11, 0x7e} // 41 A
,{0x7f, 0x49, 0x49, 0x49, 0x36} // 42 B
,{0x3e, 0x41, 0x41, 0x41, 0x22} // 43 C
,{0x7f, 0x41, 0x41, 0x22, 0x1c} // 44 D
,{0x7f, 0x49, 0x49, 0x49, 0x41} // 45 E
,{0x7f, 0x09, 0x09, 0x09, 0x01} // 46 F
,{0x3e, 0x41, 0x49, 0x49, 0x7a} // 47 G
,{0x7f, 0x08, 0x08, 0x08, 0x7f} // 48 H
,{0x00, 0x41, 0x7f, 0x41, 0x00} // 49 I
,{0x20, 0x40, 0x41, 0x3f, 0x01} // 4a J
,{0x7f, 0x08, 0x14, 0x22, 0x41} // 4b K
,{0x7f, 0x40, 0x40, 0x40, 0x40} // 4c L
,{0x7f, 0x02, 0x0c, 0x02, 0x7f} // 4d M
,{0x7f, 0x04, 0x08, 0x10, 0x7f} // 4e N
,{0x3e, 0x41, 0x41, 0x41, 0x3e} // 4f O
,{0x7f, 0x09, 0x09, 0x09, 0x06} // 50 P
,{0x3e, 0x41, 0x51, 0x21, 0x5e} // 51 Q
,{0x7f, 0x09, 0x19, 0x29, 0x46} // 52 R
,{0x46, 0x49, 0x49, 0x49, 0x31} // 53 S
,{0x01, 0x01, 0x7f, 0x01, 0x01} // 54 T
,{0x3f, 0x40, 0x40, 0x40, 0x3f} // 55 U
,{0x1f, 0x20, 0x40, 0x20, 0x1f} // 56 V
,{0x3f, 0x40, 0x38, 0x40, 0x3f} // 57 W
,{0x63, 0x14, 0x08, 0x14, 0x63} // 58 X
,{0x07, 0x08, 0x70, 0x08, 0x07} // 59 Y
,{0x61, 0x51, 0x49, 0x45, 0x43} // 5a Z
,{0x00, 0x7f, 0x41, 0x41, 0x00} // 5b [
,{0x02, 0x04, 0x08, 0x10, 0x20} // 5c ¥
,{0x00, 0x41, 0x41, 0x7f, 0x00} // 5d ]
,{0x04, 0x02, 0x01, 0x02, 0x04} // 5e ^
,{0x40, 0x40, 0x40, 0x40, 0x40} // 5f _
,{0x00, 0x01, 0x02, 0x04, 0x00} // 60 `
,{0x20, 0x54, 0x54, 0x54, 0x78} // 61 a
,{0x7f, 0x48, 0x44, 0x44, 0x38} // 62 b
,{0x38, 0x44, 0x44, 0x44, 0x20} // 63 c
,{0x38, 0x44, 0x44, 0x48, 0x7f} // 64 d
,{0x38, 0x54, 0x54, 0x54, 0x18} // 65 e
,{0x08, 0x7e, 0x09, 0x01, 0x02} // 66 f
,{0x0c, 0x52, 0x52, 0x52, 0x3e} // 67 g
,{0x7f, 0x08, 0x04, 0x04, 0x78} // 68 h
,{0x00, 0x44, 0x7d, 0x40, 0x00} // 69 i
,{0x20, 0x40, 0x44, 0x3d, 0x00} // 6a j 
,{0x7f, 0x10, 0x28, 0x44, 0x00} // 6b k
,{0x00, 0x41, 0x7f, 0x40, 0x00} // 6c l
,{0x7c, 0x04, 0x18, 0x04, 0x78} // 6d m
,{0x7c, 0x08, 0x04, 0x04, 0x78} // 6e n
,{0x38, 0x44, 0x44, 0x44, 0x38} // 6f o
,{0x7c, 0x14, 0x14, 0x14, 0x08} // 70 p
,{0x08, 0x14, 0x14, 0x18, 0x7c} // 71 q
,{0x7c, 0x08, 0x04, 0x04, 0x08} // 72 r
,{0x48, 0x54, 0x54, 0x54, 0x20} // 73 s
,{0x04, 0x3f, 0x44, 0x40, 0x20} // 74 t
,{0x3c, 0x40, 0x40, 0x20, 0x7c} // 75 u
,{0x1c, 0x20, 0x40, 0x20, 0x1c} // 76 v
,{0x3c, 0x40, 0x30, 0x40, 0x3c} // 77 w
,{0x44, 0x28, 0x10, 0x28, 0x44} // 78 x
,{0x0c, 0x50, 0x50, 0x50, 0x3c} // 79 y
,{0x44, 0x64, 0x54, 0x4c, 0x44} // 7a z
,{0x00, 0x08, 0x36, 0x41, 0x00} // 7b {
,{0x00, 0x00, 0x7f, 0x00, 0x00} // 7c |
,{0x00, 0x41, 0x36, 0x08, 0x00} // 7d }
,{0x10, 0x08, 0x08, 0x10, 0x08} // 7e ←
,{0x78, 0x46, 0x41, 0x46, 0x78} // 7f →
};

#include "kanak.h";        // my logo matrix pixel wise
#include <stdlib.h>;       // to convert the veriable data to string or string pointer
#include <Servo.h>;    

Servo myservo;
int select=0;          
int potpin = A5;
int val;
char s[8];
int bright=45;
unsigned long previousTime = 0;
byte seconds=0 ;
byte minutes=0 ;
byte hours=0 ;
int Fbright=0;



void setup()
{
  Serial.begin(9600); 
  pinMode(RST, OUTPUT);
  pinMode(CE, OUTPUT);
  pinMode(DC, OUTPUT);
  pinMode(DIN, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(Dlit, OUTPUT);
  digitalWrite(RST, LOW);
  digitalWrite(RST, HIGH);
  myservo.attach(3);
  LCDinit();
  Welcome();
 
}


  

void loop()
{

  if (digitalRead(Bup) == HIGH)
  {
    delay(100);
    if (digitalRead(Bup) == HIGH)select=select+1;
  }
  
  if (digitalRead(Bdwn) == HIGH)
   {
    delay(100);
    if (digitalRead(Bdwn) == HIGH)select=select-1;
  }
  if (select >9)select=9;
  if (select<0)select=0;
  LcdXY(57,0);
  LcdWriteString(dtostrf(select,0,0,s));
  if (digitalRead(Bok) == HIGH)
   {
    delay(100);
    if (digitalRead(Bok) == HIGH)Callmenu(select);
  }
}

void kanak(void)
{
   for(int i=0; i<451; i++) LcdWriteData(k_grf[i]);
}



void Welcome(void)
{
  LcdXY(0,0);
  kanak();
  LcdXY(37,3);
  LcdWriteString("HI");
  delay(1000);
  LCDclr();
  LcdXY(24,0);
  LcdWriteString("WELCOME");
  LcdXY(42,2);
  LcdWriteString("TO");
  LcdXY(17,5);
  LcdWriteString("B Bike");
  delay(2000);
  LcdXY(5,2);
  LcdWriteString("If found pls.");
  LcdXY(10,3);
  LcdWriteString("01738889858");
  delay(3000);
  LCDclr();
  
  mainmenu();
}




void Callmenu(int a)
{
  if(a==0)ServoCon();
  if(a==1)TempMeter();
  if(a==2)LightMeter();
  if(a==3)time();  
  if(a==4)Display();
  
  if(a==6)voltmeter();
  if(a==7)Flashlight();
  
  if(a==9)Msg();
  
}

void mainmenu(void)
{ 
  Serial.println("#main_menu");
  LCDclr();
  LcdXY(27,0);
  LcdWriteString("Menu-");
  LcdXY(0,1);
  LcdWriteString("0-Srv");
  LcdXY(0,2);
  LcdWriteString("1-Tmp");
  LcdXY(0,3);
  LcdWriteString("2-Lit");
  LcdXY(0,4);
  LcdWriteString("3-Clok");
  LcdXY(0,5);
  LcdWriteString("4-D-Br");
  LcdXY(42,1);
  LcdWriteString("5-Speed");
  LcdXY(42,2);
  LcdWriteString("6-V-M");
  LcdXY(42,3);
  LcdWriteString("7-F-lit");
  LcdXY(42,4);
  LcdWriteString("8-GPS");
  LcdXY(42,5);
  LcdWriteString("9-Msg");
}



  void ServoCon(void)
  {   
      Serial.println("Showing Servo Meter");
      LCDclr();
      LcdXY(17,0);
      LcdWriteString("Servo Met.");  
      LcdXY(0,3);
      LcdWriteString("Pos:");
      LcdXY(0,4);
      LcdWriteString("Cir:");
      LcdXY(0,5);
      LcdWriteString("Swi:");
      LcdXY(70,3);
      LcdWriteString("D");
      while(1)
      {
        
       Serial.println("Now servo at "); 
       int pot = analogRead(potpin);
       pot = map(pot, 0, 1023, 0, 179); 
       int mov=pot+val;
        myservo.write(mov);
        delay(15);
        LcdXY(35,3);
        LcdWriteString(dtostrf(mov,4,2,s));
         LcdXY(35,4);
        LcdWriteString(dtostrf(pot,4,2,s));
         LcdXY(35,5);
        LcdWriteString(dtostrf(val,4,2,s));
          if (digitalRead(Bup) == HIGH)
            {
             delay(100);
             if (digitalRead(Bup) == HIGH)val=val+5;
            }
  
          if (digitalRead(Bdwn) == HIGH)
           {
            delay(100);
            if (digitalRead(Bdwn) == HIGH)val=val-5;
          }
          if (digitalRead(Bok) == HIGH)
           {
            delay(100);
            if (digitalRead(Bok) == HIGH)
            mainmenu();
            return;
          }
            if(val<0)
       {
        val=0;
       }
       if(mov<0)
       {
        mov=0;
       }
         if(mov>180)
       {
        mov=180;
        val=180-pot;
       }
      }
  }
  
  
  
  
  
  
  void Display(void)        // for display brightness 
  {  LCDclr();
      LcdXY(10,0);
      LcdWriteString("Brightness");  
      LcdXY(0,3);
      LcdWriteString("Now:");
      LcdXY(70,3);
      LcdWriteString("%");    
    
        while(1)
        {
        analogWrite(Dlit,bright);
         if (digitalRead(Bup) == HIGH)
          {
            delay(100);
            if (digitalRead(Bup) == HIGH)bright=bright+20;
          }
          
         if (digitalRead(Bdwn) == HIGH)
           {
            delay(100);
            if (digitalRead(Bdwn) == HIGH)bright=bright-20;
           }
          if (bright >255)bright=255;
          if (bright<0)bright=0;
          if (digitalRead(Bok) == HIGH)
            {
              delay(100);
              if (digitalRead(Bok) == HIGH)
              mainmenu();
              return; 
             }
         int val_bright = map(bright, 0, 255, 0, 100);
          LcdXY(30,3);
          LcdWriteString(dtostrf(val_bright,3,0,s));       
         }
  } 
  
  
  
   void Flashlight(void)        // for flash brightness 
  {  LCDclr();
      LcdXY(5,0);
      LcdWriteString("Flash Bright:"); 
      LcdXY(70,3);
      LcdWriteString("%");    
    
        while(1)
        {
          analogWrite(Flit,Fbright);
         if (digitalRead(Bup) == HIGH)
          {
            delay(100);
            if (digitalRead(Bup) == HIGH)Fbright=Fbright+20;
          }
          
         if (digitalRead(Bdwn) == HIGH)
           {
            delay(100);
            if (digitalRead(Bdwn) == HIGH)Fbright=Fbright-20;
           }
          if (Fbright >255)Fbright=255;
          if (Fbright<0)Fbright=0;
          if (digitalRead(Bok) == HIGH)
            {
              delay(100);
              if (digitalRead(Bok) == HIGH)
              mainmenu();
              return; 
             }
         int val_bright = map(Fbright, 0, 255, 0, 100);
          LcdXY(30,3);
          LcdWriteString(dtostrf(val_bright,3,0,s));       
         }
  } 
  
  
  
  
  
  
  
  void Msg(void)                                                  //for about my self
  {
    LCDclr();
      LcdXY(0,0);
      LcdWriteString("Hi this is kanak."); 
     while(1)
     {
     
      if (digitalRead(Bok) == HIGH)
           {
            delay(100);
            if (digitalRead(Bok) == HIGH)
            mainmenu();
            return; 
           } 
     }

}
  
  void TempMeter(void)        //temparature meter.
  {
      LCDclr();
      LcdXY(17,0);
      LcdWriteString("Temp. Met.");  
      LcdXY(0,3);
      LcdWriteString("Temp:");
      LcdXY(70,3);
      LcdWriteString("C");
    while(1)
    {
      float temp = analogRead(A0)* 0.48828125;
      LcdXY(35,3);
      LcdWriteString(dtostrf(temp,4,2,s));
      delay(500); 
       if (digitalRead(Bok) == HIGH)
           {
            delay(100);
            if (digitalRead(Bok) == HIGH)
            mainmenu();
            return;
          } 
     }
  }
  
 void LightMeter(void)             //// external light intensity
    {
      LCDclr();
      LcdXY(17,0);
      LcdWriteString("light Met.");  
      LcdXY(0,3);
      LcdWriteString("Intensit:");
      LcdXY(75,3);
      LcdWriteString("%");
    while(1)
    {
      float light = analogRead(A1);
      LcdXY(55,3);
      int val_bright = map(light, 0, 1023, 0, 100);
      LcdWriteString(dtostrf(light,3,0,s));
      delay(500); 
       if (digitalRead(Bok) == HIGH)
           {
            delay(50);
            if (digitalRead(Bok) == HIGH)
            mainmenu();
            return;
          } 
     }
  }
  
  
  
void voltmeter(void)

  {
      LCDclr();
      LcdXY(17,0);
      LcdWriteString("Battry Met.");  
      LcdXY(0,3);
      LcdWriteString("Charge:");
      LcdXY(78,3);
      LcdWriteString("%");
    while(1)
    {
      float Bat = analogRead(A2);
      LcdXY(45,3);
      int val_bright = map(Bat, 0, 1023, 0, 100);
      LcdWriteString(dtostrf(Bat,4,2,s));
      delay(500); 
       if (digitalRead(Bok) == HIGH)
           {
            delay(50);
            if (digitalRead(Bok) == HIGH)
            mainmenu();
            return;
          } 
     }
  }
  
  
  
  
  
  
  void time(void)                          // to display clock in clock section
  {
    int i=0;
    int inc_m,inc_h=0, r_min, r_hour=0;
    LCDclr();
      LcdXY(10,0);
      LcdWriteString("Time & Date");  
      LcdXY(0,3);
      LcdWriteString("Time:");
      LcdXY(0,4);
      LcdWriteString("Date:");
    while(1)
  {
             if (digitalRead(Bup) == HIGH)
              {
                delay(100);
                if (digitalRead(Bup) == HIGH)hours=hours+1;
              }
          
             if (digitalRead(Bdwn) == HIGH)
               {
                delay(100);
                if (digitalRead(Bdwn) == HIGH)minutes=minutes+1;
               }
             if (digitalRead(Bok) == HIGH)
                {
                  delay(100);
                  if (digitalRead(Bok) == HIGH)
                  mainmenu();
                  return;
                } 
      if (millis() >= (previousTime)) 
        {
             previousTime = previousTime + 1000;  // use 100000 for uS
             seconds = seconds +1;
             LcdXY(58,3);
             LcdWriteString(dtostrf(seconds,2,0,s));
             if (seconds == 60)
             {
                seconds = 0;
                minutes = minutes +1;
                LcdXY(43,3);
                LcdWriteString(dtostrf(minutes,2,0,s));
                
             }
             if (minutes == 60)
             {
                minutes = 0;
                hours = hours +1;
                LcdXY(28,3);
          LcdWriteString(dtostrf(hours,2,0,s));

             }
             if (hours ==13)
             {
                hours = 1;
                i=!i;                
             }
      if (i==0)
      {
        LcdXY(76,3);
        LcdWriteString("a"); 
      }
                  
        }
  if (hours ==13)
             {
                hours = 1;
                i=!i;                
             }
         if (minutes ==60)
             {
                minutes = 0;              
             }
        if (i==1)
        {
  LcdXY(76,3);
  LcdWriteString("p"); 
  }
        if (i==0)
  {
   LcdXY(76,3);
   LcdWriteString("a"); 
  }
        LcdXY(58,3);
        LcdWriteString(dtostrf(seconds,2,0,s));
  LcdXY(28,3);
  LcdWriteString(dtostrf(hours,2,0,s));
  LcdXY(43,3);
  LcdWriteString(dtostrf(minutes,2,0,s));
     }
  }
  
  
  
  
  
  
void LCDinit(void)                                                    // lcd initial or lcd libary code bellow
{
  LcdWriteCmd(0x21);  // LCD extended commands
  LcdWriteCmd(0xB1);  // set LCD Vop (contrast) for other it may be "BF"
  LcdWriteCmd(0x04);  // set temp coefficent
  LcdWriteCmd(0x14);  // LCD bias mode 1:40
  LcdWriteCmd(0x20);  // LCD basic commands
  LcdWriteCmd(0x0C);  // LCD normal video  
  for(int i=0; i<504; i++) LcdWriteData(0x00); // clear LCD
  analogWrite(Dlit,bright);
}

void LCDclr(void)
{
  for(int i=0; i<504; i++) LcdWriteData(0x00);
}


void LcdWriteString(char *characters)
{
  while(*characters) LcdWriteCharacter(*characters++);
}



void LcdWriteCharacter(char character)
{
  for(int i=0; i<5; i++) LcdWriteData(ASCII[character - 0x20][i]);
  LcdWriteData(0x00);
}



void LcdWriteData(byte dat)
{
  digitalWrite(DC, HIGH); //DC pin is low for commands
  digitalWrite(CE, LOW);
  shiftOut(DIN, CLK, MSBFIRST, dat); //transmit serial data
  digitalWrite(CE, HIGH);
}


void LcdXY(int x, int y)
{
  LcdWriteCmd(0x80 | x);  // Column.
  LcdWriteCmd(0x40 | y);  // Row.
}


void LcdWriteCmd(byte cmd)
{
  digitalWrite(DC, LOW); //DC pin is low for commands
  digitalWrite(CE, LOW);
  shiftOut(DIN, CLK, MSBFIRST, cmd); //transmit serial data
  digitalWrite(CE, HIGH);
}




