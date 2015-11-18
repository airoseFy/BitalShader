LOCAL_PATH := $(call my-dir)

NE_ROOT := $(LOCAL_PATH)/../../../..
NE_SRC_ROOT := $(NE_ROOT)/src
AN_PLATFORM_ROOT := $(NE_SRC_ROOT)/platform/android

include $(CLEAR_VARS)

LOCAL_MODULE	:= shader

LOCAL_C_INCLUDES := \
	$(NE_SRC_ROOT) \
	$(NE_SRC_ROOT)/common \
	$(NE_SRC_ROOT)/core \
	$(NE_SRC_ROOT)/platform \
	$(AN_PLATFORM_ROOT)
	
LOCAL_SRC_FILES  := \
	$(NE_SRC_ROOT)/core/NeShader.cpp \
	$(NE_SRC_ROOT)/core/NeProgram.cpp \
	$(NE_SRC_ROOT)/core/NeSurface.cpp \
	$(AN_PLATFORM_ROOT)/AN_Surface.cpp \
	MyRenderer.cpp \
	ShaderDemo.cpp
	
LOCAL_LDLIBS     += -llog
LOCAL_LDLIBS     += -landroid -lEGL -lGLESv2

LOCAL_CPPFLAGS 	+= -std=c++11
LOCAL_CLANG = true

include $(BUILD_SHARED_LIBRARY)