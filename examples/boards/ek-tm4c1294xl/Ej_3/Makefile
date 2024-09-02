
#
# Defines the part type that this project uses.
#
PART=TM4C1294NCPDT

#
# The base directory for TivaWare.
#
ROOT=../../../..

#
# Include the common make definitions.
#
include ${ROOT}/makedefs

#
# Where to find header files that do not live in the source directory.
#
IPATH=../../../..

#
# The default rule, which causes the blinky example to be built.
#
all: ${COMPILER}
all: ${COMPILER}/Ej_3.axf

#
# The rule to clean out all the build products.
#
clean:
	@rm -rf ${COMPILER} ${wildcard *~}

#
# The rule to create the target directory.
#
${COMPILER}:
	@mkdir -p ${COMPILER}

#
# Rules for building the blinky example.
#
${COMPILER}/Ej_3.axf: ${COMPILER}/Ej_3.o
${COMPILER}/Ej_3.axf: ${COMPILER}/startup_${COMPILER}.o
${COMPILER}/Ej_3.axf: ${ROOT}/driverlib/${COMPILER}/libdriver.a
${COMPILER}/Ej_3.axf: Ej_3.ld
SCATTERgcc_Ej_3=Ej_3.ld
ENTRY_Ej_3=ResetISR
CFLAGSgcc=-DTARGET_IS_TM4C129_RA1

#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard ${COMPILER}/*.d} __dummy__
endif
