COCOS2DX_PATH = /home/igor/Development/cocos2d-x-2.1.4/cocos2dx
COCOS_PATH = /home/igor/Development/cocos2d-x-2.1.4

COCOS2D_DEBUG = 2

EXECUTABLE = RealSteel

INCLUDES =  -I../../ \
			-I../../Classes \
			-I../../Classes/Screens \
			-I../../Classes/Managers \
			-I../../Classes/Entities \
			-I../../Classes/Utils \
			-I$(COCOS2DX_PATH) \
			-I$(COCOS2DX_PATH)/platform/third_party/linux \
			-I$(COCOS2DX_PATH)/cocoa \
			-I$(COCOS2DX_PATH)/include \
			-I$(COCOS2DX_PATH)/platform \
			-I$(COCOS2DX_PATH)/platform/linux \
			-I$(COCOS2DX_PATH)/kazmath/include \
			-I$(COCOS_PATH)/extensions/ \
			-I$(COCOS_PATH)/external/ \
			-I$(COCOS_PATH)/CocosDenshion/include

SOURCES = ./main.cpp \
			../../../Classes/Options.cpp \
			../../../Classes/AppDelegate.cpp \
			../../../Classes/Utils/Utils.cpp \
			../../../Classes/Utils/Random.cpp \
			../../../Classes/Utils/Time.cpp \
			../../../Classes/Utils/Vector.cpp \
			../../../Classes/Utils/Touchable.cpp \
			../../../Classes/Entities/Entity.cpp \
			../../../Classes/Entities/TiledEntity.cpp \
			../../../Classes/Entities/AnimatedEntity.cpp \
			../../../Classes/Entities/Text.cpp \
			../../../Classes/Managers/EntityManager.cpp \
			../../../Classes/Managers/ScreenManager.cpp \
			../../../Classes/Screens/Screen.cpp \
			../../../Classes/Screens/Loader.cpp \

COCOS_ROOT = ../../../../..
include $(COCOS2DX_PATH)/proj.linux/cocos2dx.mk

SHAREDLIBS += -lcocos2d -lcocosdenshion
COCOS_LIBS = $(LIB_DIR)/libcocos2d.so \
			 $(LIB_DIR)/libcocosdenshion.so

$(TARGET): $(OBJECTS) $(STATICLIBS) $(COCOS_LIBS) $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_LINK)$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(SHAREDLIBS) $(STATICLIBS)

$(OBJ_DIR)/%.o: %.cpp $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_CXX)$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

$(OBJ_DIR)/%.o: ../%.cpp $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_CXX)$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@
