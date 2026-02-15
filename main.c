#include <msp430.h>
#include "i2c.h"
#include "vl53l0x.h"
#include "gpio.h"
#include <stdio.h>
#include <stdint.h>

#define VL53L0X
#define RS BIT0     
#define EN BIT1     
#define D4 BIT2     
#define D5 BIT3     
#define D6 BIT4     
#define D7 BIT5     

static void msp430_init()
{
    WDTCTL = WDTPW | WDTHOLD; 

    
    DCOCTL = CALDCO_1MHZ;
    BCSCTL1 = CALBC1_1MHZ;
}

void lcdkomutgonder(unsigned char command) {
    P2OUT &= ~RS;                  
    P2OUT &= 0x03;                  
    P2OUT |= (command & 0xF0) >> 2;   
    P2OUT |= EN;                    
    __delay_cycles(5);              
    P2OUT &= ~EN;                   

    P2OUT &= 0x03;                 
    P2OUT |= (command & 0x0F) << 2; 
    P2OUT |= EN;                    
    __delay_cycles(5);             
    P2OUT &= ~EN;                 

    __delay_cycles(100);            
}

void lcdverigonder(unsigned char data) {
    P2OUT |= RS;                   
    P2OUT &= 0x03;                  
    P2OUT |= (data & 0xF0) >> 2;    
    P2OUT |= EN;                    
    __delay_cycles(5);             
    P2OUT &= ~EN;                   

    P2OUT &= 0x03;                  
    P2OUT |= (data & 0x0F) << 2;    
    P2OUT |= EN;                    
    __delay_cycles(5);              
    P2OUT &= ~EN;                  

    __delay_cycles(100);           
}

void initLCD() {
    P2DIR |= RS | EN | D4 | D5 | D6 | D7;  
    
    __delay_cycles(15000);  

    lcdkomutgonder(0x33);     
    lcdkomutgonder(0x32);      
    lcdkomutgonder(0x28);     
    lcdkomutgonder(0x0C);    
    lcdkomutgonder(0x06);       
    lcdkomutgonder(0x01);       
    __delay_cycles(2000);    
}

void yaziyiyaz(const char *text) {
    while (*text) {
        lcdverigonder(*text++);
    }
}

void lcdPrintNumber1(unsigned int number)
{
    char sayi[10]; 
    sprintf(sayi, "%u", number); 

    yaziyiyaz(sayi); 
}

void karsilama(){
    yaziyiyaz("Hosgeldiniz");
    __delay_cycles(3000000); 
    lcdkomutgonder(0x01);       
}

void kullanici(){
  yaziyiyaz("Ahmet Enes Karci");
    __delay_cycles(3000000); 
    lcdkomutgonder(0x01);    
}

int main(void) {
    msp430_init();
    i2c_init();
    initLCD();                 
    vl53l0x_init();

    bool sonuc = vl53l0x_init();
    uint16_t mesafeDegerleri[1] = { 0 };
    while (sonuc) {
        sonuc = vl53l0x_read_range_single(VL53L0X_IDX_FIRST, &mesafeDegerleri[0]);
    }
    karsilama();
    __delay_cycles(2000000); 
    kullanici();  
    
  
    while (1) {
        while (sonuc) {
            sonuc = vl53l0x_read_range_single(VL53L0X_IDX_FIRST, &mesafeDegerleri[0]);
        }
        vl53l0x_read_range_single(VL53L0X_IDX_FIRST, &mesafeDegerleri[0]);
        yaziyiyaz("Uzunluk: "); 
        lcdPrintNumber1(mesafeDegerleri[0]);
        lcdkomutgonder(0xC0); 
        yaziyiyaz("Seviye: ");
        
        if (mesafeDegerleri[0] < 80)
        { yaziyiyaz("Yuksek"); } 
        
        else if (mesafeDegerleri[0] >= 80 && mesafeDegerleri[0] <= 120)
        {   yaziyiyaz("Orta"); } 
        
        else if (mesafeDegerleri[0] >= 120 && mesafeDegerleri[0] <= 160)
        { yaziyiyaz("Dusuk"); }
        
        else
        { yaziyiyaz("Bos"); }
        
        lcdkomutgonder(0x80); 
        __delay_cycles(500000); 
        lcdkomutgonder(0x01);       
        if (mesafeDegerleri[0] == 8190) {
            int tekrarSayisi = 0;
            tekrarSayisi++;
            if (tekrarSayisi == 3) {
                i2c_init();
                vl53l0x_init();
                tekrarSayisi = 0;
            }
        }
    }
    return 0;
}
