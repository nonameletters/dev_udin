################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.o 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/%.o: ../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -I"C:/myfiles/workspace/stm_prj/dev_udin/Inc" -I"C:/myfiles/workspace/stm_prj/dev_udin/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/myfiles/workspace/stm_prj/dev_udin/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"C:/myfiles/workspace/stm_prj/dev_udin/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3" -I"C:/myfiles/workspace/stm_prj/dev_udin/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/myfiles/workspace/stm_prj/dev_udin/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/myfiles/workspace/stm_prj/dev_udin/Middlewares/Third_Party/FreeRTOS-Plus/Source/FreeRTOS-Plus-CLI" -I"C:/myfiles/workspace/stm_prj/dev_udin/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/myfiles/workspace/stm_prj/dev_udin/Drivers/CMSIS/Include" -I"C:/myfiles/workspace/stm_prj/dev_udin/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


