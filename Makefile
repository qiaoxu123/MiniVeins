#
# OMNeT++/OMNEST Makefile for Test3
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out -I.
#

# Name of target to be created (-o option)
TARGET_DIR = .
TARGET_NAME = Test3$(D)
TARGET = $(TARGET_NAME)$(EXE_SUFFIX)
TARGET_IMPLIB = $(TARGET_NAME)$(IMPLIB_SUFFIX)
TARGET_IMPDEF = $(TARGET_NAME)$(IMPDEF_SUFFIX)
TARGET_FILES = $(TARGET_DIR)/$(TARGET)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(QTENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(QTENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = -I.

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc, .msg and .sm files
OBJS = \
    $O/src/base/communicationUnit/BaseCommunicationUnit.o \
    $O/src/base/communicationUnit/CarCommunicationUnit.o \
    $O/src/base/communicationUnit/CloudCommunicationUnit.o \
    $O/src/base/communicationUnit/RSUCommunicationUnit.o \
    $O/src/base/connectionManager/BaseConnectionManager.o \
    $O/src/base/connectionManager/ChannelAccess.o \
    $O/src/base/connectionManager/ConnectionManager.o \
    $O/src/base/connectionManager/NicEntryDebug.o \
    $O/src/base/connectionManager/NicEntryDirect.o \
    $O/src/base/modules/BaseBattery.o \
    $O/src/base/modules/BaseLayer.o \
    $O/src/base/modules/BaseMobility.o \
    $O/src/base/modules/BaseModule.o \
    $O/src/base/modules/BaseWorldUtility.o \
    $O/src/base/modules/BatteryAccess.o \
    $O/src/base/toolbox/Signal.o \
    $O/src/base/toolbox/Spectrum.o \
    $O/src/base/utils/Coord.o \
    $O/src/base/utils/Heading.o \
    $O/src/base/utils/NedFunctions.o \
    $O/src/base/utils/SimpleAddress.o \
    $O/src/modules/mobility/LinearMobility.o \
    $O/src/modules/mobility/traci/TraCIBuffer.o \
    $O/src/modules/mobility/traci/TraCIColor.o \
    $O/src/modules/mobility/traci/TraCICommandInterface.o \
    $O/src/modules/mobility/traci/TraCIConnection.o \
    $O/src/modules/mobility/traci/TraCICoordinateTransformation.o \
    $O/src/modules/mobility/traci/TraCILauncher.o \
    $O/src/modules/mobility/traci/TraCIMobility.o \
    $O/src/modules/mobility/traci/TraCIRegionOfInterest.o \
    $O/src/modules/mobility/traci/TraCIScenarioManager.o \
    $O/src/modules/mobility/traci/TraCIScenarioManagerForker.o \
    $O/src/modules/mobility/traci/TraCIScenarioManagerLaunchd.o \
    $O/src/modules/mobility/traci/TraCIScreenRecorder.o \
    $O/src/modules/mobility/traci/TraCIVehicleInserter.o \
    $O/src/modules/utility/HasLogProxy.o \
    $O/src/visualizer/roads/RoadsCanvasVisualizer.o \
    $O/src/common_m.o \
    $O/src/base/messages/BorderMsg_m.o \
    $O/src/base/toolbox/Signal_m.o \
    $O/src/base/utils/Coord_m.o \
    $O/src/messages/CarPosUpdateFrame_m.o \
    $O/src/messages/CloudFeedbackFrame_m.o \
    $O/src/messages/QueueStatusFrame_m.o \
    $O/src/messages/RSUTaskSignalFrame_m.o \
    $O/src/messages/TaskFrame_m.o

# Message files
MSGFILES = \
    src/common.msg \
    src/base/messages/BorderMsg.msg \
    src/base/toolbox/Signal.msg \
    src/base/utils/Coord.msg \
    src/messages/CarPosUpdateFrame.msg \
    src/messages/CloudFeedbackFrame.msg \
    src/messages/QueueStatusFrame.msg \
    src/messages/RSUTaskSignalFrame.msg \
    src/messages/TaskFrame.msg

# SM files
SMFILES =

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
CONFIGFILE = $(shell opp_configfilepath)
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIBS = $(OPPMAIN_LIB) $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS) $(IMPORT_DEFINES)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)
SMCOPTS =

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE (if COPTS has changed since last build)
# and make the object files depend on it
COPTS_FILE = $O/.last-copts
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
  $(shell $(MKPATH) "$O")
  $(file >$(COPTS_FILE),$(COPTS))
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
-include makefrag

#------------------------------------------------------------------------------

# Main target
all: $(TARGET_FILES)

$(TARGET_DIR)/% :: $O/%
	@mkdir -p $(TARGET_DIR)
	$(Q)$(LN) $< $@
ifeq ($(TOOLCHAIN_NAME),clang-msabi)
	-$(Q)-$(LN) $(<:%.dll=%.lib) $(@:%.dll=%.lib) 2>/dev/null

$O/$(TARGET_NAME).pdb: $O/$(TARGET)
endif

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile $(CONFIGFILE)
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET) $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders smheaders

# disabling all implicit rules
.SUFFIXES :

$O/%.o: %.cc $(COPTS_FILE) | msgheaders smheaders
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc -MD -MP -MF $O/$(basename $<)_m.h.d $(MSGCOPTS) $?

%_sm.cc %_sm.h: %.sm
	$(qecho) SMC: $<
	$(Q)$(SMC) -c++ -suffix cc $(SMCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

smheaders: $(SMFILES:.sm=_sm.h)

clean:
	$(qecho) Cleaning $(TARGET)
	$(Q)-rm -rf $O
	$(Q)-rm -f $(TARGET_FILES)
	$(Q)-rm -f $(call opp_rwildcard, . , *_m.cc *_m.h *_sm.cc *_sm.h)

cleanall:
	$(Q)$(CLEANALL_COMMAND)
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

help:
	@echo "$$HELP_SYNOPSYS"
	@echo "$$HELP_TARGETS"
	@echo "$$HELP_VARIABLES"
	@echo "$$HELP_EXAMPLES"

# include all dependencies
-include $(OBJS:%=%.d) $(MSGFILES:%.msg=$O/%_m.h.d)
