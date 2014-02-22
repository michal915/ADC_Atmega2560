################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include HD44780/subdir.mk
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
ADC_mega.lss \

FLASH_IMAGE += \
ADC_mega.hex \

EEPROM_IMAGE += \
ADC_mega.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: ADC_mega.elf secondary-outputs

# Tool invocations
ADC_mega.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ADC_mega.map -Wl,-u,vfprintf -mmcu=atmega2560 -o "ADC_mega.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ADC_mega.lss: ADC_mega.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ADC_mega.elf  >"ADC_mega.lss"
	@echo 'Finished building: $@'
	@echo ' '

ADC_mega.hex: ADC_mega.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex ADC_mega.elf  "ADC_mega.hex"
	@echo 'Finished building: $@'
	@echo ' '

ADC_mega.eep: ADC_mega.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ADC_mega.elf  "ADC_mega.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ADC_mega.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega2560 ADC_mega.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) ADC_mega.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
