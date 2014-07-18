##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=IndieBoy
ConfigurationName      :=Debug
WorkspacePath          := "H:\Dev\IndieBoy\IndieBoy"
ProjectPath            := "H:\Dev\IndieBoy\IndieBoy"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Daniel
Date                   :=07/18/14
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:\MinGW-4.7\bin\g++.exe 
SharedObjectLinkerName :=C:\MinGW-4.7\bin\g++.exe -shared -fPIC
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)SFML_STATIC 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="IndieBoy.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:\MinGW-4.7\bin\windres.exe 
LinkOptions            :=  -gcc-eh -static-libgcc -static-libstdc++
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)C:/Dev/SFML-2.0/include $(IncludeSwitch)C:/Dev/myinclude 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)glu32 $(LibrarySwitch)sfml-graphics-s $(LibrarySwitch)sfml-audio-s $(LibrarySwitch)sfml-window-s $(LibrarySwitch)sfml-system-s $(LibrarySwitch)MIOLIB 
ArLibs                 :=  "glu32" "sfml-graphics-s" "sfml-audio-s" "sfml-window-s" "sfml-system-s" "MIOLIB" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:/Dev/SFML-2.0/lib $(LibraryPathSwitch)C:/Dev/myinclude 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:\MinGW-4.7\bin\ar.exe rcu
CXX      := C:\MinGW-4.7\bin\g++.exe
CC       := C:\MinGW-4.7\bin\gcc.exe 
CXXFLAGS :=  -g -O0 -Wall -fpermissive -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall -fpermissive $(Preprocessors)
ASFLAGS  := 
AS       := C:\MinGW-4.7\bin\as.exe 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/config_file.cpp$(ObjectSuffix) $(IntermediateDirectory)/game_object.cpp$(ObjectSuffix) $(IntermediateDirectory)/game_window.cpp$(ObjectSuffix) $(IntermediateDirectory)/InputHandler.cpp$(ObjectSuffix) $(IntermediateDirectory)/Log.cpp$(ObjectSuffix) $(IntermediateDirectory)/Assets.cpp$(ObjectSuffix) $(IntermediateDirectory)/Sprite.cpp$(ObjectSuffix) $(IntermediateDirectory)/ObjectRegistry.cpp$(ObjectSuffix) $(IntermediateDirectory)/TestObject.cpp$(ObjectSuffix) \
	



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "H:/Dev/IndieBoy/IndieBoy/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/config_file.cpp$(ObjectSuffix): config_file.cpp $(IntermediateDirectory)/config_file.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "H:/Dev/IndieBoy/IndieBoy/config_file.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/config_file.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/config_file.cpp$(DependSuffix): config_file.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/config_file.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/config_file.cpp$(DependSuffix) -MM "config_file.cpp"

$(IntermediateDirectory)/config_file.cpp$(PreprocessSuffix): config_file.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/config_file.cpp$(PreprocessSuffix) "config_file.cpp"

$(IntermediateDirectory)/game_object.cpp$(ObjectSuffix): game_object.cpp $(IntermediateDirectory)/game_object.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "H:/Dev/IndieBoy/IndieBoy/game_object.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/game_object.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/game_object.cpp$(DependSuffix): game_object.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/game_object.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/game_object.cpp$(DependSuffix) -MM "game_object.cpp"

$(IntermediateDirectory)/game_object.cpp$(PreprocessSuffix): game_object.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/game_object.cpp$(PreprocessSuffix) "game_object.cpp"

$(IntermediateDirectory)/game_window.cpp$(ObjectSuffix): game_window.cpp $(IntermediateDirectory)/game_window.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "H:/Dev/IndieBoy/IndieBoy/game_window.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/game_window.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/game_window.cpp$(DependSuffix): game_window.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/game_window.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/game_window.cpp$(DependSuffix) -MM "game_window.cpp"

$(IntermediateDirectory)/game_window.cpp$(PreprocessSuffix): game_window.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/game_window.cpp$(PreprocessSuffix) "game_window.cpp"

