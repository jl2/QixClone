#############################################################################
# Makefile for building: QixQt.app/Contents/MacOS/QixQt
# Generated by qmake (2.01a) (Qt 4.7.0) on: Sat Nov 20 15:35:12 2010
# Project:  QixQt.pro
# Template: app
# Command: /usr/bin/qmake -o QixQt.xcodeproj/project.pbxproj QixQt.pro
#############################################################################

MOC       = /Developer/Tools/Qt/moc
UIC       = /Developer/Tools/Qt/uic
LEX       = flex
LEXFLAGS  = 
YACC      = yacc
YACCFLAGS = -d
DEFINES       = -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
INCPATH       = -I/usr/local/Qt4.7/mkspecs/macx-xcode -I. -I/Library/Frameworks/QtCore.framework/Versions/4/Headers -I/usr/include/QtCore -I/Library/Frameworks/QtGui.framework/Versions/4/Headers -I/usr/include/QtGui -I/Library/Frameworks/QtOpenGL.framework/Versions/4/Headers -I/usr/include/QtOpenGL -I/usr/include -I. -I/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers -I/System/Library/Frameworks/AGL.framework/Headers -I. -I/usr/local/include -I/System/Library/Frameworks/CarbonCore.framework/Headers -F/Library/Frameworks
DEL_FILE  = rm -f
MOVE      = mv -f

IMAGES = 
PARSERS =
preprocess: $(PARSERS) compilers
clean preprocess_clean: parser_clean compiler_clean

parser_clean:
check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compilers: ./moc_qixwidget.cpp ./moc_qixwindow.cpp ./qrc_qix.cpp
compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_qixwidget.cpp moc_qixwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_qixwidget.cpp moc_qixwindow.cpp
moc_qixwidget.cpp: qixwidget.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ qixwidget.h -o moc_qixwidget.cpp

moc_qixwindow.cpp: qixwindow.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ qixwindow.h -o moc_qixwindow.cpp

compiler_rcc_make_all: qrc_qix.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_qix.cpp
qrc_qix.cpp: qix.qrc
	/Developer/Tools/Qt/rcc -name qix qix.qrc -o qrc_qix.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean 

