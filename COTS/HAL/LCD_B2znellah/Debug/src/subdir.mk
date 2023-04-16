################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GPIO.c \
../src/LCD.c \
../src/LCD_CFG.c \
../src/RCC_config.c \
../src/RCC_prog.c \
../src/main.c 

OBJS += \
./src/GPIO.o \
./src/LCD.o \
./src/LCD_CFG.o \
./src/RCC_config.o \
./src/RCC_prog.o \
./src/main.o 

C_DEPS += \
./src/GPIO.d \
./src/LCD.d \
./src/LCD_CFG.d \
./src/RCC_config.d \
./src/RCC_prog.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000 -I"../include" -I"D:\ITI\Tourkey\Workspace\GPIO_Inshallah\src" -I"D:\ITI\Tourkey\Workspace\NVIC_Inshallah\src" -I"D:\ITI\Tourkey\Workspace\RCC_B2zenllah\src" -I"D:\ITI\Tourkey\Workspace\SCHEDULER_Inshallah\src" -I"D:\ITI\Tourkey\Workspace\SYSTCK_B2znellah\src" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


