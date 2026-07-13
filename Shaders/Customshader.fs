#version 330

// Input from vertex shader (normalized screen/texture coordinates from 0.0 to 1.0)
in vec2 fragTexCoord;

// Output color for this specific pixel position
out vec4 finalColor;

void main() {
    // Example: Color pixels based on their X/Y position
    finalColor = vec4(fragTexCoord.x, fragTexCoord.y, 0.0, 1.0);
    }