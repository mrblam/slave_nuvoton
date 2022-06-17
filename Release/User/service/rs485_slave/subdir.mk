################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/service/rs485_slave/rs485_slave.c 

C_DEPS += \
./User/service/rs485_slave/rs485_slave.d 

OBJS += \
./User/service/rs485_slave/rs485_slave.o 


# Each subdirectory must supply rules for building sources it contributes
User/service/rs485_slave/%.o: ../User/service/rs485_slave/%.c User/service/rs485_slave/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -I"../Library/CMSIS/Include" -I"../Library/Device/Nuvoton/M0A21/Include" -I"../Library/StdDriver/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-User-2f-service-2f-rs485_slave

clean-User-2f-service-2f-rs485_slave:
	-$(RM) ./User/service/rs485_slave/rs485_slave.d ./User/service/rs485_slave/rs485_slave.o

.PHONY: clean-User-2f-service-2f-rs485_slave

