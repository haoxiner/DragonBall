#version 330 core
in vec3 v_position;
in vec3 v_normal;
in vec2 v_texCoord;
out vec4 fragColor;
void main()
{
  fragColor = vec4(pow(v_normal * 0.5 + vec3(0.5), vec3(1.0/2.2)), 1.0);
}