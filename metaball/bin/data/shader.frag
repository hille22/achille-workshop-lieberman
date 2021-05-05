
uniform float time;
uniform vec2 mousePos;


const float rmin = 0.414213562373095; // sqrt(2) - 1
const float rmax = 5.0;

const float pi = 3.14159265358979;

float circles_mask(vec2 uv, float phase){
	float r = mix(rmin, rmax, phase);
	float l = length(mod(uv, 2.0)*4.0 - 1.0) - r;
	float fw = fwidth(l)*.5;
	
	return smoothstep(fw, -fw, l) + min(l/r*.005, 0.0);
}

void main(){
//gl_FragCoord

	vec3 iResolution = vec3(800.,800.,0.);
	vec2 uv = 1.5*(2.0*gl_FragCoord.xy - iResolution.xy) / iResolution.y;
	
	float t0 = time;
	float t = t0 +
		length(5.0*sin(t0*vec2(-0.5,  0.9) + 0.5*uv)) +
		length(5.0*sin(t0*vec2( 0.7, -0.7) + 0.5*uv));
	

	
	float phase2 = sin(t + pi)*2.5 + 0.5;
	float mask2 = circles_mask(uv + 0.5, phase2);
	
	vec4 color = vec4(1.0);
	
	color = mix(color, vec4(0.0, 0., .0, 0.), mask2);


	gl_FragColor = color;

}