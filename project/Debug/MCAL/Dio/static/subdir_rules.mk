################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
MCAL/Dio/static/Dio.obj: D:/02.\ Embedded\ systems/00.\ Repos/TM4C123-Interface/src/MCAL/Dio/static/Dio.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1100/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/02. Embedded systems/00. Repos/TM4C123-Interface/project" --include_path="D:/02. Embedded systems/00. Repos/TM4C123-Interface/src/Util" --include_path="D:/02. Embedded systems/00. Repos/TM4C123-Interface/src/MCAL/Dio/static" --include_path="D:/02. Embedded systems/00. Repos/TM4C123-Interface/src/MCAL/Dio/config" --include_path="D:/02. Embedded systems/00. Repos/TM4C123-Interface/src/MCAL/Mcu/static" --include_path="D:/02. Embedded systems/00. Repos/TM4C123-Interface/src/MCAL/Mcu/config" --include_path="D:/02. Embedded systems/00. Repos/TM4C123-Interface/src/HAL/Led/static" --include_path="D:/02. Embedded systems/00. Repos/TM4C123-Interface/src/HAL/Led/config" --include_path="D:/02. Embedded systems/00. Repos/TM4C123-Interface/src/HAL/Sw/static" --include_path="D:/02. Embedded systems/00. Repos/TM4C123-Interface/src/HAL/Sw/config" --include_path="C:/ti/ccs1100/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="MCAL/Dio/static/$(basename $(<F)).d_raw" --obj_directory="MCAL/Dio/static" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


