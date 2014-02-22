################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ADC1.lss \

FLASH_IMAGE += \
ADC1.hex \

EEPROM_IMAGE += \
ADC1.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: ADC1.elf secondary-outputs

# Tool invocations
ADC1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ADC1.map -mmcu=atmega2560 -o "ADC1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ADC1.lss: ADC1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ADC1.elf  >"ADC1.lss"
	@echo 'Finished building: $@'
	@echo ' '

ADC1.hex: ADC1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex ADC1.elf  "ADC1.hex"
	@echo 'Finished building: $@'
	@echo ' '

ADC1.eep: ADC1.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ADC1.elf  "ADC1.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ADC1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega2560 ADC1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) ADC1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
