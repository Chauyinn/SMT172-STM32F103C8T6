/*
 * @Author: Crpeach
 * @Date: 2022-07-22 10:04:53
 * @LastEditors: Crpeach
 * @LastEditTime: 2022-08-01 14:24:39
 * @FilePath: \SMT172 - copy\icode\SMT172\SMT172.c
 * @Description: practice
 */

#include "SMT172.h"


uint32_t HighCycles;
uint32_t EndCycle;
uint32_t StartCycle;

float temper;
float Total_Duty;
float DutyCycle = 0;

uint32_t Capture_Buf[129] = {0}; //储存采集到的数值

float Get_Temper()
{
    Total_Duty = 0; //重置总占空比
    Capture_Flag = 0;
    HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_3); //启动输入捕获
    while (Capture_Flag != 1);
    for (uint8_t i = 0; i < 127; i += 2) //计算占空比
    {
        StartCycle = Capture_Buf[i];
        HighCycles = Capture_Buf[i + 2] - Capture_Buf[i + 1];
        EndCycle = Capture_Buf[i + 2];
        DutyCycle = (float)HighCycles / (float)(EndCycle - StartCycle);
        Total_Duty += DutyCycle;
    }
    temper = -1.43 * ((Total_Duty / 64) * (Total_Duty / 64)) + 214.56 * (Total_Duty / 64) - 68.60; //二阶计算温度
    return temper;
}
