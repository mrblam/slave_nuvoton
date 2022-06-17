################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/components/adc_sensor/adc_sensor.c 

C_DEPS += \
./User/components/adc_sensor/adc_sensor.d 

OBJS += \
./User/components/adc_sensor/adc_sensor.o 


# Each subdirectory must supply rules for building sources it contributes
User/components/adc_sensor/%.o: ../User/components/adc_sensor/%.c User/components/adc_sensor/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -I"../Library/CMSIS/Include" -I"../Library/Device/Nuvoton/M0A21/Include" -I"../Library/StdDriver/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-User-2f-components-2f-adc_sensor

clean-User-2f-components-2f-adc_sensor:
	-$(RM) ./User/components/adc_sensor/adc_sensor.d ./User/components/adc_sensor/adc_sensor.o

.PHONY: clean-User-2f-components-2f-adc_sensor

