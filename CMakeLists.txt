cmake_minimum_required(VERSION 3.7)
project(C___Programming_Language)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES   main.cpp  "Chapter3/3.3-Copy&&Move.cpp" "Chapter2/2.4-Modularization.h"
        "Chapter2/2.3-User-DefinedType.h" "Chapter2/2.2-FoudmentalConcept.h"
        "Chapter3/3.2-Class.cpp" "Chapter3/3.2-Class.h" "Chapter3/3.4-Template.h"
        Chapter4/4.1-StandardHeadFile.h Chapter4/4.2-String.h Chapter4/4.3-IOStream.h
        Chapter4/4.4-Container.h Chapter4/4.5-Algorthm.h Chapter5/5.4-SmallTool.h
        Chapter5/5.6-MathComputing.h Chapter7/7.1-Pointer.h Chapter16/16.2-IntroductionOfClass.h
        Chapter16/16.3-ConcreteClass.h Chapter17/17.2-Constructor.h test.cpp Chapter17/17.3-InitializaOfObject.h Chapter17/17.4-InitializationOfMemberAndBaseClass.h Chapter17/17.5-copyAndMove.h)
add_executable(C___Programming_Language ${SOURCE_FILES} )