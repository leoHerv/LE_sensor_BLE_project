################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/app_bluenrg_2.c \
C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/bsp.c \
C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/gatt_db.c \
C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/gpio.c \
C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/hci_tl_interface.c \
C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/i2c.c \
C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/main.c \
C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/sensor.c \
C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/stm32l4xx_hal_msp.c \
C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/stm32l4xx_it.c \
C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/stm32l4xx_nucleo_bus.c \
../Application/User/syscalls.c \
../Application/User/sysmem.c 

OBJS += \
./Application/User/app_bluenrg_2.o \
./Application/User/bsp.o \
./Application/User/gatt_db.o \
./Application/User/gpio.o \
./Application/User/hci_tl_interface.o \
./Application/User/i2c.o \
./Application/User/main.o \
./Application/User/sensor.o \
./Application/User/stm32l4xx_hal_msp.o \
./Application/User/stm32l4xx_it.o \
./Application/User/stm32l4xx_nucleo_bus.o \
./Application/User/syscalls.o \
./Application/User/sysmem.o 

C_DEPS += \
./Application/User/app_bluenrg_2.d \
./Application/User/bsp.d \
./Application/User/gatt_db.d \
./Application/User/gpio.d \
./Application/User/hci_tl_interface.d \
./Application/User/i2c.d \
./Application/User/main.d \
./Application/User/sensor.d \
./Application/User/stm32l4xx_hal_msp.d \
./Application/User/stm32l4xx_it.d \
./Application/User/stm32l4xx_nucleo_bus.d \
./Application/User/syscalls.d \
./Application/User/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/app_bluenrg_2.o: C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/app_bluenrg_2.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DBLE2_DEBUG=1 -c -I../../Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../Middlewares/ST/BlueNRG-2/utils -I../../Middlewares/ST/BlueNRG-2/includes -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/HTS221" -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/LPS22HH" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/bsp.o: C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/bsp.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DBLE2_DEBUG=1 -c -I../../Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../Middlewares/ST/BlueNRG-2/utils -I../../Middlewares/ST/BlueNRG-2/includes -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/HTS221" -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/LPS22HH" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/gatt_db.o: C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/gatt_db.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DBLE2_DEBUG=1 -c -I../../Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../Middlewares/ST/BlueNRG-2/utils -I../../Middlewares/ST/BlueNRG-2/includes -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/HTS221" -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/LPS22HH" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/gpio.o: C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/gpio.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DBLE2_DEBUG=1 -c -I../../Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../Middlewares/ST/BlueNRG-2/utils -I../../Middlewares/ST/BlueNRG-2/includes -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/HTS221" -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/LPS22HH" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/hci_tl_interface.o: C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/hci_tl_interface.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DBLE2_DEBUG=1 -c -I../../Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../Middlewares/ST/BlueNRG-2/utils -I../../Middlewares/ST/BlueNRG-2/includes -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/HTS221" -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/LPS22HH" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/i2c.o: C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/i2c.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DBLE2_DEBUG=1 -c -I../../Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../Middlewares/ST/BlueNRG-2/utils -I../../Middlewares/ST/BlueNRG-2/includes -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/HTS221" -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/LPS22HH" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/main.o: C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/main.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DBLE2_DEBUG=1 -c -I../../Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../Middlewares/ST/BlueNRG-2/utils -I../../Middlewares/ST/BlueNRG-2/includes -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/HTS221" -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/LPS22HH" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/sensor.o: C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/sensor.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DBLE2_DEBUG=1 -c -I../../Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../Middlewares/ST/BlueNRG-2/utils -I../../Middlewares/ST/BlueNRG-2/includes -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/HTS221" -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/LPS22HH" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32l4xx_hal_msp.o: C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/stm32l4xx_hal_msp.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DBLE2_DEBUG=1 -c -I../../Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../Middlewares/ST/BlueNRG-2/utils -I../../Middlewares/ST/BlueNRG-2/includes -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/HTS221" -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/LPS22HH" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32l4xx_it.o: C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/stm32l4xx_it.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DBLE2_DEBUG=1 -c -I../../Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../Middlewares/ST/BlueNRG-2/utils -I../../Middlewares/ST/BlueNRG-2/includes -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/HTS221" -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/LPS22HH" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32l4xx_nucleo_bus.o: C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/Src/stm32l4xx_nucleo_bus.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DBLE2_DEBUG=1 -c -I../../Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../Middlewares/ST/BlueNRG-2/utils -I../../Middlewares/ST/BlueNRG-2/includes -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/HTS221" -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/LPS22HH" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/%.o Application/User/%.su Application/User/%.cyclo: ../Application/User/%.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DBLE2_DEBUG=1 -c -I../../Inc -I../../Drivers/BSP/STM32L4xx_Nucleo -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../Middlewares/ST/BlueNRG-2/utils -I../../Middlewares/ST/BlueNRG-2/includes -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/HTS221" -I"C:/Users/leooh/Documents/Ecole/Universite/M1/LE/TP2/SensorDemo_BLE_l476rg-main/STM32CubeIDE/Drivers/LPS22HH" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User

clean-Application-2f-User:
	-$(RM) ./Application/User/app_bluenrg_2.cyclo ./Application/User/app_bluenrg_2.d ./Application/User/app_bluenrg_2.o ./Application/User/app_bluenrg_2.su ./Application/User/bsp.cyclo ./Application/User/bsp.d ./Application/User/bsp.o ./Application/User/bsp.su ./Application/User/gatt_db.cyclo ./Application/User/gatt_db.d ./Application/User/gatt_db.o ./Application/User/gatt_db.su ./Application/User/gpio.cyclo ./Application/User/gpio.d ./Application/User/gpio.o ./Application/User/gpio.su ./Application/User/hci_tl_interface.cyclo ./Application/User/hci_tl_interface.d ./Application/User/hci_tl_interface.o ./Application/User/hci_tl_interface.su ./Application/User/i2c.cyclo ./Application/User/i2c.d ./Application/User/i2c.o ./Application/User/i2c.su ./Application/User/main.cyclo ./Application/User/main.d ./Application/User/main.o ./Application/User/main.su ./Application/User/sensor.cyclo ./Application/User/sensor.d ./Application/User/sensor.o ./Application/User/sensor.su ./Application/User/stm32l4xx_hal_msp.cyclo ./Application/User/stm32l4xx_hal_msp.d ./Application/User/stm32l4xx_hal_msp.o ./Application/User/stm32l4xx_hal_msp.su ./Application/User/stm32l4xx_it.cyclo ./Application/User/stm32l4xx_it.d ./Application/User/stm32l4xx_it.o ./Application/User/stm32l4xx_it.su ./Application/User/stm32l4xx_nucleo_bus.cyclo ./Application/User/stm32l4xx_nucleo_bus.d ./Application/User/stm32l4xx_nucleo_bus.o ./Application/User/stm32l4xx_nucleo_bus.su ./Application/User/syscalls.cyclo ./Application/User/syscalls.d ./Application/User/syscalls.o ./Application/User/syscalls.su ./Application/User/sysmem.cyclo ./Application/User/sysmem.d ./Application/User/sysmem.o ./Application/User/sysmem.su

.PHONY: clean-Application-2f-User

