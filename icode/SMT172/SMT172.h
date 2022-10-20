/*
 * @Author: Crpeach
 * @Date: 2022-07-22 10:05:00
 * @LastEditors: Crpeach
 * @LastEditTime: 2022-07-28 10:17:25
 * @FilePath: \SMT172 - copy\icode\SMT172\SMT172.h
 * @Description: practice
 */

#ifndef SMT172_H_
#define SMT172_H_

#include "stm32f1xx_hal.h"
#include "tim.h"
#include <stdio.h>

extern uint8_t Capture_Flag;
extern uint8_t Capture_Flow;

float Get_Temper(); //计算返回温度
#endif
