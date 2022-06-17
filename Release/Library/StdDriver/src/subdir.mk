################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Library/StdDriver/src/acmp.c \
../Library/StdDriver/src/adc.c \
../Library/StdDriver/src/can.c \
../Library/StdDriver/src/clk.c \
../Library/StdDriver/src/crc.c \
../Library/StdDriver/src/dac.c \
../Library/StdDriver/src/fmc.c \
../Library/StdDriver/src/gpio.c \
../Library/StdDriver/src/pdma.c \
../Library/StdDriver/src/pwm.c \
../Library/StdDriver/src/retarget.c \
../Library/StdDriver/src/sys.c \
../Library/StdDriver/src/timer.c \
../Library/StdDriver/src/uart.c \
../Library/StdDriver/src/usci_i2c.c \
../Library/StdDriver/src/usci_spi.c \
../Library/StdDriver/src/usci_uart.c \
../Library/StdDriver/src/wdt.c \
../Library/StdDriver/src/wwdt.c 

C_DEPS += \
./Library/StdDriver/src/acmp.d \
./Library/StdDriver/src/adc.d \
./Library/StdDriver/src/can.d \
./Library/StdDriver/src/clk.d \
./Library/StdDriver/src/crc.d \
./Library/StdDriver/src/dac.d \
./Library/StdDriver/src/fmc.d \
./Library/StdDriver/src/gpio.d \
./Library/StdDriver/src/pdma.d \
./Library/StdDriver/src/pwm.d \
./Library/StdDriver/src/retarget.d \
./Library/StdDriver/src/sys.d \
./Library/StdDriver/src/timer.d \
./Library/StdDriver/src/uart.d \
./Library/StdDriver/src/usci_i2c.d \
./Library/StdDriver/src/usci_spi.d \
./Library/StdDriver/src/usci_uart.d \
./Library/StdDriver/src/wdt.d \
./Library/StdDriver/src/wwdt.d 

OBJS += \
./Library/StdDriver/src/acmp.o \
./Library/StdDriver/src/adc.o \
./Library/StdDriver/src/can.o \
./Library/StdDriver/src/clk.o \
./Library/StdDriver/src/crc.o \
./Library/StdDriver/src/dac.o \
./Library/StdDriver/src/fmc.o \
./Library/StdDriver/src/gpio.o \
./Library/StdDriver/src/pdma.o \
./Library/StdDriver/src/pwm.o \
./Library/StdDriver/src/retarget.o \
./Library/StdDriver/src/sys.o \
./Library/StdDriver/src/timer.o \
./Library/StdDriver/src/uart.o \
./Library/StdDriver/src/usci_i2c.o \
./Library/StdDriver/src/usci_spi.o \
./Library/StdDriver/src/usci_uart.o \
./Library/StdDriver/src/wdt.o \
./Library/StdDriver/src/wwdt.o 


# Each subdirectory must supply rules for building sources it contributes
Library/StdDriver/src/%.o: ../Library/StdDriver/src/%.c Library/StdDriver/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -I"../Library/CMSIS/Include" -I"../Library/Device/Nuvoton/M0A21/Include" -I"../Library/StdDriver/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Library-2f-StdDriver-2f-src

clean-Library-2f-StdDriver-2f-src:
	-$(RM) ./Library/StdDriver/src/acmp.d ./Library/StdDriver/src/acmp.o ./Library/StdDriver/src/adc.d ./Library/StdDriver/src/adc.o ./Library/StdDriver/src/can.d ./Library/StdDriver/src/can.o ./Library/StdDriver/src/clk.d ./Library/StdDriver/src/clk.o ./Library/StdDriver/src/crc.d ./Library/StdDriver/src/crc.o ./Library/StdDriver/src/dac.d ./Library/StdDriver/src/dac.o ./Library/StdDriver/src/fmc.d ./Library/StdDriver/src/fmc.o ./Library/StdDriver/src/gpio.d ./Library/StdDriver/src/gpio.o ./Library/StdDriver/src/pdma.d ./Library/StdDriver/src/pdma.o ./Library/StdDriver/src/pwm.d ./Library/StdDriver/src/pwm.o ./Library/StdDriver/src/retarget.d ./Library/StdDriver/src/retarget.o ./Library/StdDriver/src/sys.d ./Library/StdDriver/src/sys.o ./Library/StdDriver/src/timer.d ./Library/StdDriver/src/timer.o ./Library/StdDriver/src/uart.d ./Library/StdDriver/src/uart.o ./Library/StdDriver/src/usci_i2c.d ./Library/StdDriver/src/usci_i2c.o ./Library/StdDriver/src/usci_spi.d ./Library/StdDriver/src/usci_spi.o ./Library/StdDriver/src/usci_uart.d ./Library/StdDriver/src/usci_uart.o ./Library/StdDriver/src/wdt.d ./Library/StdDriver/src/wdt.o ./Library/StdDriver/src/wwdt.d ./Library/StdDriver/src/wwdt.o

.PHONY: clean-Library-2f-StdDriver-2f-src

