################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Lib/driver_i2c.c" \
"../Lib/events.c" \
"../Lib/general.c" \
"../Lib/lcd.c" \
"../Lib/mc9s08jm60.c" \
"../Lib/realtimec.c" \
"../Lib/sci.c" \
"../Lib/timer.c" \

C_SRCS += \
../Lib/driver_i2c.c \
../Lib/events.c \
../Lib/general.c \
../Lib/lcd.c \
../Lib/mc9s08jm60.c \
../Lib/realtimec.c \
../Lib/sci.c \
../Lib/timer.c \

OBJS += \
./Lib/driver_i2c_c.obj \
./Lib/events_c.obj \
./Lib/general_c.obj \
./Lib/lcd_c.obj \
./Lib/mc9s08jm60_c.obj \
./Lib/realtimec_c.obj \
./Lib/sci_c.obj \
./Lib/timer_c.obj \

OBJS_QUOTED += \
"./Lib/driver_i2c_c.obj" \
"./Lib/events_c.obj" \
"./Lib/general_c.obj" \
"./Lib/lcd_c.obj" \
"./Lib/mc9s08jm60_c.obj" \
"./Lib/realtimec_c.obj" \
"./Lib/sci_c.obj" \
"./Lib/timer_c.obj" \

C_DEPS += \
./Lib/driver_i2c_c.d \
./Lib/events_c.d \
./Lib/general_c.d \
./Lib/lcd_c.d \
./Lib/mc9s08jm60_c.d \
./Lib/realtimec_c.d \
./Lib/sci_c.d \
./Lib/timer_c.d \

C_DEPS_QUOTED += \
"./Lib/driver_i2c_c.d" \
"./Lib/events_c.d" \
"./Lib/general_c.d" \
"./Lib/lcd_c.d" \
"./Lib/mc9s08jm60_c.d" \
"./Lib/realtimec_c.d" \
"./Lib/sci_c.d" \
"./Lib/timer_c.d" \

OBJS_OS_FORMAT += \
./Lib/driver_i2c_c.obj \
./Lib/events_c.obj \
./Lib/general_c.obj \
./Lib/lcd_c.obj \
./Lib/mc9s08jm60_c.obj \
./Lib/realtimec_c.obj \
./Lib/sci_c.obj \
./Lib/timer_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Lib/driver_i2c_c.obj: ../Lib/driver_i2c.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Lib/driver_i2c.args" -ObjN="Lib/driver_i2c_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Lib/%.d: ../Lib/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Lib/events_c.obj: ../Lib/events.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Lib/events.args" -ObjN="Lib/events_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Lib/general_c.obj: ../Lib/general.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Lib/general.args" -ObjN="Lib/general_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Lib/lcd_c.obj: ../Lib/lcd.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Lib/lcd.args" -ObjN="Lib/lcd_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Lib/mc9s08jm60_c.obj: ../Lib/mc9s08jm60.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Lib/mc9s08jm60.args" -ObjN="Lib/mc9s08jm60_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Lib/realtimec_c.obj: ../Lib/realtimec.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Lib/realtimec.args" -ObjN="Lib/realtimec_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Lib/sci_c.obj: ../Lib/sci.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Lib/sci.args" -ObjN="Lib/sci_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Lib/timer_c.obj: ../Lib/timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Lib/timer.args" -ObjN="Lib/timer_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


