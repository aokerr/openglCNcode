#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "../shader_s.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    //Shader myshader1("./shaders/shader1.vs", "./shaders/shader1.fs");
    //Shader myshader2("./shaders/shader2.vs", "./shaders/shader2.fs");

    ////顶点输入
    //float vertices1[] = {
    //    // first triangle
    //    -0.9f, -0.5f, 0.0f,  // left 
    //    -0.0f, -0.5f, 0.0f,  // right
    //    -0.45f, 0.5f, 0.0f,  // top 
    //};
    //float vertices2[] = {
    //    // first triangle
    //     0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // left
    //     0.9f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // right
    //     0.45f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,   // top 
    //};

    //unsigned int VBO[2], VAO[2];
    //glGenVertexArrays(2, VAO);
    //glGenBuffers(2, VBO);
    ////1
    //glBindVertexArray(VAO[0]);
    //glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
    ////解析顶点数据
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    //glEnableVertexAttribArray(0);
    ////2
    //glBindVertexArray(VAO[1]);
    //glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
    ////位置属性
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    //glEnableVertexAttribArray(0);
    ////颜色属性
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    //glEnableVertexAttribArray(1);

    float tx = 0;
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ////激活对象
        ////glUseProgram(shaderProgram);
        //myshader1.use();

        ////更新uniform颜色
        //float timeValue = glfwGetTime();
        //float greenValue = sin(timeValue) / 2.0f + 0.5f;
        //float redValue = cos(timeValue) / 2.0f + 0.5f;
        //myshader1.set4F("ourColor", redValue, greenValue, 0.0f, 1.0f);


        //glBindVertexArray(VAO[0]);
        //glDrawArrays(GL_TRIANGLES, 0, 3);

        ////glUseProgram(shaderProgramY);
        //myshader2.use();
        //if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        //    tx += 0.1f;
        //else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        //    tx -= 0.1f;
        //myshader2.setFloat("tx", tx);
        //glBindVertexArray(VAO[1]);
        //glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //glDeleteVertexArrays(2, VAO);
    //glDeleteBuffers(2, VBO);

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
