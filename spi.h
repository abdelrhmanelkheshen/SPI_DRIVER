  /******************************************************************************
 *
 * [FILE NAME]: <spi.h>
 *
 * [AUTHOR]: Abdelrhman Hesham
 *
 * [DATE CREATED]: 17/11/2023
 *
 * [DESCRIPTION]: <Header file for spi>
 *
 *******************************************************************************/
#ifndef SPI
#define SPI

#include "types.h"

#define CLEAR_REG               (0x00U)

#define SSI0_AFSEL_NUM              (0x3CU)
#define SSI1_AFSEL_NUM              (0x0FU)        
#define SSI2_AFSEL_NUM              (0xF0U)
#define SSI3_AFSEL_NUM              (0x0FU)

#define SSI0_PCTL_NUM               (0x00222200U)
#define SSI1_PCTL_NUM               (0x00002222U)
#define SSI2_PCTL_NUM               (0x22220000U)
#define SSI3_PCTL_NUM               (0x00002222U)

#define SPO_ID                  (6U)
#define SCR_ID                  (8U)
#define SPH_ID                  (7U)
#define FRF_ID                  (4U)
#define SSE_ID                  (1U)  
#define TNF_ID                  (1U)
#define BSY_ID                  (4U)
#define RNE_ID                  (2U)


typedef struct
{
    condition ECU_state;
    uint8 prescaler;
    data_size size;
}SPI_Configuration;
     
void SPI_Init(SPI_Num Number, SPI_Configuration* Config_Ptr);
void SPI_Send(SPI_Num Number, uint8 Data);
uint8 SPI_Receive(SPI_Num Number);
void SPI_ChangeState(SPI_Num Number, SPI_Configuration* Config_Ptr);

#endif