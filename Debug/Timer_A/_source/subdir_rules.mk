################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Timer_A/_source/%.obj: ../Timer_A/_source/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-msp430_20.2.0.LTS/bin/cl430" -vmsp --use_hw_mpy=none --include_path="C:/ti/ccs1000/ccs/ccs_base/msp430/include" --include_path="C:/Users/Jesus/workspace_v10/Timer" --include_path="C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-msp430_20.2.0.LTS/include" --advice:power=all --define=__MSP430G2253__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="Timer_A/_source/$(basename $(<F)).d_raw" --obj_directory="Timer_A/_source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


