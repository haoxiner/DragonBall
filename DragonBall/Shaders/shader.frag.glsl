#version 330 core
uniform sampler2D image;
uniform sampler2D aimage;
in vec3 v_position;
in vec3 v_normal;
in vec2 v_texCoord;
out vec4 fragColor;
void main()
{
  vec3 n = normalize(v_normal);
  vec3 toCamera = normalize(vec3(-1,0.5,-1) - v_position);
  vec3 toLight = toCamera;
  float NDotL = max(0.0, dot(n, toLight));
  vec2 uv0;
  uv0.x = (1.0 + NDotL) * 0.5;
  uv0.y = 3 * 0.125 + 0.015625;
  vec2 uv1;
  uv1.x = (1.0 - dot(n, toCamera));
  uv1.y = 3 * 0.125 + 0.046875;
  vec3 c = texture(image, uv0).xyz + texture(image, uv1).xyz;
  vec4 a = texture(aimage, v_texCoord);
  float r = 1.0;
  if (a.w > 0.5) {
    c = a.xyz;
  }
  // vec2 uv2;
  // vec3 h = n + toLight;
  // uv2.x = max(0.0, dot(h, n));
  // uv2.y = 0 * 0.125 + 0.078125;
  // vec3 unknown = texture(image, uv2).xyz;
  fragColor = vec4(c, 1.0);
}