# Vulkan PlayGround
A PlayGround to test Vulkan error.

Current testing code is mostly from

[https://github.com/Overv/VulkanTutorial/blob/main/code/15_hello_triangle.cpp#L131](https://github.com/Overv/VulkanTutorial/blob/main/code/15_hello_triangle.cpp#L131)

[https://vkguide.dev/docs/extra-chapter/implementing_imgui/](https://vkguide.dev/docs/extra-chapter/implementing_imgui/)

## Usage

I haven't write file system, so reading file from a specific relative folder is a problem.

If you debug from VS project, you need to copy `shaders` folder to the root dir of sln file. 

If you run my build bat, sln file will locate in `./build` and you need to copy `shaders` folder to it.

If you run exe file, you need to copy `shaders` folder to the root dir of exe file. 

If you run my build bat, sln file will locate in `./build/Debug` and you need to copy `shaders` folder to it.
