#include <stdio.h>
#include "QuadratureDecoder.h"
#include <RPi_Pico_TimerInterrupt.h>
#include "PID.h"
#include <Wire.h>
#include <MPU9250.h>
#include <math.h>
#include <HCSR04.h>
#include <remote.h>

uint8_t MPU9250_addr = 0x68;
MPU9250 IMU1(MPU9250_addr);
bool imu_succ = false;
double degree_speed = 0;
bool Enable = true;
bool Disable = false;
HCSR04 foward(2), backward(3);
NRFremote Controler1(83);
double rotate_speed = 0;
float distance = 10;// Unit: cm


void setup(){
    Serial.begin(115200);
    Wire.setSDA(0);
    Wire.setSCL(1);
    Wire.setClock(400000);
    Wire.begin();
    delay(2000);
    pinMode(LED_BUILTIN, OUTPUT);
    imu_succ = IMU1.init();
    imusucc.gravity(Enable);
    pinMode(25, OUTPUT);
    Controler1.init();
}
void loop(){
    if(imu_succ){
        double move_speed = Controler1.read_move();
        double rotate = Controler1.read_rotate();
        double G_z = imusucc.gravity_Z();
        double G_y = imusucc.gravity_Y();
        double G_degree = atan2(G_z, G_x);
        double move_degree = map(move_speed, -255, 255, -10, 10);
        rotate_speed = map(rotate, -255, 255, -30, 30);
        if(foward.read < distance){
            rotate_speed = min(rotate_speed, 0);
        }
        if(backward.read < distance){
            rotate_speed = max(rotate_speed, 0);
        }
        G_degree = (G_degree / PI) * (180+move_degree);
        degree_speed = G_degree - 90;
    }
    else{
        degree_speed = 0;
        digitalWrite(25, (millis()%1000>500));
    }
  
}

RPI_PICO_Timer ITimer0(0);
PID RtirePIDPID;
PID LtirePIDPID;
PID ACCPID;

QuadratureDecoder decoder;
int32_t lastCounter = 0;
int32_t IndexR = 0;
int32_t IndexL = 0;

double Rsetpoint = 0;
double ROutput = 0;

double Lsetpoint = 0;
double LOutput = 0;

void setup1(){
    //Serial.begin(115200);
    analogWriteFreq(20000);
    analogWriteRange(65535);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
  
    // set right motor encoder pin is 16,17
    const uint pinBaseR = 16;
    gpio_init(pinBaseR+0);
    gpio_init(pinBaseR+1);
    gpio_disable_pulls(pinBaseR+0);
    gpio_disable_pulls(pinBaseR+1);
    // set right motor encoder pin is 14,15
    const uint pinBaseL = 14;
    gpio_init(pinBaseL+0);
    gpio_init(pinBaseL+1);
    gpio_disable_pulls(pinBaseL+0);
    gpio_disable_pulls(pinBaseL+1);
    
    decoder.init(pio0);
    IndexR = decoder.addQuadratureEncoder(pinBaseR);
    IndexL = decoder.addQuadratureEncoder(pinBaseL);
    
    ITimer0.attachInterruptInterval(4 * 1000, timeloop);
    RtirePIDPID.init(85, 0, 0.002);
    LtirePIDPID.init(85, 0, 0.002);
    ACCPID.init(0.4, 0, 0.002);
}

void loop1(){
    /*Serial.print("tireR:");
    Serial.println(decoder.getCount(IndexR));
    Serial.print("tireL:");
    Serial.println(decoder.getCount(IndexL));
    delay(100);*/
}

bool timeloop(struct repeating_timer *t) {


  
    double ACCspeed = -15 * ACCPID.PIDv1(0, degree_speed);
    double Rspeed = ACCspeed;
    Rsetpoint = Rsetpoint + Rspeed + rotate_speed;
    ROutput = RtirePIDPID.PIDv1(Rsetpoint, decoder.getCount(IndexR));
    if (ROutput > 0){
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
    }
    else{
        digitalWrite(8, HIGH);
        digitalWrite(7, LOW);
    }
    analogWrite(6, abs(ROutput));


    double Lspeed = -1*ACCspeed;
    Lsetpoint = Lsetpoint + Lspeed + rotate_speed;
    LOutput = LtirePIDPID.PIDv1(Lsetpoint, decoder.getCount(IndexL));
    if (LOutput > 0){
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
    }
    else{
        digitalWrite(10, HIGH);
        digitalWrite(9, LOW);
    }
    analogWrite(11, abs(LOutput));
    return(true);
}
