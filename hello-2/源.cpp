#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

const char* vertexShaderSource = "#version 330 core\n"  //顶点着色器
"layout (location = 0) in vec3 aPos;\n"
"out vec4 vertexColor;"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"   vertexColor = vec4(0.5, 0.0, 0.0, 1.0);\n"
"}\0";

const char* vertexShaderSource2 = "#version 330 core\n"  //顶点着色器
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"out vec3 ourColor2;"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"   ourColor2 = aColor;\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"  //顶点着色器
"out vec4 FragColor;\n"
"uniform vec4 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = ourColor;\n"
"}\0";

const char* fragmentShaderSourceY = "#version 330 core\n"  //顶点着色器
"out vec4 FragColor;\n"
"in vec3 ourColor2;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(ourColor2, 1.0f);\n"
"}\0";
//
//int main()
//{
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//
//    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//
//    //顶点着色器
//    unsigned int vertexShader;
//    vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//    int  success;  //用于检验编译是否成功
//    char infoLog[512];
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    //片段着色器
//    unsigned int fragmentShader;
//    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//
//    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);//用于检验编译是否成功
//    if (!success)
//    {
//        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    //着色器程序对象(Shader Program Object)是多个着色器合并之后并最终链接完成的版本
//    unsigned int shaderProgram;
//    shaderProgram = glCreateProgram();
//    //链接
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//    //检错
//    glGetShaderiv(shaderProgram, GL_COMPILE_STATUS, &success);//用于检验编译是否成功
//    if (!success)
//    {
//        glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    //删除之前的着色器对象
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//
//    //顶点输入
//    float vertices[] = {
//        // first triangle
//        -0.9f, -0.5f, 0.0f,  // left 
//        -0.0f, -0.5f, 0.0f,  // right
//        -0.45f, 0.5f, 0.0f,  // top 
//        // second triangle
//         0.0f, -0.5f, 0.0f,  // left
//         0.9f, -0.5f, 0.0f,  // right
//         0.45f, 0.5f, 0.0f   // top 
//    };
//    //float vertices[] = {
//    //0.5f, 0.5f, 0.0f,   // 右上角
//    //0.5f, -0.5f, 0.0f,  // 右下角
//    //-0.5f, -0.5f, 0.0f, // 左下角
//    //-0.5f, 0.5f, 0.0f   // 左上角
//    //};
//
//    unsigned int indices[] = {
//        // 注意索引从0开始! 
//        // 此例的索引(0,1,2,3)就是顶点数组vertices的下标，
//        // 这样可以由下标代表顶点组合成矩形
//
//        0, 1, 3, // 第一个三角形
//        1, 2, 3  // 第二个三角形
//    };
//    unsigned int VBO, VAO, EBO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glGenBuffers(1, &EBO);
//    glBindVertexArray(VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//    //解析顶点数据
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//
//
//
//    while (!glfwWindowShouldClose(window))
//    {
//        processInput(window);
//
//        //glClearColor函数是一个状态设置函数，而glClear函数则是一个状态使用的函数，它使用了当前的状态来获取应该清除为的颜色。
//        //if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        //激活对象
//        glUseProgram(shaderProgram);
//        glBindVertexArray(VAO);
//        //添加更多顶点到数据中，使用glDrawArrays，尝试绘制两个彼此相连的三角形：参考解答
//        glDrawArrays(GL_TRIANGLES, 0, 6);
//        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    glDeleteProgram(shaderProgram);
//
//    glfwTerminate();
//    return 0;
//}