$(IntermediateDirectory)/InputHandler.cpp$(ObjectSuffix): InputHandler.cpp $(IntermediateDirectory)/InputHandler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "H:/Dev/IndieBoy/IndieBoy/InputHandler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/InputHandler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/InputHandler.cpp$(DependSuffix): InputHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/InputHandler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/InputHandler.cpp$(DependSuffix) -MM "InputHandler.cpp"

$(IntermediateDirectory)/InputHandler.cpp$(PreprocessSuffix): InputHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/InputHandler.cpp$(PreprocessSuffix) "InputHandler.cpp"

$(IntermediateDirectory)/Log.cpp$(ObjectSuffix): Log.cpp $(IntermediateDirectory)/Log.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "H:/Dev/IndieBoy/IndieBoy/Log.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Log.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Log.cpp$(DependSuffix): Log.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Log.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Log.cpp$(DependSuffix) -MM "Log.cpp"

$(IntermediateDirectory)/Log.cpp$(PreprocessSuffix): Log.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Log.cpp$(PreprocessSuffix) "Log.cpp"

$(IntermediateDirectory)/Assets.cpp$(ObjectSuffix): Assets.cpp $(IntermediateDirectory)/Assets.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "H:/Dev/IndieBoy/IndieBoy/Assets.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Assets.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Assets.cpp$(DependSuffix): Assets.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Assets.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Assets.cpp$(DependSuffix) -MM "Assets.cpp"

$(IntermediateDirectory)/Assets.cpp$(PreprocessSuffix): Assets.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Assets.cpp$(PreprocessSuffix) "Assets.cpp"

$(IntermediateDirectory)/Sprite.cpp$(ObjectSuffix): Sprite.cpp $(IntermediateDirectory)/Sprite.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "H:/Dev/IndieBoy/IndieBoy/Sprite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Sprite.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Sprite.cpp$(DependSuffix): Sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Sprite.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Sprite.cpp$(DependSuffix) -MM "Sprite.cpp"

$(IntermediateDirectory)/Sprite.cpp$(PreprocessSuffix): Sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Sprite.cpp$(PreprocessSuffix) "Sprite.cpp"

$(IntermediateDirectory)/ObjectRegistry.cpp$(ObjectSuffix): ObjectRegistry.cpp $(IntermediateDirectory)/ObjectRegistry.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "H:/Dev/IndieBoy/IndieBoy/ObjectRegistry.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ObjectRegistry.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ObjectRegistry.cpp$(DependSuffix): ObjectRegistry.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ObjectRegistry.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ObjectRegistry.cpp$(DependSuffix) -MM "ObjectRegistry.cpp"

$(IntermediateDirectory)/ObjectRegistry.cpp$(PreprocessSuffix): ObjectRegistry.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ObjectRegistry.cpp$(PreprocessSuffix) "ObjectRegistry.cpp"

$(IntermediateDirectory)/TestObject.cpp$(ObjectSuffix): TestObject.cpp $(IntermediateDirectory)/TestObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "H:/Dev/IndieBoy/IndieBoy/TestObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TestObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TestObject.cpp$(DependSuffix): TestObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TestObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TestObject.cpp$(DependSuffix) -MM "TestObject.cpp"

$(IntermediateDirectory)/TestObject.cpp$(PreprocessSuffix): TestObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TestObject.cpp$(PreprocessSuffix) "TestObject.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/config_file.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/config_file.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/config_file.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/game_object.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/game_object.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/game_object.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/game_window.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/game_window.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/game_window.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/InputHandler.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/InputHandler.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/InputHandler.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Log.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Log.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Log.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Assets.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Assets.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Assets.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Sprite.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Sprite.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Sprite.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ObjectRegistry.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ObjectRegistry.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ObjectRegistry.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/TestObject.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/TestObject.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/TestObject.cpp$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) ".build-debug/IndieBoy"


