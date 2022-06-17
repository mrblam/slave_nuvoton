################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Library/StdDriver/src/clk.c \
../Library/StdDriver/src/retarget.c \
../Library/StdDriver/src/sys.c \
../Library/StdDriver/src/uart.c 

OBJS += \
./Library/clk.o \
./Library/retarget.o \
./Library/sys.o \
./Library/uart.o 

C_DEPS += \
./Library/clk.d \
./Library/retarget.d \
./Library/sys.d \
./Library/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Library/%.o: ../Library/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -I"../Library/CMSIS/Include" -I"../Library/Device/Nuvoton/M0A21/Include" -I"../Library/StdDriver/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


