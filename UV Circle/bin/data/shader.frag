
uniform float time;
uniform vec2 mousePos;
uniform sampler2DRect rock;
uniform sampler2DRect circle;



void main(){
//gl_FragCoord

	vec3 iResolution = vec3(800.,800.,0.);

	vec2 uv = 1.5*(2.0*gl_FragCoord.xy - iResolution.xy) / iResolution.y;
    vec2 mouse = 1.5*(2.0*mousePos.xy - iResolution.xy) / iResolution.y;
	vec2 offset = vec2(cos(time/2.0)*mouse.x,sin(time/2.0)*mouse.y);


	vec3 light_color = vec3(0.9, 0.65, 0.5);
	float light = 0.1 / distance(normalize(uv), uv);
	
	if(length(uv) < 1.0){
		light *= 0.1 / distance(normalize(uv-offset), uv-offset);
	}

	gl_FragColor = vec4(light*light_color, 1.0);

}