#version 330 core
uniform sampler2D image;
uniform sampler2D aimage;
in vec3 v_position;
in vec3 v_normal;
in vec2 v_texCoord;
out vec4 fragColor;
void main()
{
  vec2 uv = v_texCoord;
  vec3 toCamera = vec3(-1,0.5,-1) - v_position;
  vec3 toLight = normalize(toCamera);
  float b = (dot(normalize(v_normal), toLight));
  uv.s = b;
  uv.t = 17.5 / 127;
  vec4 c = texture(image, uv);
  // fragColor = vec4(pow(vec3(1.0 - texture(image, uv).w), vec3(1.0/2.2)), 1.0);
  vec4 a = texture(aimage, v_texCoord);
  float r = 1.0;
  if (a.w > 0.4) {
    r = 0.0;
  }
  fragColor = vec4(c.xyz * r, 1.0);
}