##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=UOCOrganization
ConfigurationName      :=Debug
WorkspacePath          :="/home/uoc/Documents/codelite/workspaces/UOCCongress2019 PR2"
ProjectPath            :="/home/uoc/Documents/codelite/workspaces/UOCCongress2019 PR2/UOCOrganization"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=uoc
Date                   :=22/04/19
CodeLitePath           :=/home/uoc/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../lib/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="UOCOrganization.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_organization.c$(ObjectSuffix) $(IntermediateDirectory)/src_congress.c$(ObjectSuffix) $(IntermediateDirectory)/src_presentation.c$(ObjectSuffix) $(IntermediateDirectory)/src_guest.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "/home/uoc/Documents/codelite/workspaces/UOCCongress2019 PR2/.build-debug"
	@echo rebuilt > "/home/uoc/Documents/codelite/workspaces/UOCCongress2019 PR2/.build-debug/UOCOrganization"

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


./Debug:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_organization.c$(ObjectSuffix): src/organization.c $(IntermediateDirectory)/src_organization.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Documents/codelite/workspaces/UOCCongress2019 PR2/UOCOrganization/src/organization.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_organization.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_organization.c$(DependSuffix): src/organization.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_organization.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_organization.c$(DependSuffix) -MM src/organization.c

$(IntermediateDirectory)/src_organization.c$(PreprocessSuffix): src/organization.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_organization.c$(PreprocessSuffix) src/organization.c

$(IntermediateDirectory)/src_congress.c$(ObjectSuffix): src/congress.c $(IntermediateDirectory)/src_congress.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Documents/codelite/workspaces/UOCCongress2019 PR2/UOCOrganization/src/congress.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_congress.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_congress.c$(DependSuffix): src/congress.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_congress.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_congress.c$(DependSuffix) -MM src/congress.c

$(IntermediateDirectory)/src_congress.c$(PreprocessSuffix): src/congress.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_congress.c$(PreprocessSuffix) src/congress.c

$(IntermediateDirectory)/src_presentation.c$(ObjectSuffix): src/presentation.c $(IntermediateDirectory)/src_presentation.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Documents/codelite/workspaces/UOCCongress2019 PR2/UOCOrganization/src/presentation.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_presentation.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_presentation.c$(DependSuffix): src/presentation.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_presentation.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_presentation.c$(DependSuffix) -MM src/presentation.c

$(IntermediateDirectory)/src_presentation.c$(PreprocessSuffix): src/presentation.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_presentation.c$(PreprocessSuffix) src/presentation.c

$(IntermediateDirectory)/src_guest.c$(ObjectSuffix): src/guest.c $(IntermediateDirectory)/src_guest.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Documents/codelite/workspaces/UOCCongress2019 PR2/UOCOrganization/src/guest.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_guest.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_guest.c$(DependSuffix): src/guest.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_guest.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_guest.c$(DependSuffix) -MM src/guest.c

$(IntermediateDirectory)/src_guest.c$(PreprocessSuffix): src/guest.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_guest.c$(PreprocessSuffix) src/guest.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


