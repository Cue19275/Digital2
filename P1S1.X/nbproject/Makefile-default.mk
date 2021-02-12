#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/P1S1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/P1S1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED="C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/ADCLIB.c" "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/ASCII_NUM.c" "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/LCD8BIT.c" "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/Osc.c" "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/usartP.c" "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/main.c" "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/SPI.c"

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1794776729/ADCLIB.p1 ${OBJECTDIR}/_ext/1794776729/ASCII_NUM.p1 ${OBJECTDIR}/_ext/1794776729/LCD8BIT.p1 ${OBJECTDIR}/_ext/1794776729/Osc.p1 ${OBJECTDIR}/_ext/1794776729/usartP.p1 ${OBJECTDIR}/_ext/1794776729/main.p1 ${OBJECTDIR}/_ext/1794776729/SPI.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1794776729/ADCLIB.p1.d ${OBJECTDIR}/_ext/1794776729/ASCII_NUM.p1.d ${OBJECTDIR}/_ext/1794776729/LCD8BIT.p1.d ${OBJECTDIR}/_ext/1794776729/Osc.p1.d ${OBJECTDIR}/_ext/1794776729/usartP.p1.d ${OBJECTDIR}/_ext/1794776729/main.p1.d ${OBJECTDIR}/_ext/1794776729/SPI.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1794776729/ADCLIB.p1 ${OBJECTDIR}/_ext/1794776729/ASCII_NUM.p1 ${OBJECTDIR}/_ext/1794776729/LCD8BIT.p1 ${OBJECTDIR}/_ext/1794776729/Osc.p1 ${OBJECTDIR}/_ext/1794776729/usartP.p1 ${OBJECTDIR}/_ext/1794776729/main.p1 ${OBJECTDIR}/_ext/1794776729/SPI.p1

# Source Files
SOURCEFILES=C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/ADCLIB.c C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/ASCII_NUM.c C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/LCD8BIT.c C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/Osc.c C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/usartP.c C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/main.c C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/SPI.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/P1S1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=16F887
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1794776729/ADCLIB.p1: C:/Users/Carlo/OneDrive/Documentos/Quinto\ Semestre/Digital2/P1S1.X/ADCLIB.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1794776729" 
	@${RM} ${OBJECTDIR}/_ext/1794776729/ADCLIB.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1794776729/ADCLIB.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1794776729/ADCLIB.p1 "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/ADCLIB.c" 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1794776729/ADCLIB.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1794776729/ASCII_NUM.p1: C:/Users/Carlo/OneDrive/Documentos/Quinto\ Semestre/Digital2/P1S1.X/ASCII_NUM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1794776729" 
	@${RM} ${OBJECTDIR}/_ext/1794776729/ASCII_NUM.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1794776729/ASCII_NUM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1794776729/ASCII_NUM.p1 "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/ASCII_NUM.c" 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1794776729/ASCII_NUM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1794776729/LCD8BIT.p1: C:/Users/Carlo/OneDrive/Documentos/Quinto\ Semestre/Digital2/P1S1.X/LCD8BIT.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1794776729" 
	@${RM} ${OBJECTDIR}/_ext/1794776729/LCD8BIT.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1794776729/LCD8BIT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1794776729/LCD8BIT.p1 "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/LCD8BIT.c" 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1794776729/LCD8BIT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1794776729/Osc.p1: C:/Users/Carlo/OneDrive/Documentos/Quinto\ Semestre/Digital2/P1S1.X/Osc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1794776729" 
	@${RM} ${OBJECTDIR}/_ext/1794776729/Osc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1794776729/Osc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1794776729/Osc.p1 "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/Osc.c" 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1794776729/Osc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1794776729/usartP.p1: C:/Users/Carlo/OneDrive/Documentos/Quinto\ Semestre/Digital2/P1S1.X/usartP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1794776729" 
	@${RM} ${OBJECTDIR}/_ext/1794776729/usartP.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1794776729/usartP.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1794776729/usartP.p1 "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/usartP.c" 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1794776729/usartP.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1794776729/main.p1: C:/Users/Carlo/OneDrive/Documentos/Quinto\ Semestre/Digital2/P1S1.X/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1794776729" 
	@${RM} ${OBJECTDIR}/_ext/1794776729/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1794776729/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1794776729/main.p1 "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/main.c" 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1794776729/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1794776729/SPI.p1: C:/Users/Carlo/OneDrive/Documentos/Quinto\ Semestre/Digital2/P1S1.X/SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1794776729" 
	@${RM} ${OBJECTDIR}/_ext/1794776729/SPI.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1794776729/SPI.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1794776729/SPI.p1 "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/SPI.c" 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1794776729/SPI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/1794776729/ADCLIB.p1: C:/Users/Carlo/OneDrive/Documentos/Quinto\ Semestre/Digital2/P1S1.X/ADCLIB.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1794776729" 
	@${RM} ${OBJECTDIR}/_ext/1794776729/ADCLIB.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1794776729/ADCLIB.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1794776729/ADCLIB.p1 "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/ADCLIB.c" 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1794776729/ADCLIB.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1794776729/ASCII_NUM.p1: C:/Users/Carlo/OneDrive/Documentos/Quinto\ Semestre/Digital2/P1S1.X/ASCII_NUM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1794776729" 
	@${RM} ${OBJECTDIR}/_ext/1794776729/ASCII_NUM.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1794776729/ASCII_NUM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1794776729/ASCII_NUM.p1 "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/ASCII_NUM.c" 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1794776729/ASCII_NUM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1794776729/LCD8BIT.p1: C:/Users/Carlo/OneDrive/Documentos/Quinto\ Semestre/Digital2/P1S1.X/LCD8BIT.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1794776729" 
	@${RM} ${OBJECTDIR}/_ext/1794776729/LCD8BIT.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1794776729/LCD8BIT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1794776729/LCD8BIT.p1 "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/LCD8BIT.c" 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1794776729/LCD8BIT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1794776729/Osc.p1: C:/Users/Carlo/OneDrive/Documentos/Quinto\ Semestre/Digital2/P1S1.X/Osc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1794776729" 
	@${RM} ${OBJECTDIR}/_ext/1794776729/Osc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1794776729/Osc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1794776729/Osc.p1 "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/Osc.c" 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1794776729/Osc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1794776729/usartP.p1: C:/Users/Carlo/OneDrive/Documentos/Quinto\ Semestre/Digital2/P1S1.X/usartP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1794776729" 
	@${RM} ${OBJECTDIR}/_ext/1794776729/usartP.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1794776729/usartP.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1794776729/usartP.p1 "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/usartP.c" 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1794776729/usartP.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1794776729/main.p1: C:/Users/Carlo/OneDrive/Documentos/Quinto\ Semestre/Digital2/P1S1.X/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1794776729" 
	@${RM} ${OBJECTDIR}/_ext/1794776729/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1794776729/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1794776729/main.p1 "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/main.c" 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1794776729/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1794776729/SPI.p1: C:/Users/Carlo/OneDrive/Documentos/Quinto\ Semestre/Digital2/P1S1.X/SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1794776729" 
	@${RM} ${OBJECTDIR}/_ext/1794776729/SPI.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1794776729/SPI.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/_ext/1794776729/SPI.p1 "C:/Users/Carlo/OneDrive/Documentos/Quinto Semestre/Digital2/P1S1.X/SPI.c" 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1794776729/SPI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/P1S1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/P1S1.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -std=c99 -gdwarf-3 -mstack=compiled:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/P1S1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/P1S1.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/P1S1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/P1S1.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/P1S1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif