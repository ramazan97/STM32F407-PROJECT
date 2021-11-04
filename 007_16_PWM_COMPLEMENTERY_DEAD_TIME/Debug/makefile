################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
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


BUILD_ARTIFACT_NAME := 007_16_PWM_COMPLEMENTERY_DEAD_TIME
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
007_16_PWM_COMPLEMENTERY_DEAD_TIME.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
007_16_PWM_COMPLEMENTERY_DEAD_TIME.list \

OBJCOPY_BIN += \
007_16_PWM_COMPLEMENTERY_DEAD_TIME.bin \


# All Target
all: main-build

# Main-build Target
main-build: 007_16_PWM_COMPLEMENTERY_DEAD_TIME.elf secondary-outputs

# Tool invocations
007_16_PWM_COMPLEMENTERY_DEAD_TIME.elf: $(OBJS) $(USER_OBJS) D:\STMCubemxIDE\workspace_1.6.1\007_16_PWM_COMPLEMENTERY_DEAD_TIME\STM32F407VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "007_16_PWM_COMPLEMENTERY_DEAD_TIME.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\STMCubemxIDE\workspace_1.6.1\007_16_PWM_COMPLEMENTERY_DEAD_TIME\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="007_16_PWM_COMPLEMENTERY_DEAD_TIME.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

007_16_PWM_COMPLEMENTERY_DEAD_TIME.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "007_16_PWM_COMPLEMENTERY_DEAD_TIME.list"
	@echo 'Finished building: $@'
	@echo ' '

007_16_PWM_COMPLEMENTERY_DEAD_TIME.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "007_16_PWM_COMPLEMENTERY_DEAD_TIME.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SIZE_OUTPUT)$(OBJDUMP_LIST)$(EXECUTABLES)$(OBJS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS)$(OBJCOPY_BIN) 007_16_PWM_COMPLEMENTERY_DEAD_TIME.elf
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
