################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.c 

OBJS += \
./Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.o 

C_DEPS += \
./Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.o: ../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L052xx -DDEBUG -c -I../USB_DEVICE/Target -I../Drivers/CMSIS/Include -I../Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../USB_DEVICE/App -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

