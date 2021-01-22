#include <Servo.h>
#include <math.h> 
#define trigPin 12
#define echoPin 13
float H=0;
float H1=0; //H = height(); to measurement height

Servo myservos[7];  // create servo object to control servo1
int pos[7] = {0};double sideangle[3];double T1[181]={0};double servo[3];int angle[6];
double L1X,L1Y,L2X,L2Y,L3X,L3Y,RX,RY,BX,BY,GX,GY,OX,OY,YX,YY;
int loadpointflag1=0;
/*
///////// use to update angle///////////// 4 angle are required rest just for gripper

  angle[0]= servo[0];
moveservo( angle[0], angle[1], angle[2], angle[3], angle[4], angle[5], angle[6]);
  angle[1]= servo[1];
  angle[2]= servo[2];
  angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3], angle[4], angle[5], angle[6]);

/////////////////////
*/

void setup() {
////////////////////////////ULTSNRNGFND//////////////////////////////////////////////////
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
////////////////////////////////////////////////////
/////////////////////////////////////Set up Servo on Arduino/////////////////////////////
for (int i=0;i<7;i++){myservos[i].attach(i+2);}
myservos[0].write(90);
myservos[1].write(65);
myservos[2].write(125);
myservos[3].write(95);
myservos[4].write(90);
myservos[5].write(90);
////////////////////////////////////////////////////

Serial.begin(57600);
Serial.println();
Serial.print("Enter L1X,L1Y,L2X,L2Y,L3X,L3Y,RX,RY,BX,BY,GX,GY,OX,OY,YX,YY");

while(Serial.available() == 0) 
  {}
double xy[24];

  for(int i=0;i<24;i++)
  {
 xy[i] = Serial.parseInt();
    }
L1X =xy[0];L1Y =xy[1];L2X =xy[2];L2Y =xy[3];L3X =xy[4];L3Y =xy[5];RX =xy[6];RY =xy[7];BX =xy[8];BY =xy[9];GX =xy[10];GY =xy[11];OX =xy[12];OY =xy[13];YX =xy[14];YY=xy[15];
// 110,250,380,120,430,230,160,140,250,90,290,80,470,60,520,190
///////////////////////////////////////////////////
}


////////////////////////////////////////////////Note for all Function/////////////////////////////////////
/*
  moveservo(int a, int b, int c, int d, int e, int f, int g) to apply angles in all servo  
  safeposition()  to move arm upwords to avoid obstacles
  getposition()  to print current servo position    position will be get in servo[i] terms
  findangle(double K1,double X1, double Z) to find all required angles to reach X,Y,Z position on board
 */
/////////////////////////////////////////////////////////////////////////////////////////////////
// left 60 open 90 close right 110 open 90 close   90 90 open 110 75 close
//////////////////////////////////////// MAIN CODE /////////////////////////////////////
//////////////////////////////////////// MAIN CODE /////////////////////////////////////
//////////////////////////////////////// MAIN CODE /////////////////////////////////////
//////////////////////////////////////// MAIN CODE /////////////////////////////////////
void loop() {
  
if (loadpointflag1==0)
{
findsideangle(L1X,L1Y,50);
angle[0]= servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3],  90,90,90);
delay(1000);
H = (int)round((height()-30)*(-1));
Serial.print("Cube Height = ");Serial.println(H);

