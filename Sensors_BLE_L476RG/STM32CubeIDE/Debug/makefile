################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/BlueNRG-2/Wireless/BlueNRG-2/Utils/subdir.mk
-include Middlewares/BlueNRG-2/Wireless/BlueNRG-2/HCI_TL/Basic/subdir.mk
-include Middlewares/BlueNRG-2/Wireless/BlueNRG-2/Controller/subdir.mk
-include Drivers/STM32L4xx_HAL_Driver/subdir.mk
-include Drivers/LPS22HH/subdir.mk
-include Drivers/HTS221/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Drivers/BSP/STM32L4xx_Nucleo/subdir.mk
-include Application/User/subdir.mk
-include Application/Startup/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := SensorDemo_BLE_l476rg
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
SensorDemo_BLE_l476rg.elf \

MAP_FILES += \
SensorDemo_BLE_l476rg.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
SensorDemo_BLE_l476rg.list \


# All Target
all: main-build

# Main-build Target
main-build: SensorDemo_BLE_l476rg.elf secondary-outputs

# Tool invocations
SensorDemo_BLE_l476rg.elf SensorDemo_BLE_l476rg.map: $(OBJS) $(USER_OBJS) C:\Users\leooh\Documents\Ecole\Universite\M1\LE\TP2\SensorDemo_BLE_l476rg-main\STM32CubeIDE\STM32L476RGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "SensorDemo_BLE_l476rg.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\leooh\Documents\Ecole\Universite\M1\LE\TP2\SensorDemo_BLE_l476rg-main\STM32CubeIDE\STM32L476RGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="SensorDemo_BLE_l476rg.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

SensorDemo_BLE_l476rg.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "SensorDemo_BLE_l476rg.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) SensorDemo_BLE_l476rg.elf SensorDemo_BLE_l476rg.list SensorDemo_BLE_l476rg.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
