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

const char* vertexShaderSource = "#version 330 core\n"  //������ɫ��
"layout (location = 0) in vec3 aPos;\n"
"out vec4 vertexColor;"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"   vertexColor = vec4(0.5, 0.0, 0.0, 1.0);\n"
"}\0";

const char* vertexShaderSource2 = "#version 330 core\n"  //������ɫ��
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"out vec3 ourColor2;"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"   ourColor2 = aColor;\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"  //������ɫ��
"out vec4 FragColor;\n"
"uniform vec4 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = ourColor;\n"
"}\0";

const char* fragmentShaderSourceY = "#version 330 core\n"  //������ɫ��
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
//    //������ɫ��
//    unsigned int vertexShader;
//    vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//    int  success;  //���ڼ�������Ƿ�ɹ�
//    char infoLog[512];
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    //Ƭ����ɫ��
//    unsigned int fragmentShader;
//    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//
//    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);//���ڼ�������Ƿ�ɹ�
//    if (!success)
//    {
//        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    //��ɫ���������(Shader Program Object)�Ƕ����ɫ���ϲ�֮������������ɵİ汾
//    unsigned int shaderProgram;
//    shaderProgram = glCreateProgram();
//    //����
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//    //���
//    glGetShaderiv(shaderProgram, GL_COMPILE_STATUS, &success);//���ڼ�������Ƿ�ɹ�
//    if (!success)
//    {
//        glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    //ɾ��֮ǰ����ɫ������
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//
//    //��������
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
//    //0.5f, 0.5f, 0.0f,   // ���Ͻ�
//    //0.5f, -0.5f, 0.0f,  // ���½�
//    //-0.5f, -0.5f, 0.0f, // ���½�
//    //-0.5f, 0.5f, 0.0f   // ���Ͻ�
//    //};
//
//    unsigned int indices[] = {
//        // ע��������0��ʼ! 
//        // ����������(0,1,2,3)���Ƕ�������vertices���±꣬
//        // �����������±��������ϳɾ���
//
//        0, 1, 3, // ��һ��������
//        1, 2, 3  // �ڶ���������
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
//    //������������
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
//        //glClearColor������һ��״̬���ú�������glClear��������һ��״̬ʹ�õĺ�������ʹ���˵�ǰ��״̬����ȡӦ�����Ϊ����ɫ��
//        //if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        //�������
//        glUseProgram(shaderProgram);
//        glBindVertexArray(VAO);
//        //��Ӹ��ඥ�㵽�����У�ʹ��glDrawArrays�����Ի��������˴������������Σ��ο����
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

//������ͬ�����������Σ��������ǵ�����ʹ�ò�ͬ��VAO��VBO
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
//    //������ɫ��
//    unsigned int vertexShader;
//    vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//    int  success;  //���ڼ�������Ƿ�ɹ�
//    char infoLog[512];
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    //Ƭ����ɫ��
//    unsigned int fragmentShader;
//    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//
//    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);//���ڼ�������Ƿ�ɹ�
//    if (!success)
//    {
//        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    //��ɫ���������(Shader Program Object)�Ƕ����ɫ���ϲ�֮������������ɵİ汾
//    unsigned int shaderProgram;
//    shaderProgram = glCreateProgram();
//    //����
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//    //���
//    glGetShaderiv(shaderProgram, GL_COMPILE_STATUS, &success);//���ڼ�������Ƿ�ɹ�
//    if (!success)
//    {
//        glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    //ɾ��֮ǰ����ɫ������
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//
//    //��������
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
//    //������������
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
//        //glClearColor������һ��״̬���ú�������glClear��������һ��״̬ʹ�õĺ�������ʹ���˵�ǰ��״̬����ȡӦ�����Ϊ����ɫ��
//        //if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        //�������
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



//������ͬ�����������Σ��������ǵ�����ʹ�ò�ͬ��VAO��VBO
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


    //������ɫ��
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int  success;  //���ڼ�������Ƿ�ɹ�
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //������ɫ��
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

    //Ƭ����ɫ��
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);//���ڼ�������Ƿ�ɹ�
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int fragmentShaderY;
    fragmentShaderY = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderY, 1, &fragmentShaderSourceY, NULL);
    glCompileShader(fragmentShaderY);

    glGetShaderiv(fragmentShaderY, GL_COMPILE_STATUS, &success);//���ڼ�������Ƿ�ɹ�
    if (!success)
    {
        glGetShaderInfoLog(fragmentShaderY, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //��ɫ���������(Shader Program Object)�Ƕ����ɫ���ϲ�֮������������ɵİ汾
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    //����
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    //���
    glGetShaderiv(shaderProgram, GL_COMPILE_STATUS, &success);//���ڼ�������Ƿ�ɹ�
    if (!success)
    {
        glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int shaderProgramY;
    shaderProgramY = glCreateProgram();
    //����
    glAttachShader(shaderProgramY, vertexShader2);
    glAttachShader(shaderProgramY, fragmentShaderY);
    glLinkProgram(shaderProgramY);
    //���
    glGetShaderiv(shaderProgramY, GL_COMPILE_STATUS, &success);//���ڼ�������Ƿ�ɹ�
    if (!success)
    {
        glGetShaderInfoLog(shaderProgramY, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //ɾ��֮ǰ����ɫ������
    glDeleteShader(vertexShader);
    glDeleteShader(vertexShader2);
    glDeleteShader(fragmentShader);
    glDeleteShader(fragmentShaderY);

    //��������
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
    //������������
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //2
    glBindVertexArray(VAO[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
    //λ������
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //��ɫ����
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);


    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        //glClearColor������һ��״̬���ú�������glClear��������һ��״̬ʹ�õĺ�������ʹ���˵�ǰ��״̬����ȡӦ�����Ϊ����ɫ��
        //if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //�������
        glUseProgram(shaderProgram);

        //����uniform��ɫ
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