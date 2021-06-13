#include "mbed.h"
#include "C12832.h"
C12832 lcd(SPI_MOSI, SPI_SCK, SPI_MISO, p8, p11); //LCD Display as Timer
PwmOut speaker(p21); // Speaker to act as an alarm for pedestrians
void play_tone(float frequency, float volume, int interval, int rest) {
speaker.period(1.0 / frequency);
speaker = volume;
wait(interval);
speaker = 0.0;
wait(rest);
}
//T1
DigitalOut t1red(p12);
DigitalOut t1yellow(p13);
DigitalOut t1green(p14);
//T2
DigitalOut t2red(p15);
DigitalOut t2yellow(p16);
DigitalOut t2green(p17);
//T3
DigitalOut t3red(p18);
DigitalOut t3yellow(p19);
DigitalOut t3green(p20);
//T4
DigitalOut t4red(p22);
DigitalOut t4yellow(p23);
DigitalOut t4green(p24);
void t1light(char a){
if (a == 'R'){
t1red = 1;
t1yellow = 0;
t1green = 0;
}else if(a == 'Y'){
t1red = 0;
t1yellow = 1;
t1green = 0;
}else if(a == 'G'){
t1red = 0;
t1yellow = 0;
t1green = 1;
}else{}
}
void t2light(char a){
if (a == 'R'){
t2red = 1;
t2yellow = 0;
t2green = 0;
}else if(a == 'Y'){
t2red = 0;
t2yellow = 1;
t2green = 0;
}else if(a == 'G'){
t2red = 0;
t2yellow = 0;
t2green = 1;
}else{}
}
void t3light(char a){
if (a == 'R'){
t3red = 1;
t3yellow = 0;
t3green = 0;
}else if(a == 'Y'){
t3red = 0;
t3yellow = 1;
t3green = 0;
}else if(a == 'G'){
t3red = 0;
t3yellow = 0;
t3green = 1;
}else{}
}
void t4light(char a){
if (a == 'R'){
t4red = 1;
t4yellow = 0;
t4green = 0;
}else if(a == 'Y'){
t4red = 0;
t4yellow = 1;
t4green = 0;
}else if(a == 'G'){
t4red = 0;
t4yellow = 0;
t4green = 1;
}else{}
}
void traffic_default (char t1, char t2, char t3, char t4, int time){
t1light(t1);
t2light(t2);
t3light(t3);
t4light(t4);
wait(time);
}
void normal_traffic(){
traffic_default('G','R','G','R',47);
traffic_default('Y','R','Y','R',3);
traffic_default('R','G','R','G',47);
traffic_default('R','Y','R','Y',3);
}
int main() {
while(1){
normal_traffic();
lcd.cls();
for(int i=47;i>=0;i--)
{
lcd.locate(3, 13);
lcd.printf("%d",i);
wait(1);
if((i<=5)&&(i>=0))
{play_tone(200.0, 0.5, 1, 0);
play_tone(150.0, 0.5, 1, 0);
play_tone(125.0, 0.5, 1, 2);}
else{};
}
wait(3);
}
}
