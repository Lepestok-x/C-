#version 330
out vec4 finalColor;
uniform vec4 colDiffuse;
uniform float u_time;
void main() {
    vec4 drawDiffuse = colDiffuse;
    drawDiffuse *= ((sin(u_time) * 0.35) + 0.5);
    finalColor = vec4(drawDiffuse.rgb, 1.0);
}