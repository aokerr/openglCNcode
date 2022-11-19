#version 330 core  //顶点着色器
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
uniform float tx;
out vec3 ourColor2;
void main()
{
   gl_Position = vec4(aPos.x + tx, aPos.y, aPos.z, 1.0);
   ourColor2 = aColor;
}