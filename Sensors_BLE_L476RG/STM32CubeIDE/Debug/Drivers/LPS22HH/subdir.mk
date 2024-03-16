################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/LPS22HH/lps22hh_reg.c 

OBJS += \
./Drivers/LPS22HH/lps22hh_reg.o 

C_DEPS += \
./Drivers/LPS22HH/lps22hh_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/LPS22HH/%.o Drivers/LPS22HH/%.su Drivers/LPS22HH/%.cyclo: ../Drivers/LPS22HH/%.c Drivers/LPS22HH/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DBLE2_DEBUG=1 -c -I../../Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../Middlewares/ST/BlueNRG-2/utils -I../../Middlewares/ST/BlueNRG-2/includes -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/HTS221" -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/LPS22HH" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-LPS22HH

clean-Drivers-2f-LPS22HH:
	-$(RM) ./Drivers/LPS22HH/lps22hh_reg.cyclo ./Drivers/LPS22HH/lps22hh_reg.d ./Drivers/LPS22HH/lps22hh_reg.o ./Drivers/LPS22HH/lps22hh_reg.su

.PHONY: clean-Drivers-2f-LPS22HH

