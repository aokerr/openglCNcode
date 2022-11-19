#version 330 core  //顶点着色器
out vec4 FragColor;
in vec3 ourColor2;
void main()
{
   FragColor = vec4(ourColor2, 1.0f);
}