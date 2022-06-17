################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/util/string/subdir.mk
-include User/service/rs485_slave/subdir.mk
-include User/components/switch/subdir.mk
-include User/components/rgb_led/subdir.mk
-include User/components/ntc/subdir.mk
-include User/components/adc_sensor/subdir.mk
-include User/board/nuvoton_bsp/uart_hw/subdir.mk
-include User/board/nuvoton_bsp/core_hw/subdir.mk
-include User/board/nuvoton_bsp/cabinet_slave_hw/subdir.mk
-include User/board/nuvoton_bsp/adc_hw/subdir.mk
-include User/board/subdir.mk
-include User/app/peripheral_init/subdir.mk
-include User/app/cabinet_slave_app/subdir.mk
-include User/subdir.mk
-include Library/StdDriver/src/subdir.mk
-include CMSIS/GCC/subdir.mk
-include CMSIS/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := HelloWorld
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
HelloWorld.hex \

SECONDARY_SIZE += \
HelloWorld.siz \


# All Target
all: main-build

# Main-build Target
main-build: HelloWorld.elf secondary-outputs

# Tool invocations
HelloWorld.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM GNU C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -T gcc_arm.ld -Xlinker --gc-sections -L"../CMSIS/GCC" -Wl,-Map,"HelloWorld.map" --specs=nano.specs -o "HelloWorld.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

HelloWorld.hex: HelloWorld.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy -O ihex "HelloWorld.elf"  "HelloWorld.hex"
	@echo 'Finished building: $@'
	@echo ' '

HelloWorld.siz: HelloWorld.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-none-eabi-size --format=berkeley "HelloWorld.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) HelloWorld.elf HelloWorld.hex HelloWorld.siz
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build

-include ../makefile.targets
