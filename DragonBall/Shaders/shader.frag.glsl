#version 330 core
uniform sampler2D image;
uniform sampler2D aimage;
in vec3 v_position;
in vec3 v_normal;
in vec2 v_texCoord;
out vec4 fragColor;
void main()
{
  
  vec3 toCamera = vec3(-1,0.5,-1) - v_position;
  vec3 toLight = normalize(toCamera);
  float NDotL = max(0.0, dot(normalize(v_normal), toLight));
  vec2 uv0 = v_texCoord;
  uv0.x = (1.0 + NDotL) * 0.5;
  uv0.y = 1 * 0.125 + 0.015625;
  vec2 uv1 = v_texCoord;
  uv1.x = (1.0 - dot(normalize(v_normal), toLight));
  uv1.y = 1 * 0.125 + 0.046875;
  vec3 c = texture(image, uv0).xyz + texture(image, uv1).xyz;
  vec4 a = texture(aimage, v_texCoord);
  float r = 1.0;
  if (a.w > 0.5) {
    c = a.xyz;
  }
  fragColor = vec4(c.xyz, 1.0);
}