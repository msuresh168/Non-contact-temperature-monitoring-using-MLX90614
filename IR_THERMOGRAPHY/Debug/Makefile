################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../i2c.c \
../IR_THERMOGRAPHY.c \
../lcd.c \
../MLX90614.c \
../UART.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
i2c.o \
IR_THERMOGRAPHY.o \
lcd.o \
MLX90614.o \
UART.o


OBJS_AS_ARGS +=  \
i2c.o \
IR_THERMOGRAPHY.o \
lcd.o \
MLX90614.o \
UART.o


C_DEPS +=  \
i2c.d \
IR_THERMOGRAPHY.d \
lcd.d \
MLX90614.d \
UART.d


C_DEPS_AS_ARGS +=  \
i2c.d \
IR_THERMOGRAPHY.d \
lcd.d \
MLX90614.d \
UART.d


OUTPUT_FILE_PATH +=IR_THERMOGRAPHY.elf

OUTPUT_FILE_PATH_AS_ARGS +=IR_THERMOGRAPHY.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

# AVR32/GNU C Compiler











./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.876\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG  -O1 -ffunction-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o"$@" "$<" 
	@echo Finished building: $<



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.876\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="IR_THERMOGRAPHY.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32 
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.876\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "IR_THERMOGRAPHY.elf" "IR_THERMOGRAPHY.hex"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.876\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "IR_THERMOGRAPHY.elf" "IR_THERMOGRAPHY.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.876\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "IR_THERMOGRAPHY.elf" > "IR_THERMOGRAPHY.lss"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.876\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "IR_THERMOGRAPHY.elf" "IR_THERMOGRAPHY.srec"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.876\avr8-gnu-toolchain\bin\avr-size.exe" "IR_THERMOGRAPHY.elf"
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS)$(C_DEPS_AS_ARGS) $(EXECUTABLES) 
	rm -rf "IR_THERMOGRAPHY.elf" "IR_THERMOGRAPHY.a" "IR_THERMOGRAPHY.hex" "IR_THERMOGRAPHY.lss" "IR_THERMOGRAPHY.eep" "IR_THERMOGRAPHY.map" "IR_THERMOGRAPHY.srec"
	