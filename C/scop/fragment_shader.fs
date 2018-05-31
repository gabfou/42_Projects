#version 400
out vec4 frag_colour;
in vec3 pos;
in vec3 norm;
in vec2 text;
uniform sampler2D textmap;
uniform vec3 debug;
uniform float texte;

void main()
{
	vec3 tmp;

	vec3 lightpos = vec3(-1, 1, -3);
	vec3 norm2 = normalize(norm);
	vec3 lightDir = normalize(lightpos - pos);
	vec3 diff = max(max(dot(norm2, lightDir), 0.0), max(dot(-norm2, lightDir), 0.0)) * vec3(1, 1, 1);
	if (text == vec2(0, 0))
	{
		vec3 blending = abs(norm);
		blending = normalize(max(blending, 0.00001));
		blending /= blending.x + blending.y + blending.z;
		vec3 xaxis = texture( textmap, (pos.yz / 2 - 0.5) * -1).rgb;
		vec3 yaxis = texture( textmap, (pos.xz / 2 - 0.5) * -1).rgb;
		vec3 zaxis = texture( textmap, (pos.xy / 2 - 0.5) * -1).rgb;
		tmp = xaxis * blending.x + yaxis * blending.y + zaxis * blending.z;
		tmp = tmp;
	}
	else
		tmp = texture( textmap, text ).rgb;
	frag_colour = vec4(tmp * texte, 1.0) * (texte) + vec4(diff + 0.25, 1.0) * (1 - texte);
}