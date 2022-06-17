################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/components/switch/switch.c 

C_DEPS += \
./User/components/switch/switch.d 

OBJS += \
./User/components/switch/switch.o 


# Each subdirectory must supply rules for building sources it contributes
User/components/switch/%.o: ../User/components/switch/%.c User/components/switch/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -I"../Library/CMSIS/Include" -I"../Library/Device/Nuvoton/M0A21/Include" -I"../Library/StdDriver/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-User-2f-components-2f-switch

clean-User-2f-components-2f-switch:
	-$(RM) ./User/components/switch/switch.d ./User/components/switch/switch.o

.PHONY: clean-User-2f-components-2f-switch

