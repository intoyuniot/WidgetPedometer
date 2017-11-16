/*
************************************************************************
* 作者:  IntoRobot Team    
* 版本:  V1.0.0
* 日期:  03-30-15
************************************************************************
功能描述：
可记录跑步数

所需器件:
1、加速度传感器

*/

/*该头文件引用由IntoRobot自动添加.*/
#include <WidgetPedometer.h>

WidgetPedometer pedometer;

uint32_t count;

void CountResetCb(void)
{
    if(pedometer.getReset())
    {
        pedometer.displayPedometerCount(0);
    }
}

void setup() 
{
// put your setup code here, to run once.
    pedometer.begin(CountResetCb);
}

void loop() 
{
// put your main code here, to run repeatedly.
    count++;
    pedometer.displayPedometerCount(count);
    delay(2000);
}
