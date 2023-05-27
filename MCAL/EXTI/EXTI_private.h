#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

typedef struct
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;

}EXTI_t;

#define EXTI                            ((volatile EXTI_t *)0X40013C00)
#define SYSCFG_CR1                      *((volatile u32 *)0X40013808)

#endif