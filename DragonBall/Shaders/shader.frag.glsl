#version 330 core
uniform sampler2D image;
in vec3 v_position;
in vec3 v_normal;
in vec2 v_texCoord;
out vec4 fragColor;
void main()
{
  vec2 uv = v_texCoord;
  // fragColor = texture(image, uv * 100.0);
  // fragColor.w = 1.0;
  fragColor = vec4(pow(texture(image, uv).www, vec3(1.0/2.2)), 1.0);
}