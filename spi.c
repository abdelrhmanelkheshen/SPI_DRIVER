  /******************************************************************************
 *
 * [FILE NAME]: <spi.c>
 *
 * [AUTHOR]: Abdelrhman Hesham
 *
 * [DATE CREATED]: 17/11/2023
 *
 * [DESCRIPTION]: <Source file for spi>
 *
 *******************************************************************************/
#include "spi.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"

void SPI_Init(SPI_Num Number, SPI_Configuration* Config_Ptr)
{
    switch (Number)
    {
    case SSI0_ID:
        SET_BIT(SYSCTL_RCGCGPIO_R,PORTA);
        while((GET_BIT(SYSCTL_RCGCGPIO_R,PORTA))==0){};
        
        SET_BIT(SYSCTL_RCGCSSI_R,SSI0_ID);
        while ( BIT_IS_CLEAR(SYSCTL_RCGCSSI_R,SSI0_ID) );
        
        GPIO_PORTA_CR_R |= (0x0F << 2);
        GPIO_PORTA_DEN_R |= (0x0F << 2);
        GPIO_PORTA_AFSEL_R |= SSI0_AFSEL_NUM;
        
        GPIO_PORTA_PCTL_R |=  SSI0_PCTL_NUM;
        
        SSI0_CR1_R = CLEAR_REG;
        SSI0_CR1_R = Config_Ptr->ECU_state;
        SSI0_CC_R = CLEAR_REG; //clksrc
        SSI0_CPSR_R = Config_Ptr->prescaler; // pescaler CDVSRCL
        SSI0_CR0_R &=  ~( (0xFFFF << SCR_ID) | (1<<SPH_ID) | (0x3 << FRF_ID) ) ; //SCR , SPH , FRF
        SSI0_CR0_R |= (1<< SPO_ID); //SPO
        SSI0_CR0_R =  (SSI0_CR0_R & ~(0x0F)) | (Config_Ptr->size);
        SET_BIT(SSI0_CR1_R, SSE_ID);
      
      break;
       case SSI1_ID:
        SET_BIT(SYSCTL_RCGCGPIO_R,PORTF);
        while((GET_BIT(SYSCTL_RCGCGPIO_R,PORTF))==0){};
        
        SET_BIT(SYSCTL_RCGCSSI_R,SSI1_ID);
        while ( BIT_IS_CLEAR(SYSCTL_RCGCSSI_R,SSI1_ID) );
        
        GPIO_PORTF_CR_R |= 0x0F;
        GPIO_PORTF_DEN_R |= 0x0F;
        GPIO_PORTF_AFSEL_R |= SSI1_AFSEL_NUM;
        GPIO_PORTF_PCTL_R |=  SSI1_PCTL_NUM;
        
        SSI1_CR1_R = CLEAR_REG;
        SSI1_CR1_R = Config_Ptr->ECU_state;
        SSI1_CC_R = CLEAR_REG; //clksrc
        SSI1_CPSR_R = Config_Ptr->prescaler; // pescaler CDVSRCL
        SSI1_CR0_R &=  ~( (0xFFFF << SCR_ID) | (1<<SPH_ID) | (0x3 << FRF_ID) ) ; //SCR , SPH , FRF
        SSI1_CR0_R |= (1<< SPO_ID); //SPO
        SSI1_CR0_R =  (SSI0_CR0_R & ~( 0x0F)) | (Config_Ptr->size);
        SET_BIT(SSI1_CR1_R, SSE_ID);
      break;
       case SSI2_ID:
         SET_BIT(SYSCTL_RCGCGPIO_R,PORTB);
         while((GET_BIT(SYSCTL_RCGCGPIO_R,PORTB))==0){};
         
         SET_BIT(SYSCTL_RCGCSSI_R,SSI2_ID);
         while ( BIT_IS_CLEAR(SYSCTL_RCGCSSI_R,SSI0_ID) );
         
         GPIO_PORTB_CR_R |= (0x0F << 4);
         GPIO_PORTB_DEN_R |= (0x0F << 4);
         GPIO_PORTB_AFSEL_R |= SSI2_AFSEL_NUM;
         GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R & LEAST_4_BYTES_HIGH) | SSI2_PCTL_NUM;
         
         SSI2_CR1_R = CLEAR_REG;
         SSI2_CR1_R = Config_Ptr->ECU_state;
         SSI2_CC_R = CLEAR_REG; //clksrc
         SSI2_CPSR_R = Config_Ptr->prescaler; // pescaler CDVSRCL
         SSI2_CR0_R &=  ~( (0xFFFF << SCR_ID) | (1<<SPH_ID) | (0x3 << FRF_ID) ) ; //SCR , SPH , FRF
         SSI2_CR0_R |= (1<< SPO_ID); //SPO
         SSI2_CR0_R =  (SSI0_CR0_R & ~( 0x0F)) | (Config_Ptr->size);
         SET_BIT(SSI2_CR1_R, SSE_ID);
      break;
       case SSI3_ID:
        SET_BIT(SYSCTL_RCGCGPIO_R,PORTD);
        while((GET_BIT(SYSCTL_RCGCGPIO_R,PORTD))==0){};
        
        SET_BIT(SYSCTL_RCGCSSI_R,SSI3_ID);
        while ( BIT_IS_CLEAR(SYSCTL_RCGCSSI_R,SSI0_ID) );
        
        GPIO_PORTD_CR_R |= 0x0F;
        GPIO_PORTD_DEN_R |= 0x0F;
        GPIO_PORTD_AFSEL_R |= SSI3_AFSEL_NUM;
        GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & MOST_4_BYTES_HIGH) | SSI3_PCTL_NUM;
        
        SSI3_CR1_R = CLEAR_REG;
        SSI3_CR1_R = Config_Ptr->ECU_state;
        SSI3_CC_R = CLEAR_REG; //clksrc
        SSI3_CPSR_R = Config_Ptr->prescaler; // pescaler CDVSRCL
        SSI3_CR0_R &=  ~( (0xFFFF << SCR_ID) | (1<<SPH_ID) | (0x3 << FRF_ID) ) ; //SCR , SPH , FRF
        SSI3_CR0_R |= (1<< SPO_ID); //SPO
        SSI3_CR0_R =  (SSI3_CR0_R & ~( 0x0F)) | (Config_Ptr->size);
        SET_BIT(SSI3_CR1_R, SSE_ID);
      break;
    }

  
  
}

