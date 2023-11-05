cmake_minimum_required(VERSION 3.24)
project(VulkanPlayGround CXX)

# Stop in source builds
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# Add the cmake folder so the FindXXX module is found
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

set(PLAYGROUND_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_ROOT_DIR ${PLAYGROUND_ROOT_DIR}/src)
set(3RD_PARTY_ROOT_DIR ${PLAYGROUND_ROOT_DIR}/3rdparty)

add_subdirectory(${3RD_PARTY_ROOT_DIR})

add_executable(ERROR1 ${SRC_ROOT_DIR}/error_of_multiview_render_pass.cpp)

set_target_properties(ERROR1 PROPERTIES CXX_STANDARD 17)
set_target_properties(ERROR1 PROPERTIES FOLDER "ERROR1")

target_compile_definitions(ERROR1
    PRIVATE
    VK_USE_PLATFORM_WIN32_KHR # TODO: Config vulkan platform preprocesser according to cmake build platform
    NOMINMAX # for std::numeric_limits<double>::min() and max()
    )

# being a cross-platform target, we enforce standards conformance on MSVC
target_compile_options(ERROR1 PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->")
target_compile_options(ERROR1 PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/WX->")

target_include_directories(ERROR1 PUBLIC ${SRC_ROOT_DIR})

target_link_libraries(ERROR1 PUBLIC glfw)
target_include_directories(ERROR1 PUBLIC ${3RD_PARTY_ROOT_DIR}/glfw/include)
target_compile_definitions(ERROR1
    PUBLIC
    GLFW_INCLUDE_VULKAN 
    GLFW_EXPOSE_NATIVE_WIN32)

if(Vulkan_FOUND)
    # for vulkan hpp
    target_include_directories(ERROR1 PUBLIC ${Vulkan_INCLUDE_DIRS})
    # don't link to vulkan static lib
endif()

target_link_libraries(ERROR1 PUBLIC imgui)
target_include_directories(ERROR1 PUBLIC ${3RD_PARTY_ROOT_DIR}/imgui)