//
//if (H<10){Serial.print("Cube Height = ");Serial.println(" No Cube Present");}
//if (10<H<30){Serial.print("Cube Height = ");Serial.println(" 20 mm");}
//if (30<H<50){Serial.print("Cube Height = ");Serial.println(" 40 mm");}
//if (50<H<70){Serial.print("Cube Height = ");Serial.println(" 60 mm");}
//if (70<H<90){Serial.print("Cube Height = ");Serial.println(" 80 mm");}
//if (90<H<110){Serial.print("Cube Height = ");Serial.println(" 100 mm");}
//if (110<H<130){Serial.print("Cube Height = ");Serial.println(" 120 mm");}
/*
angle[0]=90;
safeposition();
delay(5000);
opengrip();delay(500);closegrip();delay(500);opengrip();delay(500);



findsideangle(L1X,L1Y,100);
angle[0]= servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3], 90,90,90);
delay(2000);
findsideangle(L1X,L1Y,80);
angle[0]= servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3], 90,90,90);
delay(2000);
findsideangle(L1X,L1Y,70);
angle[0]= servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3], 90,90,90);
delay(2000);
findsideangle(L1X,L1Y,50);
angle[0]= servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3],  90,90,90);
delay(1000);
//opengrip();
//delay(2000);
findsideangle(L1X,L1Y,40);
angle[0]= servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3],  90,90,90);
delay(1000);
findsideangle(L1X,L1Y,20);
angle[0]= servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3],  90,90,90);
delay(1000);
findsideangle(L1X,L1Y,0);
angle[0]= servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3],  90,90,90);
delay(2000);
findsideangle(L1X,L1Y,20);
angle[0]= servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3],  90,90,90);
delay(2000);
moveservo( angle[0], angle[1], angle[2], angle[3],  90,110,75);
delay(2000);
//opengrip();
//delay(2000);
//closegrip();
//delay(2000);
safeposition();
delay(3000);
safeposition();
delay(2000);

findsideangle(L2X,L2Y,100);
angle[0]= servo[0];
moveservo( angle[0], angle[1], angle[2], angle[3], 90,110,75);
delay(2000);
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3], 90,110,75);
delay(2000);

findsideangle(L2X,L2Y,90);
angle[0]= servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3], 90,110,75);
delay(1000);
findsideangle(L2X,L2Y,80);
angle[0]= servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3], 90,110,75);
delay(1000);
findsideangle(L2X,L2Y,70);
angle[0]= servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3], 90,110,75);
delay(1000);
findsideangle(L2X,L2Y,60);
angle[0]= servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3], 90,110,75);
delay(1000);
findsideangle(L2X,L2Y,50);
angle[0]= servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3], 90,110,75);
delay(500);
findsideangle(L2X,L2Y,40);
angle[0]= servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3], 90,110,75);
delay(1000);
findsideangle(L2X,L2Y,30);
angle[0]= servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3], 90,110,75);
delay(1000);
findsideangle(L2X,L2Y,20);
angle[0]= servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3], 90,110,75);
delay(1000);
findsideangle(L2X,L2Y,0);
angle[0]= servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo( angle[0], angle[1], angle[2], angle[3], 90,110,75);
delay(2000);
moveservo( angle[0], angle[1], angle[2], angle[3], 90,90,90);
delay(2000);
//opengrip();
//delay(2000);
safeposition();
delay(2000);
safeposition();
delay(3000);
//loadpointflag1=1;
/*
findsideangle(L1X,L1Y,70);
delay(2000);
angle[0]=servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo(angle[0],angle[1],angle[2],angle[3],90,90,90);
delay(2000);  

findsideangle(L1X,L1Y,0);
delay(2000);
angle[0]=servo[0];
angle[1]= servo[1];
angle[2]= servo[2];
angle[3]= servo[3];
moveservo(angle[0],angle[1],angle[2],angle[3],90,90,90);
delay(2000);  
*/
//loadpointflag1=1;


}

}
//////////////////////////////////////// END MAIN CODE /////////////////////////////////////
////////////////////////////////////////END MAIN CODE /////////////////////////////////////
////////////////////////////////////////END MAIN CODE /////////////////////////////////////
////////////////////////////////////////END MAIN CODE /////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////End Function to move servo position////////////////////////////////////////////////////////////////////////////


  
///////////////////////////////////////////////////////////////////////////////Function to find all angle using X,Y,X////////////////////////////////////////////////////////////////////////////

