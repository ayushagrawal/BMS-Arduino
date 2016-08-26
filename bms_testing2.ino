/* There is a list of functions as given in the LTC6804.cpp and for using those functions these libraries are necessary */

#include <stdint.h>
#include <Arduino.h>
#include "Linduino.h"
#include "LT_SPI.h"
#include "LTC68042.h"
#include <SPI.h>


/******************************************************************************************/

/* All the basic functions are included as above */

/******************************************************************************************/

/******* GLOBAL VARIABLES ***********/

const int CELL_NUM = 12;                          //Maximum cell number on each IC
const int TOTAL_IC = 1;                          //Number of IC's
uint8_t tx_cfg[TOTAL_IC][6];                     //For configuring configuration registers
uint8_t error;
int input;
uint16_t cell_codes[TOTAL_IC][12];

/******************************************************************************************/
/* Some other required functions */

void init_cfg(){
  for(int i = 0; i<TOTAL_IC;i++){
    tx_cfg[i][0] = 0x04;
    tx_cfg[i][1] = 0x00;
    tx_cfg[i][2] = 0x00;
    tx_cfg[i][3] = 0x00;
    tx_cfg[i][4] = 0x00;
    tx_cfg[i][5] = 0x10;
  }
}

void print_cells()
{
  for (int current_ic = 0 ; current_ic < TOTAL_IC; current_ic++)
  {
    Serial.print(" IC ");
    Serial.print(current_ic+1,DEC);
    for(int i=0; i<CELL_NUM; i++)
    {
      Serial.print(" C");
      Serial.print(i+1,DEC);
      Serial.print(":");
      Serial.print(cell_codes[current_ic][i]*.0001, 4);
      Serial.print(",");
    }
     Serial.println();
  }
}

/*********************************************************************************************/

void setup() 
{
  Serial.begin(115200);
  LTC6804_initialize();  //Initialize LTC6804 hardware
  init_cfg();            //Initialize the 6804 configuration array to be written
}

void loop() 
{
  Serial.println("Starting voltage loop. Transmit 'm' to quit.");
  wakeup_sleep();
  LTC6804_wrcfg(TOTAL_IC,tx_cfg);
  while (input != 'm')
  {
    if (Serial.available() > 0)
    {
      input = Serial.available();
    }
    wakeup_idle();
    LTC6804_adcv();                 //Starts the conversion of input voltages
    delay(10);
    wakeup_idle();
    error = LTC6804_rdcv(1, TOTAL_IC,cell_codes);     /*It reads the data, parses it and then store it,
                                                                        and returns if there is any error detected */
    
    /* THE ZERO IN THE ABOVE COMMAND REFERS TO THE STACK OF CELLS TO BE READ. 
                 IN THE ABOVE CASE IT CORRESPONDS TO READING ALL THE CELL VOLTAGES */ 
    
    if (error == 255)
    {
      Serial.println("A PEC error was detected in the received data");
      while (error == 255)
      {
        error = LTC6804_rdcv(1, TOTAL_IC,cell_codes);
        Serial.println("Error Detected");
      }
    }
    else
    {
      Serial.print(error);
      print_cells();
      Serial.println();
    }
    delay(50);
  }
}
