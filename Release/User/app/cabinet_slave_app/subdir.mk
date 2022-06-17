################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/app/cabinet_slave_app/cabinet_slave_app.c 

C_DEPS += \
./User/app/cabinet_slave_app/cabinet_slave_app.d 

OBJS += \
./User/app/cabinet_slave_app/cabinet_slave_app.o 


# Each subdirectory must supply rules for building sources it contributes
User/app/cabinet_slave_app/%.o: ../User/app/cabinet_slave_app/%.c User/app/cabinet_slave_app/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -I"../Library/CMSIS/Include" -I"../Library/Device/Nuvoton/M0A21/Include" -I"../Library/StdDriver/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-User-2f-app-2f-cabinet_slave_app

clean-User-2f-app-2f-cabinet_slave_app:
	-$(RM) ./User/app/cabinet_slave_app/cabinet_slave_app.d ./User/app/cabinet_slave_app/cabinet_slave_app.o

.PHONY: clean-User-2f-app-2f-cabinet_slave_app

