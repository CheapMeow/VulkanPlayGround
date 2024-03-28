#include <vulkan/vulkan_raii.hpp>

#include <functional>
#include <queue>
#include <iostream>

class TestClass
{
    std::queue<std::function<void(vk::raii::CommandBuffer const&)>> m_pending_commands;
};

int main()
{
    TestClass testClassIns;
    
    do 
    {
        std::cout << '\n' << "Press a key to continue...";
    } while (std::cin.get() != '\n');

    return 0;
}