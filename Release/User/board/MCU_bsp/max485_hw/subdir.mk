################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/board/MCU_bsp/max485_hw/max485_hw.c 

OBJS += \
./User/board/MCU_bsp/max485_hw/max485_hw.o 

C_DEPS += \
./User/board/MCU_bsp/max485_hw/max485_hw.d 


# Each subdirectory must supply rules for building sources it contributes
User/board/MCU_bsp/max485_hw/%.o: ../User/board/MCU_bsp/max485_hw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -I"../Library/CMSIS/Include" -I"../Library/Device/Nuvoton/M0A21/Include" -I"../Library/StdDriver/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


