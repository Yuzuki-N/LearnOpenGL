#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//回调函数
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// 创建窗口
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;

		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// glad管理opengl的函数指针，这里在使用opengl函数之前先初始化glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	//前两个参数设定左下角坐标， 后两个指定视口宽高
	glViewport(0, 0, 800, 600);
	//调用回调函数动态调整视口大小
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(window))
	{
		//监控是否要退出
		processInput(window);

		//state - setting function
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		//state - using function
		glClear(GL_COLOR_BUFFER_BIT);

		//交换缓冲区
		glfwSwapBuffers(window);
		//处理事件
		glfwPollEvents();
	}

	//清理GLFW资源
	glfwTerminate();
	return 0;
}

//调整视口和窗口大小相同用的回调函数
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

//处理输入
void processInput(GLFWwindow* window)
{
	//如果esc键被按下了关闭窗口
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}