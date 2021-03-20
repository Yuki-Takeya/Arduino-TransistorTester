char SetVoltage[4];
char SetVoltages1 = 0;
char SetVoltages2 = 0;
char SetVoltages3 = 0;
int RealNumberVoltage1=0;
int RealNumberVoltage2=0;
int RealNumberVoltage3=0;
float SetVoltagefloat1=0.0;
float SetVoltagefloat2=0.0;
float SetVoltagefloat3=0.0;
float SetVoltagefloat=0.0;
int PinSet=0;
char Pinset[1];
int FinalPWM=0;
float AnalogRead=0.0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("VoltageGenerator");
  Serial.println("Supported Pin : 3, 5, 6, 9, 10, 11 @ 490 Hz (pins 5 and 6: 980 Hz)");
  Serial.println("Select Pin : ");
  PinSet=0;
  while(true){
    PinSet=0;
    Serial.println("Type In Number");
    Serial.readBytes(Pinset,1);
    PinSet=(int)(Pinset[0])-48;
    if(PinSet != -48){
      PinSet=(int)(Pinset[0])-48;
      break;
    }
  }
 Serial.print("Selected Pin: ");
 Serial.println(PinSet);
}
/* 48-0
 * 49-1
 * 50-2
 * 51-3
 * 52-4
 * 53-5
 * 54-6
 * 55-7
 * 56-8
 * 57-9
 */
void loop() {
  // put your main code here, to run repeatedly:
  
FinalPWM=0;
SetVoltage[0]=48;
SetVoltage[2]=48;
SetVoltage[3]=48;
SetVoltages1 = 48;
SetVoltages2 = 48;
SetVoltages3 = 48;
RealNumberVoltage1=0;
RealNumberVoltage2=0;
RealNumberVoltage3=0;
SetVoltagefloat=0.0;
SetVoltagefloat1=0.0;
SetVoltagefloat2=0.0;
SetVoltagefloat3=0.0;
Serial.readBytes(SetVoltage,4);

SetVoltages1 = SetVoltage[0];
SetVoltages2 = SetVoltage[2];
SetVoltages3 = SetVoltage[3];

RealNumberVoltage1=(int)(SetVoltages1)-48;
RealNumberVoltage2=(int)(SetVoltages2)-48;
RealNumberVoltage3=(int)(SetVoltages3)-48;
if(RealNumberVoltage1<=0){
  RealNumberVoltage1=0;
}
if(RealNumberVoltage2<=0){
  RealNumberVoltage2=0;
}
if(RealNumberVoltage3<=0){
  RealNumberVoltage3=0;
}
SetVoltagefloat1=RealNumberVoltage1;
SetVoltagefloat2=RealNumberVoltage2;
SetVoltagefloat2=(SetVoltagefloat2/10);
SetVoltagefloat3=RealNumberVoltage3;
SetVoltagefloat3=(SetVoltagefloat3/100);
SetVoltagefloat=SetVoltagefloat1+SetVoltagefloat2+SetVoltagefloat3;
Serial.print(SetVoltagefloat);
Serial.println("V @ Input");
Serial.print("Port ");
Serial.println(PinSet);

//Appr. 0.019V / 1 Step PWM
FinalPWM=SetVoltagefloat*50;
if(FinalPWM>=255){
  FinalPWM=255;
}
analogWrite(PinSet,FinalPWM);
delay(500);

AnalogRead=analogRead(A0);
AnalogRead=AnalogRead*0.0048;
Serial.print(AnalogRead);
Serial.println("V @ Analog 0");
delay(500);
}
