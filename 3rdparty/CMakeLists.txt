# add_subdirectory would add 3rdparty source code into cmake build tree

if(NOT TARGET glfw)
    option(GLFW_BUILD_EXAMPLES "" OFF)
    option(GLFW_BUILD_TESTS "" OFF)
    option(GLFW_BUILD_DOCS "" OFF)
    option(GLFW_INSTALL "" OFF)
    add_subdirectory(glfw)
endif()

# need have installed Vulkan SDK
find_package(Vulkan REQUIRED)

if(NOT TARGET imgui)
    include(imgui.cmake)
endif()