void SPI_Send(SPI_Num Number, uint8 Data)
{ 
   switch (Number)
    {
    case SSI0_ID:
        while ( GET_BIT (SSI0_SR_R , TNF_ID) == 0);
        SSI0_DR_R = (uint8)(Data);
        while ( GET_BIT (SSI0_SR_R , BSY_ID) == 1);
        break;
    case SSI1_ID:
        while ( GET_BIT (SSI1_SR_R , TNF_ID) == 0);
        SSI1_DR_R = (uint8)(Data);
        while ( GET_BIT (SSI1_SR_R , BSY_ID) == 1);
        break;
    case SSI2_ID:
        while ( GET_BIT (SSI2_SR_R , TNF_ID) == 0);
        SSI2_DR_R = (uint8)(Data);
        while ( GET_BIT (SSI2_SR_R , BSY_ID) == 1);
        break;
    case SSI3_ID:
        while ( GET_BIT (SSI3_SR_R , TNF_ID) == 0);
        SSI3_DR_R = (uint8)(Data);
        while ( GET_BIT (SSI3_SR_R , BSY_ID) == 1);
        break;
    } 
}

uint8 SPI_Receive(SPI_Num Number)
{
  uint8 data;
  switch (Number)
    {
  case SSI0_ID:
      while ( GET_BIT (SSI0_SR_R , RNE_ID) == 0); //RNE
      data = SSI0_DR_R;
      break;
  case SSI1_ID:
      while ( GET_BIT (SSI1_SR_R , RNE_ID) == 0); //RNE
      data = SSI1_DR_R;
      break;
  case SSI2_ID:
      while ( GET_BIT (SSI2_SR_R , RNE_ID) == 0); //RNE
      data = SSI2_DR_R;
      break;
  case SSI3_ID:
      while ( GET_BIT (SSI3_SR_R , RNE_ID) == 0); //RNE
      data = SSI3_DR_R;
      break;
    }
  return data;
}

