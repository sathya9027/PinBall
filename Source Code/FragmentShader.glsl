#version 330
in vec2 _pixcoords;
uniform sampler2D _pixcolor;
void main()
{
	gl_FragColor = texture(_pixcolor, _pixcoords);
}