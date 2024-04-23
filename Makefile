CXX = g++
SRCDIR = src
BUILDDIR = build
subdirs = $(wildcard include/**)
CXXFLAGS = -std=c++20 \
				-Wall \
				-Wextra \
				-I"C:/Program Files/boost/boost_1_82_0" \
				-I"C:/Users/ander/source/repos/MadelineCAD" \
				-I"C:/VulkanSDK/1.3.280.0/Include"


CXXFLAGS += $(foreach dir,$(subdirs),-I$(dir))


LDFLAGS = \
				-L"C:/Program Files/boost/boost_1_82_0/stage/lib" \
				-L"C:/VulkanSDK/1.3.280.0/Lib"


BOOST_LIBS = \
    -llibboost_atomic-vc143-mt-gd-x64-1_82 \
    -llibboost_chrono-vc143-mt-gd-x64-1_82 \
    -llibboost_container-vc143-mt-gd-x64-1_82 \
    -llibboost_context-vc143-mt-gd-x64-1_82 \
    -llibboost_contract-vc143-mt-gd-x64-1_82 \
    -llibboost_coroutine-vc143-mt-gd-x64-1_82 \
    -llibboost_date_time-vc143-mt-gd-x64-1_82 \
    -llibboost_exception-vc143-mt-gd-x64-1_82 \
    -llibboost_fiber-vc143-mt-gd-x64-1_82 \
    -llibboost_filesystem-vc143-mt-gd-x64-1_82 \
    -llibboost_graph-vc143-mt-gd-x64-1_82 \
    -llibboost_iostreams-vc143-mt-gd-x64-1_82 \
    -llibboost_json-vc143-mt-gd-x64-1_82 \
    -llibboost_locale-vc143-mt-gd-x64-1_82 \
    -llibboost_log_setup-vc143-mt-gd-x64-1_82 \
    -llibboost_log-vc143-mt-gd-x64-1_82 \
    -llibboost_math_c99f-vc143-mt-gd-x64-1_82 \
    -llibboost_math_c99l-vc143-mt-gd-x64-1_82 \
    -llibboost_math_c99-vc143-mt-gd-x64-1_82 \
    -llibboost_math_tr1f-vc143-mt-gd-x64-1_82 \
    -llibboost_math_tr1l-vc143-mt-gd-x64-1_82 \
    -llibboost_math_tr1-vc143-mt-gd-x64-1_82 \
    -llibboost_nowide-vc143-mt-gd-x64-1_82 \
    -llibboost_prg_exec_monitor-vc143-mt-gd-x64-1_82 \
    -llibboost_program_options-vc143-mt-gd-x64-1_82 \
    -llibboost_random-vc143-mt-gd-x64-1_82 \
    -llibboost_regex-vc143-mt-gd-x64-1_82 \
    -llibboost_serialization-vc143-mt-gd-x64-1_82 \
    -llibboost_stacktrace_noop-vc143-mt-gd-x64-1_82 \
    -llibboost_stacktrace_windbg_cached-vc143-mt-gd-x64-1_82 \
    -llibboost_stacktrace_windbg-vc143-mt-gd-x64-1_82 \
    -llibboost_system-vc143-mt-gd-x64-1_82 \
    -llibboost_test_exec_monitor-vc143-mt-gd-x64-1_82 \
    -llibboost_thread-vc143-mt-gd-x64-1_82 \
    -llibboost_timer-vc143-mt-gd-x64-1_82 \
    -llibboost_type_erasure-vc143-mt-gd-x64-1_82 \
    -llibboost_unit_test_framework-vc143-mt-gd-x64-1_82 \
    -llibboost_url-vc143-mt-gd-x64-1_82 \
    -llibboost_wave-vc143-mt-gd-x64-1_82 \
    -llibboost_wserialization-vc143-mt-gd-x64-1_82

VULKAN_LIBS = \
				-lvulkan-1

LIBS = $(BOOST_LIBS) $(VULKAN_LIBS)

SRCS := $(wildcard src/**/*.cpp)
OBJS = $(SRCS:.cpp=.o)
EXECUTABLE = MadelineCAD.exe

all: $(BUILDDIR)/$(EXECUTABLE)

$(BUILDDIR)/$(EXECUTABLE): $(OBJS)
				$(CXX) $(CXXFLAGS) $(LDFLAGS) $(foreach obj,$(OBJS), build/$(notdir $(obj))) -o $@ $(LIBS)

.cpp.o:
				$(CXX) $(CXXFLAGS) -c $< -o $(BUILDDIR)/$(notdir $@)

clean:
				rd /s /q build
				mkdir build