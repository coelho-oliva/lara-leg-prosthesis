################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/encoder.c \
../Src/freertos.c \
../Src/main.c \
../Src/miscellaneous.c \
../Src/stm32f1xx_hal_msp.c \
../Src/stm32f1xx_hal_timebase_tim.c \
../Src/stm32f1xx_it.c \
../Src/system_stm32f1xx.c 

OBJS += \
./Src/encoder.o \
./Src/freertos.o \
./Src/main.o \
./Src/miscellaneous.o \
./Src/stm32f1xx_hal_msp.o \
./Src/stm32f1xx_hal_timebase_tim.o \
./Src/stm32f1xx_it.o \
./Src/system_stm32f1xx.o 

C_DEPS += \
./Src/encoder.d \
./Src/freertos.d \
./Src/main.d \
./Src/miscellaneous.d \
./Src/stm32f1xx_hal_msp.d \
./Src/stm32f1xx_hal_timebase_tim.d \
./Src/stm32f1xx_it.d \
./Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -I"C:/Users/lemos/Documents/stm32projects/NEW/RLEG_FREERTOS_ENCODER/Inc" -I"C:/Users/lemos/Documents/stm32projects/NEW/RLEG_FREERTOS_ENCODER/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/Users/lemos/Documents/stm32projects/NEW/RLEG_FREERTOS_ENCODER/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"C:/Users/lemos/Documents/stm32projects/NEW/RLEG_FREERTOS_ENCODER/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/lemos/Documents/stm32projects/NEW/RLEG_FREERTOS_ENCODER/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/lemos/Documents/stm32projects/NEW/RLEG_FREERTOS_ENCODER/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3" -I"C:/Users/lemos/Documents/stm32projects/NEW/RLEG_FREERTOS_ENCODER/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Users/lemos/Documents/stm32projects/NEW/RLEG_FREERTOS_ENCODER/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

