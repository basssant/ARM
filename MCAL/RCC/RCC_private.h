#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#define MRCC_BASE_ADDRESS                   *(volatile u32*)0x4002 3800

#define MRCC_ADDRESS_POINTER                *((volatile u32*)(MRCC_BASE_ADDRESS+0x00))

typedef struct 
{
    volatile u32 CR;
    volatile u32 PLLCFGR;
    volatile u32 CFGR;
    volatile u32 CIR;
    volatile u32 AHB1RSTR;
    volatile u32 AHB2RSTR;
    volatile u32 Reserved1[2];
    volatile u32 APB1RSTR;
    volatile u32 APB2RSTR;
    volatile u32 Reserved2[2];
    volatile u32 AHB1ENR;
    volatile u32 AHB2ENR;
    volatile u32 Reserved3[2];
    volatile u32 APB1ENR;
    volatile u32 APB2ENR;
    volatile u32 Reserved4[2];
    volatile u32 AHB1LPENR;
    volatile u32 AHB2LPENR;
    volatile u32 Reserved5[2];
    volatile u32 APB1LPENR;
    volatile u32 APB2LPENR;
    volatile u32 Reserved6[2];
    volatile u32 BDCR;
    volatile u32 CSR;
    volatile u32 Reserved7[2];
    volatile u32 SSCGR;
    volatile u32 PLLI2SCFGR;
    volatile u32 Resevred;
    volatile u32 DCKCFGR;
}RCC_t;

#define RCC                             ((volatile RCC_t*)0x40023800)

#define AHB_PRESCALER_MASK              0xFFFFFF0F
#define AHB_NO_PRESCALER                0x00000000
#define AHB_PRESCALER_2                 0x00000080
#define AHB_PRESCALER_4                 0x00000090
#define AHB_PRESCALER_8                 0x000000A0
#define AHB_PRESCALER_16                0x000000B0
#define AHB_PRESCALER_64                0x000000C0
#define AHB_PRESCALER_128               0x000000D0
#define AHB_PRESCALER_256               0x000000E0
#define AHB_PRESCALER_512               0x000000F0

#define APB1_PRESCALER_MASK             0XFFFFE3FF
#define AHB_clock_not_divided           0x0000AB00
#define AHB_clock_divided_by_2          0x00001000
#define AHB_clock_divided_by_4          0x00001400
#define AHB_clock_divided_by_8          0x00001800
#define AHB_clock_divided_by_16         0x00001C00

#define APB2_PRESCALER_MASK             0XFFFF1FFF
#define APB1_NO_PRESCALER               (AHB_clock_not_divided   << 3)
#define APB1_PRESCALER_2                (AHB_clock_divided_by_2  << 3)
#define APB1_PRESCALER_4                (AHB_clock_divided_by_4  << 3)
#define APB1_PRESCALER_8                (AHB_clock_divided_by_8  << 3)
#define APB1_PRESCALER_16               (AHB_clock_divided_by_16 << 3)

#define HSI                             0
#define HSE                             1
#define PLL                             2
#endif