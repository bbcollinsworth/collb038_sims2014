#version 120

uniform sampler2D heightMap;
uniform sampler2D normalMap;
uniform float time;

varying vec4 vert;
varying vec2 texCoord;
varying float maxHeight;


float rand(vec2 n) { 
    return fract(sin(dot(n, vec2(12.9898, 4.1414))) * 43758.5453);
}

float noise(vec2 p){
    vec2 ip = floor(p);
    vec2 u = fract(p);
    u = u*u*(3.0-2.0*u);

    float res = mix(
        mix(rand(ip),rand(ip+vec2(1.0,0.0)),u.x),
        mix(rand(ip+vec2(0.0,1.0)),rand(ip+vec2(1.0,1.0)),u.x),u.y);
    return res*res;
}

void main(){
	vec4 color = gl_Color;
	// color = texture2D(normalMap,texCoord);

	//vec3 lightPos = vec3(1000,1000,500);
	
	vec3 lightPos = vec3(1000*sin(time*0.1),1000*cos(time*0.1),500);

	vec3 normal = ((texture2D(normalMap,texCoord).rgb-0.5)*vert.z)/maxHeight;
	//*abs(sin(time*0.1)*1.0);//2.0;
	vec3 diff = normalize(lightPos - vert.xyz);

	float no = noise(vec2(vert.x*0.5,vert.y*0.5));
	
	//color.rgb = vec3((vert.z/maxHeight)*0.8,(vert.z/maxHeight)*0.6,(vert.z/maxHeight)*(vert.z/maxHeight))*0.6 + vec3(dot(diff,normal))*0.8
	+vec3(no*(maxHeight-vert.z),no*(maxHeight-vert.z),no*maxHeight)*0.0002;

	//THIS MAKES MOUNTAIN BLUE:
	color.rgb = vec3((vert.z/maxHeight)*(vert.z/maxHeight),(vert.z/maxHeight)*(vert.z/maxHeight),vert.z/maxHeight) + vec3(dot(diff,normal))*0.7;
	

	gl_FragColor = color;
}




