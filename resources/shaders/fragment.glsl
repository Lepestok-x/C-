#version 330 core
precision mediump float;
in vec2 fragTexCoord;
uniform sampler2D texture0;
uniform vec4 u_color;
out vec4 fragColor;
void main() {
    vec4 color = texture(texture0, fragTexCoord);
    color.r = 1.0;
    fragColor = color * u_color;
}