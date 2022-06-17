################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/GCC/_syscalls.c 

S_UPPER_SRCS += \
../CMSIS/GCC/startup_M0A21.S 

C_DEPS += \
./CMSIS/GCC/_syscalls.d 

OBJS += \
./CMSIS/GCC/_syscalls.o \
./CMSIS/GCC/startup_M0A21.o 

S_UPPER_DEPS += \
./CMSIS/GCC/startup_M0A21.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/GCC/%.o: ../CMSIS/GCC/%.c CMSIS/GCC/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -I"../Library/CMSIS/Include" -I"../Library/Device/Nuvoton/M0A21/Include" -I"../Library/StdDriver/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

CMSIS/GCC/%.o: ../CMSIS/GCC/%.S CMSIS/GCC/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -x assembler-with-cpp -I"../Library/CMSIS/Include" -I"../Library/Device/Nuvoton/M0A21/Include" -I"../Library/StdDriver/inc" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-CMSIS-2f-GCC

clean-CMSIS-2f-GCC:
	-$(RM) ./CMSIS/GCC/_syscalls.d ./CMSIS/GCC/_syscalls.o ./CMSIS/GCC/startup_M0A21.d ./CMSIS/GCC/startup_M0A21.o

.PHONY: clean-CMSIS-2f-GCC

