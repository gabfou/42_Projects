#version 400
layout(location = 0) in vec3 vp;
layout(location = 1) in vec2 vt;
layout(location = 2) in vec3 vn;
uniform float time;
uniform vec3 posmodif;
out vec3 pos;
out vec3 norm;
out vec2 text;


mat4 rotationMatrix(vec3 axis, float angle)
{
	axis = normalize(axis);
	float s = sin(angle);
	float c = cos(angle);
	float oc = 1.0 - c;
	
	return mat4(oc * axis.x * axis.x + c,          oc * axis.x * axis.y - axis.z * s, oc * axis.z * axis.x + axis.y * s, 0.0,
				oc * axis.x * axis.y + axis.z * s, oc * axis.y * axis.y + c,          oc * axis.y * axis.z - axis.x * s, 0.0,
				oc * axis.z * axis.x - axis.y * s, oc * axis.y * axis.z + axis.x * s, oc * axis.z * axis.z + c,          0.0,
				0.0,                               0.0,                               0.0,                               1.0);
}

void main()
{
	mat4 pm = mat4(	1, 0, 0, 0, 
					0, 1, 0, 0,
					0, 0, 0, 0,
					0, 0, 1, 0);
	gl_Position = rotationMatrix(vec3(0, 1, 0), time) * (vec4(vp, 1.0)) + vec4(posmodif, 0) * pm;
	pos = vp;
	norm = vn;
	text = vt;
}