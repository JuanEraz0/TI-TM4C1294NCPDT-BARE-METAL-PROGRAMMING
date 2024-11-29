#include "timer5.h"
#include <stdio.h>
#include <stdint.h>


void timer5_INIT(void){
    SYSCTL_RCGCTIMER_R |= 0x20; //habilitar reloj de TIMER5

    //Configuracion de TIMER5
    TIMER5_CTL_R = 0x0; //Apagar TIMER5 Para su configuracion
    TIMER5_CFG_R = 0x4; //configuracion de timer a 16 bits
    TIMER5_TBMR_R |= 0x11;  //Configurar el timer en modo ONE-SHOT cuenta hacia arriba
    
    TIMER5_TBILR_R = 0x1E00; //Valor para 480 seg
    TIMER5_TBPR_R = 0xFF; //preescalador en 256
    TIMER5_ICR_R = 0x100;   //Limpia interrupciones
    TIMER5_IMR_R = 0x100; //Habilita interrupciones para T5 en subtimer B
    TIMER5_CTL_R= 0x100;    //Enciende TIMER5
    NVIC_EN2_R = 0x04; // Habilita INT 66 en NVIC

}
