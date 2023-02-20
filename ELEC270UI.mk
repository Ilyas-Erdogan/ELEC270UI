##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ELEC270UI
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=/home/ilyas/Documents/Projects/ELEC270UI
ProjectPath            :=/home/ilyas/Documents/Projects/ELEC270UI/ELEC270UI
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Ilyas Erdogan
Date                   :=19/02/23
CodeLitePath           :=/home/ilyas/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=$(IntermediateDirectory)
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="ELEC270UI.txt"
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
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/discrete.cpp$(ObjectSuffix) $(IntermediateDirectory)/WeekOne.cpp$(ObjectSuffix) $(IntermediateDirectory)/Latex.cpp$(ObjectSuffix) $(IntermediateDirectory)/Week.cpp$(ObjectSuffix) 



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
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)


$(IntermediateDirectory)/.d:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/discrete.cpp$(ObjectSuffix): discrete.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/discrete.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/discrete.cpp$(DependSuffix) -MM discrete.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ilyas/Documents/Projects/ELEC270UI/ELEC270UI/discrete.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/discrete.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/discrete.cpp$(PreprocessSuffix): discrete.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/discrete.cpp$(PreprocessSuffix) discrete.cpp

$(IntermediateDirectory)/WeekOne.cpp$(ObjectSuffix): WeekOne.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/WeekOne.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/WeekOne.cpp$(DependSuffix) -MM WeekOne.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ilyas/Documents/Projects/ELEC270UI/ELEC270UI/WeekOne.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/WeekOne.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/WeekOne.cpp$(PreprocessSuffix): WeekOne.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/WeekOne.cpp$(PreprocessSuffix) WeekOne.cpp

$(IntermediateDirectory)/Latex.cpp$(ObjectSuffix): Latex.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Latex.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Latex.cpp$(DependSuffix) -MM Latex.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ilyas/Documents/Projects/ELEC270UI/ELEC270UI/Latex.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Latex.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Latex.cpp$(PreprocessSuffix): Latex.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Latex.cpp$(PreprocessSuffix) Latex.cpp

$(IntermediateDirectory)/Week.cpp$(ObjectSuffix): Week.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Week.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Week.cpp$(DependSuffix) -MM Week.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ilyas/Documents/Projects/ELEC270UI/ELEC270UI/Week.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Week.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Week.cpp$(PreprocessSuffix): Week.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Week.cpp$(PreprocessSuffix) Week.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


