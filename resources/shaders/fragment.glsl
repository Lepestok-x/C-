#version 330 core
uniform vec4 colDiffuse;
out vec4 fragColor;
void main() {
    fragColor = colDiffuse;
}