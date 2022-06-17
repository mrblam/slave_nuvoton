################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/components/rgb_led/rgb_led.c 

C_DEPS += \
./User/components/rgb_led/rgb_led.d 

OBJS += \
./User/components/rgb_led/rgb_led.o 


# Each subdirectory must supply rules for building sources it contributes
User/components/rgb_led/%.o: ../User/components/rgb_led/%.c User/components/rgb_led/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -I"../Library/CMSIS/Include" -I"../Library/Device/Nuvoton/M0A21/Include" -I"../Library/StdDriver/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-User-2f-components-2f-rgb_led

clean-User-2f-components-2f-rgb_led:
	-$(RM) ./User/components/rgb_led/rgb_led.d ./User/components/rgb_led/rgb_led.o

.PHONY: clean-User-2f-components-2f-rgb_led

