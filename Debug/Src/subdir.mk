################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/freertos.c \
../Src/main.c \
../Src/nn_commands.c \
../Src/nn_console.c \
../Src/nn_serial.c \
../Src/nn_threads.c \
../Src/nn_tim.c \
../Src/stm32f1xx_hal_msp.c \
../Src/stm32f1xx_hal_timebase_TIM.c \
../Src/stm32f1xx_it.c \
../Src/system_stm32f1xx.c 

OBJS += \
./Src/freertos.o \
./Src/main.o \
./Src/nn_commands.o \
./Src/nn_console.o \
./Src/nn_serial.o \
./Src/nn_threads.o \
./Src/nn_tim.o \
./Src/stm32f1xx_hal_msp.o \
./Src/stm32f1xx_hal_timebase_TIM.o \
./Src/stm32f1xx_it.o \
./Src/system_stm32f1xx.o 

C_DEPS += \
./Src/freertos.d \
./Src/main.d \
./Src/nn_commands.d \
./Src/nn_console.d \
./Src/nn_serial.d \
./Src/nn_threads.d \
./Src/nn_tim.d \
./Src/stm32f1xx_hal_msp.d \
./Src/stm32f1xx_hal_timebase_TIM.d \
./Src/stm32f1xx_it.d \
./Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -I"C:/myfiles/workspace/stm_prj/dev_udin/Inc" -I"C:/myfiles/workspace/stm_prj/dev_udin/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/myfiles/workspace/stm_prj/dev_udin/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"C:/myfiles/workspace/stm_prj/dev_udin/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3" -I"C:/myfiles/workspace/stm_prj/dev_udin/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/myfiles/workspace/stm_prj/dev_udin/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/myfiles/workspace/stm_prj/dev_udin/Middlewares/Third_Party/FreeRTOS-Plus/Source/FreeRTOS-Plus-CLI" -I"C:/myfiles/workspace/stm_prj/dev_udin/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/myfiles/workspace/stm_prj/dev_udin/Drivers/CMSIS/Include" -I"C:/myfiles/workspace/stm_prj/dev_udin/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


