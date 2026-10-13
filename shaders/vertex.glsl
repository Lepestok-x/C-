#version 330
in vec3 vertexPosition;
uniform mat4 mvp;
uniform float u_time;
void main() {
    vec3 position = vertexPosition;
    position.x += ((sin(u_time + 3.0 + position.y * 1.05) * 0.5) + 0.5);
    gl_Position = mvp * vec4(position, 1.0);
}