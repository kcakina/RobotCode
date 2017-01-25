/*
 * File:   BasicLED.c
 * Author: almoser
 *
 * Created on September 7, 2016, 11:08 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include <plib.h>
/* all ports have names:                        */
/* e.g. IOPORT_A IOPORT_B, etc.                 */
/* all port bits have names:                    */
/* e.g. BIT_0, BIT_1,... BIT_14, BIT_15, etc.   */

/*
 *
 */
/*
 * This program is to control the motors on the MRK-LINE Robot, using feedback
 * from the optical sensors in the line-following accessory.
 * Here are the pertinent port connections:
 *      Left wheel (assuming sensors are on front bumper)
 *          DIR - RD6
 *          EN -  RD2   active high
 *          SA -  RD10  SA and SB are quadrature encoded feedback
 *          SB -  RC2
 *      Right wheel
 *          DIR - RD7
 *          EN -  RD1
 *          SA -  RD9
 *          SB -  RC1
 *      Optical Sensors
 *          S1 - RB0    S1 is rightmost sensor
 *          S2 - RB1    S2 is middle right sensor
 *          S3 - RB2    S3 is middle left sensor
 *          S4 - RB3    S4 is leftmost sensor
 */
int main(int argc, char** argv) {
    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
    INTEnableInterrupts();

    // Useful functions: (see PeripheralLibraries pdf file for more)
    //  PORTSetPinsDigitalOut(IOPORT_B, BIT_10 | BIT_11 | BIT_12 | BIT_13);
    //  PORTSetPinsDigitalIn(IOPORT_B, BIT_10 | BIT_11 | BIT_12 | BIT_13);
    //  PORTClearBits(IOPORT_B, BIT_10 | BIT_11 | BIT_12 | BIT_13);     // clear bits
    //  PORTSetBits(IOPORT_B, BIT_10 | BIT_11 | BIT_12 | BIT_13);       // set bits
    //  PORTToggleBits(IOPORT_B, BIT_10 | BIT_11 | BIT_12 | BIT_13);    // toggle state of the bits
    //  PORTReadBits(IOPORT_A, BIT_6);   // read the state of button on RA6

   // Configure ports for onboard LEDs as outputs
   // Configure built in buttons as inputs
   PORTSetPinsDigitalOut(IOPORT_B, BIT_10 | BIT_11 | BIT_12 | BIT_13); //this sets all the LED's as outputs
   //PORTSetPinsDigitalIn(IOPORT_A, BIT_6 | BIT_7); //This sets the push buttons as inputs
   //PORTSetBits(IOPORT_B, BIT_10 | BIT_11); // Set 2 LED's to on
   PORTSetPinsDigitalIn(IOPORT_B, BIT_0 | BIT_1 | BIT_2 | BIT_3);
   PORTClearBits(IOPORT_B, BIT_12 | BIT_13); //Clear 2 LED's and make them off
   PORTSetPinsDigitalOut(IOPORT_D, BIT_1 | BIT_2 | BIT_6 | BIT_7);
   PORTSetBits(IOPORT_D, BIT_6);
   PORTClearBits(IOPORT_D, BIT_7);

   // Keoni Code
   PORTClearBits(IOPORT_D, BIT_1);
   PORTClearBits(IOPORT_D, BIT_2);

    while (1) // continuous loop
    {

        // PORT_B SENSOR if white then high
        // Port B BIT_1 = right sensor
        // Port B BIT_2 = left
        // port d Bit_1 = right motor
        // Port D bit_2 = left
        

        if(!PORTReadBits(IOPORT_B,BIT_1)){
            PORTSetBits(IOPORT_D, BIT_1);
            PORTClearBits(IOPORT_D, BIT_2);
        }else{
        PORTSetBits(IOPORT_D, BIT_2);
        PORTClearBits(IOPORT_D, BIT_1);
        }
    }
    return (EXIT_SUCCESS);
}