//创建相同的两个三角形，但对它们的数据使用不同的VAO和VBO
//int main()
//{
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//
//    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//
//    //顶点着色器
//    unsigned int vertexShader;
//    vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//    int  success;  //用于检验编译是否成功
//    char infoLog[512];
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    //片段着色器
//    unsigned int fragmentShader;
//    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//
//    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);//用于检验编译是否成功
//    if (!success)
//    {
//        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    //着色器程序对象(Shader Program Object)是多个着色器合并之后并最终链接完成的版本
//    unsigned int shaderProgram;
//    shaderProgram = glCreateProgram();
//    //链接
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//    //检错
//    glGetShaderiv(shaderProgram, GL_COMPILE_STATUS, &success);//用于检验编译是否成功
//    if (!success)
//    {
//        glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    //删除之前的着色器对象
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//
//    //顶点输入
//    float vertices1[] = {
//        // first triangle
//        -0.9f, -0.5f, 0.0f,  // left 
//        -0.0f, -0.5f, 0.0f,  // right
//        -0.45f, 0.5f, 0.0f,  // top 
//    };
//    float vertices2[] = {
//        // first triangle
//        -0.9f, -0.5f, 0.0f,  // left 
//        -0.0f, -0.5f, 0.0f,  // right
//        -0.45f, 0.5f, 0.0f,  // top 
//    };
//
//    unsigned int VBO[2], VAO[2];
//    glGenVertexArrays(2, VAO);
//    glGenBuffers(2, VBO);
//    //1
//    glBindVertexArray(VAO[0]);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
//    //解析顶点数据
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    //2
//    glBindVertexArray(VAO[1]);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//
//
//    while (!glfwWindowShouldClose(window))
//    {
//        processInput(window);
//
//        //glClearColor函数是一个状态设置函数，而glClear函数则是一个状态使用的函数，它使用了当前的状态来获取应该清除为的颜色。
//        //if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        //激活对象
//        glUseProgram(shaderProgram);
//        glBindVertexArray(VAO[0]);
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//
//        glBindVertexArray(VAO[1]);
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glDeleteVertexArrays(2, VAO);
//    glDeleteBuffers(2, VBO);
//    glDeleteProgram(shaderProgram);
//
//    glfwTerminate();
//    return 0;
//}



//创建相同的两个三角形，但对它们的数据使用不同的VAO和VBO
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


    //顶点着色器
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int  success;  //用于检验编译是否成功
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //顶点着色器
    unsigned int vertexShader2;
    vertexShader2 = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader2, 1, &vertexShaderSource2, NULL);
    glCompileShader(vertexShader2);
    glGetShaderiv(vertexShader2, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader2, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //片段着色器
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);//用于检验编译是否成功
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int fragmentShaderY;
    fragmentShaderY = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderY, 1, &fragmentShaderSourceY, NULL);
    glCompileShader(fragmentShaderY);

    glGetShaderiv(fragmentShaderY, GL_COMPILE_STATUS, &success);//用于检验编译是否成功
    if (!success)
    {
        glGetShaderInfoLog(fragmentShaderY, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //着色器程序对象(Shader Program Object)是多个着色器合并之后并最终链接完成的版本
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    //链接
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    //检错
    glGetShaderiv(shaderProgram, GL_COMPILE_STATUS, &success);//用于检验编译是否成功
    if (!success)
    {
        glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int shaderProgramY;
    shaderProgramY = glCreateProgram();
    //链接
    glAttachShader(shaderProgramY, vertexShader2);
    glAttachShader(shaderProgramY, fragmentShaderY);
    glLinkProgram(shaderProgramY);
    //检错
    glGetShaderiv(shaderProgramY, GL_COMPILE_STATUS, &success);//用于检验编译是否成功
    if (!success)
    {
        glGetShaderInfoLog(shaderProgramY, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //删除之前的着色器对象
    glDeleteShader(vertexShader);
    glDeleteShader(vertexShader2);
    glDeleteShader(fragmentShader);
    glDeleteShader(fragmentShaderY);

    //顶点输入
    float vertices1[] = {
        // first triangle
        -0.9f, -0.5f, 0.0f,  // left 
        -0.0f, -0.5f, 0.0f,  // right
        -0.45f, 0.5f, 0.0f,  // top 
    };
    float vertices2[] = {
        // first triangle
         0.0f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // left
         0.9f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // right
         0.45f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,   // top 
    };

    unsigned int VBO[2], VAO[2];
    glGenVertexArrays(2, VAO);
    glGenBuffers(2, VBO);
    //1
    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
    //解析顶点数据
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //2
    glBindVertexArray(VAO[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
    //位置属性
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //颜色属性
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);


    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        //glClearColor函数是一个状态设置函数，而glClear函数则是一个状态使用的函数，它使用了当前的状态来获取应该清除为的颜色。
        //if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //激活对象
        glUseProgram(shaderProgram);

        //更新uniform颜色
        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;
        float redValue = cos(timeValue) / 2.0f + 0.5f;
        int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
        glUniform4f(vertexColorLocation, redValue, greenValue, 0.0f, 1.0f);


        glBindVertexArray(VAO[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgramY);
        glBindVertexArray(VAO[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(2, VAO);
    glDeleteBuffers(2, VBO);
    glDeleteProgram(shaderProgram);
    glDeleteProgram(shaderProgramY);

    glfwTerminate();
    return 0;
}