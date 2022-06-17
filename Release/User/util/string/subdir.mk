################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/util/string/string_util.c 

C_DEPS += \
./User/util/string/string_util.d 

OBJS += \
./User/util/string/string_util.o 


# Each subdirectory must supply rules for building sources it contributes
User/util/string/%.o: ../User/util/string/%.c User/util/string/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -I"../Library/CMSIS/Include" -I"../Library/Device/Nuvoton/M0A21/Include" -I"../Library/StdDriver/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-User-2f-util-2f-string

clean-User-2f-util-2f-string:
	-$(RM) ./User/util/string/string_util.d ./User/util/string/string_util.o

.PHONY: clean-User-2f-util-2f-string

