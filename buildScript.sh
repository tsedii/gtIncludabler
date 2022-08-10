#!/bin/bash

# To save build results put "NotDelBuildResults" as commandline parameter of this script !!!

#MultiLineBashCommenter() {

[ -z $BASH ] || shopt -s expand_aliases
alias BEGINCOMMENT="if [ ]; then"
alias ENDCOMMENT="fi"

#BEGINCOMMENT
#ENDCOMMENT

#}

builtTarget="converter"
builtTestTarget="converterTests"

DeleteTmpBildFolders() {

if [ -d build ]; then
      rm -rf build
fi
if [ -d builds ]; then
      rm -rf builds
fi

}

DeleteTargetFiles() {

if [ -f $builtTarget ]; then
      rm -f $builtTarget
fi

if [ -f $builtTestTarget ]; then
      rm -f $builtTestTarget
fi

}

PreviousCommandExitCodeCheck() {

if [ $? -ne 0 ]; then
  echo -e "PreviousCommandExitCodeCheck: Failure execute previous command\n" >&2
  exit 1
fi

}

CheckNotDelBuildCommandLineArgument() {

if [[ "$1" == "NotDelBuildResults" ]]; then
  echo -e "$1: Save all build results\n";
  exit 0
fi

}

SaveTargetFiles() {

if [ -f build/$builtTarget ]; then
      cp build/$builtTarget ./
fi

if [ -f build/Src/Tests/$builtTestTarget ]; then
      cp build/Src/Tests/$builtTestTarget ./
fi

}

DeleteTmpBildFolders
DeleteTargetFiles


mkdir build
#cmake -S . -B build
cmake -S . -B build -D CMAKE_BUILD_TYPE=Debug
#cmake -S . -B build -D CMAKE_BUILD_TYPE=Release
cd build
make

PreviousCommandExitCodeCheck


cd ..

SaveTargetFiles

CheckNotDelBuildCommandLineArgument $1

DeleteTmpBildFolders

