#version 120

uniform sampler2D heightMap;
uniform sampler2D normalMap;
uniform float time;
uniform float random;


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
	maxHeight = 300.0;
	//float height = maxHeight;
	//float height = abs(sin(time*0.05)*maxHeight); // Max altitud
	float height = abs(sin(time*0.01+sin(time*0.04))*maxHeight); // Max altitud

	texCoord = gl_MultiTexCoord0.xy;
	//float height = montecarlo(texCoord.xy)*maxHeight;

	

	vec2 center = normalize(vec2(640,360));
	vec2 coordNorm = center-texCoord;

	vert = gl_Vertex;
	float no = noise(vert.xy*2)*4;
	float offset = texture2D(heightMap,texCoord).r;
	 vert.z = height*(offset)+no;
	 //vert.x = vert.x+offset*offset*offset*400*coordNorm.x;
	 //vert.y = vert.y+offset*offset*offset*400*coordNorm.y;
	 vert.x = vert.x+offset*offset*100*cos(time+cos(time*0.3)*60);
	 vert.y = vert.y+offset*100*sin(time+sin(time*0.3)*60);
	//vert.z = pow(offset*100.,0.2)*height;
	//vert.x = pow(offset*10.,0.2)*height;
	//vert.y = pow(offset*10.,0.2)*height;
	//vert.xy = pow(offset*100.,0.2)//;*height;

	

	gl_Position = gl_ModelViewProjectionMatrix * vert;
	gl_FrontColor = gl_Color;
}
