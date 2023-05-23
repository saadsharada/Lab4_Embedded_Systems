################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Gpio/GPIO_Adress.c 

OBJS += \
./Gpio/GPIO_Adress.o 

C_DEPS += \
./Gpio/GPIO_Adress.d 


# Each subdirectory must supply rules for building sources it contributes
Gpio/%.o: ../Gpio/%.c Gpio/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"D:\Embedded Systems ARM\Lab4_Startup_Project_TODO\Lib" -I"D:\Embedded Systems ARM\Lab4_Startup_Project_TODO\Rcc" -I"D:\Embedded Systems ARM\Lab4_Startup_Project_TODO\Gpio" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


