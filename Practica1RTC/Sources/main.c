/* 
 * Ejemplo de I2C. Usando el Driver Estándar
   Manejo de la Memoria 24LC16. Páginas de 16 datos.
   La aplicación es muy simple, un conjunto de valores se escriben en la memoria y luego se
   leen. Se comparan los datos escritos con los leidos. Finalmente se envían
   mensajes al LCD de acuerdo a la ejecución.
   Los datos se escriben al final de la página 16, sabiendo que la primera página es la cero
   es decir, en la dirección 0x10F (memoria 24LC16 con 16 bytes por páginas). El Driver
   automáticamente hace el salto de página para no perder datos.
 
   Este ejemplo también configura el RTC y lo lee cada 0.5seg.

   Este programa no hace uso de metodología de eventos, es
   simplemente una ilustración de como emplear el protocolo I2C.
   
   ALAMBRADA (LCD)   
   
              PTC6 PTC4                          PTA0 PTA1 PTA2 PTA3 VCC
    _|____|____|____|____|____|____|____|____|____|____|____|____|____|__
   |           RS   E                             D4   D5   D6   D7   BL |
   | 1                                                                16 |
   |         LCD                                                         |
   |_____________________________________________________________________|
   
   ALAMBRADA (I2C)
   
      PTA4    PTA5
    ___|_______|___
   |  SDA     SCL  |
   |               |
   |_______________|
   
   */
   
#include "derivative.h" 
#include "driver_i2c.h"
#include "general.h"
#include "lcd.h"
#include "timer.h"
#include "events.h"
#include "realtimec.h"


// Función principal
void main(void) 
{
  // Inicialización
  SYSTEM_INIT();
  MCG_Init();
  LCD_Init();
  TPM_Init();
  SCI_Init();
  CLI;


  RealTimeClock_Init();

  for(;;){
    	SEI;   	
    	if(INT_EVENTS==0)WAIT;
    	CLI;
    	
    	Process_Events();
  }

}
