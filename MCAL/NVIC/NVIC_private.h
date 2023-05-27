#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

typedef struct 
{
    volatile u32 ISER[8];
    volatile u32 RESERVED0[24];
    volatile u32 ICER[8];
    volatile u32 RESERVED1[24];
    volatile u32 ISPR[8];
    volatile u32 RESERVED2[24];
    volatile u32 ICPR[8];
    volatile u32 RESERVED2[24];
    volatile u32 IABR[8];
    volatile u32 RESERVED3[56];
    volatile u8 IPR[240];
    volatile u32 RESERVED3[580];
    volatile u32 STIR;
}NVIC_t;

#define     MNVIC           ((volatile NVIC_t*)0XE000EF00)

#define     SCB_AIRCR       *((volatile u32*)0xE000ED0C)
#define     AIRCR_PRIVKEY   0X05FA

#define GRP_4_SUB_0_BITS                    0b000
#define GRP_3_SUB_1_BITS                    0b100
#define GRP_2_SUB_2_BITS                    0b101
#define GRP_1_SUB_3_BITS                    0b110
#define GRP_0_SUB_4_BITS                    0b111

#endif