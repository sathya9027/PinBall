#version 330
in vec2 _vertices;
in vec2 _uvcoords;
out vec2 _pixcoords;
void main()
{
	vec4 _local = vec4(_vertices, 0, 1);
	gl_Position = _local;
	_pixcoords = _uvcoords;
}