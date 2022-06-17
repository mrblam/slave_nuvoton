################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/app/peripheral_init/peripheral_init.c 

C_DEPS += \
./User/app/peripheral_init/peripheral_init.d 

OBJS += \
./User/app/peripheral_init/peripheral_init.o 


# Each subdirectory must supply rules for building sources it contributes
User/app/peripheral_init/%.o: ../User/app/peripheral_init/%.c User/app/peripheral_init/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -I"../Library/CMSIS/Include" -I"../Library/Device/Nuvoton/M0A21/Include" -I"../Library/StdDriver/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-User-2f-app-2f-peripheral_init

clean-User-2f-app-2f-peripheral_init:
	-$(RM) ./User/app/peripheral_init/peripheral_init.d ./User/app/peripheral_init/peripheral_init.o

.PHONY: clean-User-2f-app-2f-peripheral_init

