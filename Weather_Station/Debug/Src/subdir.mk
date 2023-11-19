################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/AFIO_program.c \
../Src/DIO_program.c \
../Src/EXTI_program.c \
../Src/GSM_program.c \
../Src/I2C_program.c \
../Src/NVIC_program.c \
../Src/RCC_program.c \
../Src/SHT.c \
../Src/SoilSensor.c \
../Src/USART3_program.c \
../Src/USART_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/AFIO_program.o \
./Src/DIO_program.o \
./Src/EXTI_program.o \
./Src/GSM_program.o \
./Src/I2C_program.o \
./Src/NVIC_program.o \
./Src/RCC_program.o \
./Src/SHT.o \
./Src/SoilSensor.o \
./Src/USART3_program.o \
./Src/USART_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/AFIO_program.d \
./Src/DIO_program.d \
./Src/EXTI_program.d \
./Src/GSM_program.d \
./Src/I2C_program.d \
./Src/NVIC_program.d \
./Src/RCC_program.d \
./Src/SHT.d \
./Src/SoilSensor.d \
./Src/USART3_program.d \
./Src/USART_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/AFIO_program.cyclo ./Src/AFIO_program.d ./Src/AFIO_program.o ./Src/AFIO_program.su ./Src/DIO_program.cyclo ./Src/DIO_program.d ./Src/DIO_program.o ./Src/DIO_program.su ./Src/EXTI_program.cyclo ./Src/EXTI_program.d ./Src/EXTI_program.o ./Src/EXTI_program.su ./Src/GSM_program.cyclo ./Src/GSM_program.d ./Src/GSM_program.o ./Src/GSM_program.su ./Src/I2C_program.cyclo ./Src/I2C_program.d ./Src/I2C_program.o ./Src/I2C_program.su ./Src/NVIC_program.cyclo ./Src/NVIC_program.d ./Src/NVIC_program.o ./Src/NVIC_program.su ./Src/RCC_program.cyclo ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/SHT.cyclo ./Src/SHT.d ./Src/SHT.o ./Src/SHT.su ./Src/SoilSensor.cyclo ./Src/SoilSensor.d ./Src/SoilSensor.o ./Src/SoilSensor.su ./Src/USART3_program.cyclo ./Src/USART3_program.d ./Src/USART3_program.o ./Src/USART3_program.su ./Src/USART_program.cyclo ./Src/USART_program.d ./Src/USART_program.o ./Src/USART_program.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

