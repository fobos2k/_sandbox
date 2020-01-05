LOCAL_PATH      := $(shell pwd)
OBJS_PATH       := $(LOCAL_PATH)/obj
SRCS_PATH       := $(LOCAL_PATH)/src
INCLUDES_PATH   := $(LOCAL_PATH)/include
TESTS_PATH      := $(LOCAL_PATH)/test
BUILD_PATH      := $(LOCAL_PATH)/build

LOCAL_TARGET    := app4isolator
LOCAL_TEST      := test_$(LOCAL_TARGET)
LOCAL_MAIN      := $(SRCS_PATH)/main.cpp

LOCAL_SRCS      := $(wildcard $(SRCS_PATH)/*.cpp)
LOCAL_SRCS      := $(filter-out $(LOCAL_MAIN), $(LOCAL_SRCS))
LOCAL_TEST_SRCS := $(wildcard $(TESTS_PATH)/*.cpp)
LOCAL_TEST_NAMES := $(patsubst $(TESTS_PATH)/%.cpp, %, $(LOCAL_TEST_SRCS))
LOCAL_OBJS      := $(patsubst $(SRCS_PATH)/%.cpp, $(OBJS_PATH)/%.o, $(LOCAL_SRCS))

INCLUDES        := -I$(INCLUDES_PATH)
INCLUDES        += -I$(BOOST_PATH)
INCLUDES        += -I$(ISOLATOR_INCLUDE_PATH)

CC              := g++
LOCAL_CFLAGS    := -std=c++11 -g3 -O0 -fdata-sections -ffunction-sections

LOCAL_LDFLAGS   :=

LOCAL_TESTS_LDFLAGS := -Wall -no-pie -ldl -lpthread -Wl,--gc-sections
ISOLATOR_LDFLAGS := -L$(ISOLATOR_LIB_PATH) -l:libisolator.so
BOOST_LDFLAGS    := -L$(BOOST_LIB_PATH) -l:libboost_unit_test_framework.so
LOCAL_TESTS_LDFLAGS += $(ISOLATOR_LDFLAGS) $(BOOST_LDFLAGS)

ifndef BOOST_PATH
CHECK_ENV       := $(CHECK_ENV) BOOST_PATH
endif
ifndef BOOST_LIB_PATH
CHECK_ENV       := $(CHECK_ENV) BOOST_LIB_PATH
endif
ifndef ISOLATOR_INCLUDE_PATH
CHECK_ENV       := $(CHECK_ENV) ISOLATOR_INCLUDE_PATH
endif
ifndef ISOLATOR_LIB_PATH
CHECK_ENV       := $(CHECK_ENV) ISOLATOR_LIB_PATH
endif

.PHONY: prepare clean check_env tests all

all: prepare check_env $(LOCAL_TARGET)
	$(info Build app is done!)

tests: prepare check_env $(LOCAL_TEST)
	$(info Build tests is done!)

prepare:
	@mkdir -p $(OBJS_PATH)
	@mkdir -p $(BUILD_PATH)

check_env:
ifdef CHECK_ENV
	$(error Environment variables is not defined:$(CHECK_ENV))
endif

clean:
	@rm -rf $(OBJS_PATH)
	@rm -rf $(BUILD_PATH)
	$(info Cleaned!)


.PHONY: $(LOCAL_TARGET) $(LOCAL_TEST_APP)

$(LOCAL_TARGET): $(LOCAL_OBJS)
	$(info ... Local Target ...)
	$(CC) -o $(BUILD_PATH)/$@ $^ $(LOCAL_MAIN) $(INCLUDES) $(LOCAL_LDFLAGS)

$(LOCAL_TEST):
	$(MAKE) $(LOCAL_OBJS)
	$(info ... $(LOCAL_TEST_NAMES))
	$(foreach test, $(LOCAL_TEST_NAMES), $(info ... $(test)))
	$(foreach test, $(LOCAL_TEST_NAMES), $(CC) -o $(BUILD_PATH)/$(test) $(TESTS_PATH)/$(test).cpp $(LOCAL_OBJS) $(INCLUDES) $(LOCAL_TESTS_LDFLAGS);)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.cpp
	$(CC) -c -o $@ $< $(LOCAL_CFLAGS) $(INCLUDES)

-include $(OBJ_FILES:.o=.d)
