#version 330 core  //顶点着色器
out vec4 FragColor;
in vec4 vertexColor;
uniform vec4 ourColor;
void main()
{
   FragColor = ourColor;
   // FragColor = vertexColor;
}