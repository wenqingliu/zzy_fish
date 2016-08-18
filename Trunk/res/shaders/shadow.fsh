varying vec2 v_texCoord;

vec4 composite(vec4 over, vec4 under)
{
	return over + (1.0 - over.a)*under;
}
void main(){
	//vec2 shadowOffset = vec2(0.01, 0.01);
	//vec4 textureColor = texture2D(CC_Texture0, v_texCoord);
	float shadowMask = texture2D(CC_Texture0, v_texCoord  ).a;
	const float shadowOpacity = 0.4;  
	vec4 shadowColor = vec4(0,0,0,shadowMask *shadowOpacity);
	gl_FragColor = shadowColor;//composite(textureColor, shadowColor);
}