void findsideangle(double K1,double X1, double Z)
{
double fi,Y,theta1,T2,T3,T4,a,T2X,T2Y,X,ZX,K;
////////////////////////////////////////////////////////for base angle//////////////////////////////
//ZX=0;fi=0;Y=0;theta1=0;T2=0;T3=0;T4=0;a=0;T2X=0;T2Y=0;X=0;ZX=0;K=0;
K = K1-295;
X = 390-X1;

/////////////Loading Point 1//////////////////
 sideangle[0] = atan(X/K)*(180/PI);
 ZX = X/ sin((sideangle[0])*PI/180);if (ZX<0){ZX=((ZX)*(-1));}
 H1=ZX/10;
 if (sideangle[0]<0){sideangle[0] = 180+ sideangle[0];}

////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int flag=0;
for(int i=0;i<181;i++)
{
  T1[i]=i;
  }
fi = atan((Z+65)/(ZX))*180/PI;
Y = ZX / cos(fi*PI/180);

for(int i=0;i<181;i++)
{

a = sqrt(30625+(Y*Y)-(2*175*Y*cos(T1[i]*PI/180)));
T2Y = acos((30625+(a*a)-(Y*Y))/(2*175*a))*180/PI;
T2X = acos((25600+(a*a)-(22500))/(2*160*a))*180/PI;
T2 = T2X+T2Y+6;
T3 = (acos((48100-(a*a))/48000)*180/PI)+(7);
T4=360-i-T2-T3;
theta1 = 180-7-(fi+T1[i]);
if (theta1>0&&T2>0&&T3>95&&T2<160)
{

if (flag==0)
{
sideangle[1]=theta1;
sideangle[2]=T2;
sideangle[3]=T3;
flag=1;
}
}

}
///////Calibartion////////////
//sideangle[0]=sideangle[0]-5;

//Serial.print("   ZX   ");
//Serial.print(ZX);
Serial.print("   angle[0]   ");
Serial.print(sideangle[0]);
Serial.print("   angle[1]   ");
Serial.print(sideangle[1]);
Serial.print("   angle[2]   ");
Serial.print(sideangle[2]);
Serial.print("   angle[3]   ");
Serial.print(sideangle[3]);
Serial.println();
 for (int i=0;i<4;i++)
{
  servo[i]=(int)round(sideangle[i]);
  Serial.print("   Servo ");
  Serial.print(i);
  Serial.print(" : ");
  Serial.print(servo[i]);
  } 

 }
/////////////////////////////////////////////////////////////////////////////END Function to find all angle using X,Y,X////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////// FIND HEIGHT////////////////////////////////
float height()
{

 float duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  
  if (distance >= 400 || distance <= 2){
    Serial.print("Distance = ");
    Serial.println("Out of range");
  }
  else {
    distance = ((distance)*10)-50-H1;
    //Serial.print("Distance = ");
   // Serial.print(distance);
   // Serial.println(" cm");
    delay(250);
  }
 // delay(500);
  return distance;

  }
////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////Servo Functions///////////////////////////////////////////////////////////////////////////////////////////////
void moveservo(int h, int b, int c, int d, int e, int f, int g)
{
 int a[7]={h,b,c,d,e,f,g};
 int inc_dec[7]={1,1,1,1,1,1,1};
  int angfl=0;
  for(int i=0;i<7;i++)
  {
    if(pos[i]>=a[i])
    {
      inc_dec[i]=-1;
    }
  }   
  for(;angfl != 7;)
  {
//Serial.println();
     for(int i=0;i<7;i++)
     {
      for(;pos[i]!=(a[i]);pos[i]=(pos[i]+inc_dec[i])){}
 
      }  
           for(int i=0;i<7;i++)
      {
//      Serial.print("Servo ");
//      Serial.print(i);
//      Serial.print(":");
      myservos[i].write(pos[i]);
      
//      Serial.print(pos[i]);
//      Serial.println(" ");
        
        }
//Serial.println();
angfl=7;
  }
// delay(500); 
  }


void getposition()
{
 for (int i;i<7;i++)
 {
 Serial.print("  Servo  ");
 Serial.print(i);
 Serial.print(" : ");
 Serial.print(angle[i]);
 }
  }   
 void opengrip()
 {
angle[5]= 90;
angle[6]= 90;
 moveservo(angle[0],angle[1],angle[2],angle[3],angle[4],angle[5],angle[6]); 
  } 
  void closegrip()
 {
  angle[5]= 110;
  angle[6]= 75;
 moveservo(angle[0],angle[1],angle[2],angle[3],angle[4],angle[5],angle[6]); 
  }
  void safeposition()
  {
    angle[1]= 35;
    angle[2]=125;
    angle[3]=95;
    angle[5]= 110;
    angle[4]=90;
  angle[6]= 75;
    moveservo(angle[0],angle[1],angle[2],angle[3],angle[4],angle[5],angle[6]);
    }
  void safemove(double a, double b, int c)
  {
    findsideangle(a,b,c);
    angle[0]=servo[0];
    angle[1]=servo[1];
    angle[2]=servo[2];
    angle[3]=servo[3];
    moveservo(angle[0],angle[1],angle[2],angle[3],angle[4],angle[5],angle[6]);
    delay(250);  
    }
//////////////////////////////////////////////////////////////////////////////////////END Servo Functions///////////////////////////////////////////////////////////////////////////////////////////////