void SPI_ChangeState(SPI_Num Number, SPI_Configuration* Config_Ptr)
{
   
  switch (Number)
    {
  case SSI0_ID:
      SSI0_CR1_R = CLEAR_REG;
      SSI0_CR1_R = Config_Ptr->ECU_state;;
      SSI0_CC_R = CLEAR_REG; //clksrc
      SSI0_CPSR_R = Config_Ptr->prescaler; // pescaler CDVSRCL
      SSI0_CR0_R &=  ~( (0xFFFF << SCR_ID) | (1<<SPH_ID) | (0x3 << FRF_ID) ) ; //SCR , SPH , FRF
      SSI0_CR0_R |= (1<< SPO_ID); //SPO
      SSI0_CR0_R =  (SSI0_CR0_R & ~(0x0F)) | (Config_Ptr->size);
      SET_BIT(SSI0_CR1_R, SSE_ID);
      break;
  case SSI1_ID:
      SSI1_CR1_R = CLEAR_REG;
      SSI1_CR1_R = Config_Ptr->ECU_state;;
      SSI1_CC_R = CLEAR_REG; //clksrc
      SSI1_CPSR_R = Config_Ptr->prescaler; // pescaler CDVSRCL
      SSI1_CR0_R &=  ~( (0xFFFF << SCR_ID) | (1<<SPH_ID) | (0x3 << FRF_ID) ) ; //SCR , SPH , FRF
      SSI1_CR0_R |= (1<< SPO_ID); //SPO
      SSI1_CR0_R =  (SSI0_CR0_R & ~(0x0F)) | (Config_Ptr->size);
      SET_BIT(SSI1_CR1_R, SSE_ID);
      break;
  case SSI2_ID:
      SSI2_CR1_R = CLEAR_REG;
      SSI2_CR1_R = Config_Ptr->ECU_state;;
      SSI2_CC_R = CLEAR_REG; //clksrc
      SSI2_CPSR_R = Config_Ptr->prescaler; // pescaler CDVSRCL
      SSI2_CR0_R &=  ~( (0xFFFF << SCR_ID) | (1<<SPH_ID) | (0x3 << FRF_ID) ) ; //SCR , SPH , FRF
      SSI2_CR0_R |= (1<< SPO_ID); //SPO
      SSI2_CR0_R =  (SSI0_CR0_R & ~(0x0F)) | (Config_Ptr->size);
      SET_BIT(SSI2_CR1_R, SSE_ID);
      break;
  case SSI3_ID:
      SSI3_CR1_R = CLEAR_REG;
      SSI3_CR1_R = Config_Ptr->ECU_state;;
      SSI3_CC_R = CLEAR_REG; //clksrc
      SSI3_CPSR_R = Config_Ptr->prescaler; // pescaler CDVSRCL
      SSI3_CR0_R &=  ~( (0xFFFF << SCR_ID) | (1<<SPH_ID) | (0x3 << FRF_ID) ) ; //SCR , SPH , FRF
      SSI3_CR0_R |= (1<< SPO_ID); //SPO
      SSI3_CR0_R =  (SSI0_CR0_R & ~(0x0F)) | (Config_Ptr->size);
      SET_BIT(SSI3_CR1_R, SSE_ID);
      break;
    }
}
