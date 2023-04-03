__kernel void pentagon_area(__global float* input, __global float* area, __global float* inradius, __global float* circumradius, __global float* perimeter, __global float* interior, __global float* exterior,int sides)
{
	int i=get_global_id(0);
	area[i]=((sides*input[i]*input[i])/(4.0f*tan(M_PI/sides)));
	perimeter[i]=(sides*input[i]);
	interior[i]=((sides-2)*(180.0f/sides));
	exterior[i]=(360.0f/sides);
	circumradius[i]=((input[i]/2.0f)/sin(M_PI/sides));
	inradius[i]=((2.0f*area[i])/(perimeter[i]));
}
