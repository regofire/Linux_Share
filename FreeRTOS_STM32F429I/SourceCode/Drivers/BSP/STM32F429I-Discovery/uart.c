#include "uart.h"
#include "xprintf.h"
// -----------------------------------------------------------------------------
UART_HandleTypeDef  debug_uart1_handle;
// -----------------------------------------------------------------------------	
HAL_StatusTypeDef BSP_UART_Init(void)
{    
    HAL_StatusTypeDef result;
    
    debug_uart1_handle.Instance          = USARTx;
    
    debug_uart1_handle.Init.BaudRate     = 115200;
    debug_uart1_handle.Init.WordLength   = UART_WORDLENGTH_8B;
    debug_uart1_handle.Init.StopBits     = UART_STOPBITS_1;
    debug_uart1_handle.Init.Parity       = UART_PARITY_NONE;
    debug_uart1_handle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
    debug_uart1_handle.Init.Mode         = UART_MODE_TX_RX;
    debug_uart1_handle.Init.OverSampling = UART_OVERSAMPLING_16;   
        
    result = HAL_UART_Init(&debug_uart1_handle);    
    
    xdev_out(UART_Send_Byte);
    
    return result;
}
// -----------------------------------------------------------------------------
void UART_Send_Byte(unsigned char byte)
{
    HAL_UART_Transmit(&debug_uart1_handle, 
                      (unsigned char *)&byte,
                       1,
                       1000);
}
// -----------------------------------------------------------------------------
