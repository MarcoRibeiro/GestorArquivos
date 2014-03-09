################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../catalogosAutores.c \
../estatisticas.c \
../indiceAutores.c \
../main.c \
../menu.c 

OBJS += \
./catalogosAutores.o \
./estatisticas.o \
./indiceAutores.o \
./main.o \
./menu.o 

C_DEPS += \
./catalogosAutores.d \
./estatisticas.d \
./indiceAutores.d \
./main.d \
./menu.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


