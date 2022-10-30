##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=PracticaC1
ConfigurationName      :=Debug
WorkspacePath          :=/home/uoc/Documents/codelite/workspaces/CoworkingCenter.Ej3
ProjectPath            :=/home/uoc/Documents/codelite/workspaces/CoworkingCenter.Ej3/PracticaC1
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=uoc
Date                   :=29/10/22
CodeLitePath           :=/home/uoc/.codelite
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="PracticaC1.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
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
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/coworker.c$(ObjectSuffix) $(IntermediateDirectory)/coworkingcenter.c$(ObjectSuffix) $(IntermediateDirectory)/api.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/menu.c$(ObjectSuffix) $(IntermediateDirectory)/test.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/coworker.c$(ObjectSuffix): coworker.c $(IntermediateDirectory)/coworker.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Documents/codelite/workspaces/CoworkingCenter.Ej3/PracticaC1/coworker.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/coworker.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/coworker.c$(DependSuffix): coworker.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/coworker.c$(ObjectSuffix) -MF$(IntermediateDirectory)/coworker.c$(DependSuffix) -MM coworker.c

$(IntermediateDirectory)/coworker.c$(PreprocessSuffix): coworker.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/coworker.c$(PreprocessSuffix) coworker.c

$(IntermediateDirectory)/coworkingcenter.c$(ObjectSuffix): coworkingcenter.c $(IntermediateDirectory)/coworkingcenter.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Documents/codelite/workspaces/CoworkingCenter.Ej3/PracticaC1/coworkingcenter.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/coworkingcenter.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/coworkingcenter.c$(DependSuffix): coworkingcenter.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/coworkingcenter.c$(ObjectSuffix) -MF$(IntermediateDirectory)/coworkingcenter.c$(DependSuffix) -MM coworkingcenter.c

$(IntermediateDirectory)/coworkingcenter.c$(PreprocessSuffix): coworkingcenter.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/coworkingcenter.c$(PreprocessSuffix) coworkingcenter.c

$(IntermediateDirectory)/api.c$(ObjectSuffix): api.c $(IntermediateDirectory)/api.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Documents/codelite/workspaces/CoworkingCenter.Ej3/PracticaC1/api.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/api.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/api.c$(DependSuffix): api.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/api.c$(ObjectSuffix) -MF$(IntermediateDirectory)/api.c$(DependSuffix) -MM api.c

$(IntermediateDirectory)/api.c$(PreprocessSuffix): api.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/api.c$(PreprocessSuffix) api.c

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Documents/codelite/workspaces/CoworkingCenter.Ej3/PracticaC1/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/menu.c$(ObjectSuffix): menu.c $(IntermediateDirectory)/menu.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Documents/codelite/workspaces/CoworkingCenter.Ej3/PracticaC1/menu.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/menu.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/menu.c$(DependSuffix): menu.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/menu.c$(ObjectSuffix) -MF$(IntermediateDirectory)/menu.c$(DependSuffix) -MM menu.c

$(IntermediateDirectory)/menu.c$(PreprocessSuffix): menu.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/menu.c$(PreprocessSuffix) menu.c

$(IntermediateDirectory)/test.c$(ObjectSuffix): test.c $(IntermediateDirectory)/test.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Documents/codelite/workspaces/CoworkingCenter.Ej3/PracticaC1/test.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test.c$(DependSuffix): test.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test.c$(DependSuffix) -MM test.c

$(IntermediateDirectory)/test.c$(PreprocessSuffix): test.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test.c$(PreprocessSuffix) test.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


