/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*                  Equipped with M5StickC sample source code
*                          配套  M5StickC 示例源代码
* Visit the website for more information：https://docs.m5stack.com/en/core/m5stickc
* 获取更多资料请访问：https://docs.m5stack.com/zh_CN/core/m5stickc
*
* describe：Fan.  风扇
* date：2021/8/11
*******************************************************************************
  Please connect to Port, Adjust the speed of FAN Unit through PWM.
  请连接端口,通过PWM调节风扇单元的转速。
*/
#include <M5StickC.h>

#define motor_pin 32

int freq = 10000;
int ledChannel = 0;
int resolution = 10;
void setup() {
  M5.begin(); //Init M5StickC.  初始化M5StickC
  M5.Lcd.setRotation(3);  //Rotate the screen.  旋转屏幕
  M5.Lcd.setCursor(65, 10); //Set the cursor at (65,10).  将光标设置在(65,10)处
  M5.Lcd.println("Fan");
  ledcSetup(ledChannel, freq, resolution);  //Sets the frequency and number of counts corresponding to the channel.  设置通道对应的频率和计数位数
  ledcAttachPin(motor_pin, ledChannel); //Binds the specified channel to the specified I/O port for output.  将指定通道绑定到指定 IO 口上以实现输出
}

void loop() {
  ledcWrite(ledChannel, 512);  //Output PWM.  输出PWM
  delay(1000);
  ledcWrite(ledChannel, 0);
  delay(1000);
}
